#include<bits/stdc++.h>
using namespace std;

class Node {
    public :
    int val;
    int sizePower; 
    // 0 : means even
    // 1 means odd : size of node is a even power or odd power

    Node(){
        val = 0;
        sizePower = 0;
    }

    Node (int p){
        val = p;
        sizePower = 0; // 2^0 power of 2 is even
    }

    void merge(Node &a, Node&b){

        if( a.sizePower == 0){
            // even power of 2
            val = a.val | b.val;
            sizePower = 1;
        }
        else {
            val = a.val ^ b.val;
            sizePower = 0;
        }
    }
};

class Update{

    public : 
    int val;
    Update(int p){
        val = p;
    }
    void apply(Node & leafNode){
        leafNode.val = val; 
    }
};

template<typename Node, typename Update>
class SegmentTree {

    int n;
    vector<int> arr;
    int s;
    vector<Node> tree;

    void buildTree(int idx, int nodeLeft, int nodeRight){
        
        if( nodeLeft == nodeRight){
            tree[idx] = Node(arr[nodeLeft]);
            return;
        }
        int mid = (nodeLeft + nodeRight)/ 2;

        buildTree(2*idx, nodeLeft, mid);
        buildTree(2*idx+1, mid+1, nodeRight);

        tree[idx].merge(tree[2*idx], tree[2*idx+1]);
    }

    void updateHelper(int idx, int nodeLeft, int nodeRight, int update_idx, Update &u){

        if( update_idx == nodeLeft && nodeLeft == nodeRight){
            u.apply(tree[idx]);
            return;
        }

        if( update_idx < nodeLeft || update_idx > nodeRight) return;

        int mid = (nodeLeft + nodeRight)/ 2;

        updateHelper(2*idx, nodeLeft, mid, update_idx, u);
        updateHelper(2*idx+1, mid+1, nodeRight, update_idx, u);
        tree[idx].merge(tree[2*idx], tree[2*idx+1]);
    }

    public : 

    int getFinalValue(){
        return tree[1].val;
    }
    SegmentTree(int n, vector<int> a){
        this->n = n;
        arr = a;
        s = 1;

        while( s < n){
            s = s << 1;
            // 2^k > n : nearest power of 2^k > n
        }
        s = s << 1;
        tree.assign(s, Node());
        buildTree(1, 0, n -1);
    }

    void updateArray(int update_idx, int newVal){
        Update u(newVal);
        updateHelper(1, 0, n-1, update_idx, u);
    }
};

int main(){


    // final ans : tree[1];
    int n, m;
    cin >> n >> m;

    vector<int> arr(1 << n);
    for(int i = 0; i < (1 << n) ; i++){
        cin >> arr[i];
    }
    SegmentTree<Node, Update> sg(1 << n, arr);

    for(int i = 0; i < m; i ++){

        int idx,val;
        cin >> idx >> val;
        sg.updateArray(idx-1, val);
        cout << sg.getFinalValue() << "\n";
    }
    return 0;
}