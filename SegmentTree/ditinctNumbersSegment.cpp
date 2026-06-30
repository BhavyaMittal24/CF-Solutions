#include<bits/stdc++.h>
using namespace std;

class Node {

    public :
    long long setNumbers;
    int cnt;

    Node(){
        // mask for storign if the ith bit is set -> i number is part of that range or not
        setNumbers = 0;
        cnt = 0;
    }
    // actual value stored in the sgmt tree node for a leaf node
    Node(int val){
        cnt = 1;
        setNumbers = (1LL << val);
        // val is set in the setNumbers
    }

    void merge(Node &left, Node & right){
        setNumbers = left.setNumbers | right.setNumbers;
        // when in update, i merge the left child and right child, or during the build tree
        cnt = 0;
        for(int i = 1; i <= 40; i ++){
            if( ( setNumbers & (1LL << i)) != 0 ){
                cnt++;
            } 
        }
    }
    
};

class Update{

    int oldVal;
    int newVal;

    public : 
    Update(int val1, int val2){
        oldVal = val1;
        newVal = val2;
    }

    void apply(Node & node){

        node.setNumbers = 0;
        // 10011 ^ 10000
        node.setNumbers =  1LL << newVal;
    }
};


template<typename Node, typename Update> 

class SegmentTree{

    int n;
    int s;
    vector<int> arr;
    vector<Node> tree;

    // remains same throughout
    void buildTree(int idx, int nodeLeft, int nodeRight){

        if( nodeLeft == nodeRight){
            tree[idx] = Node(arr[nodeLeft]);
            return;
        }

        int mid = (nodeLeft + nodeRight)/2;
        buildTree(2*idx, nodeLeft, mid);
        buildTree(2*idx + 1, mid+ 1, nodeRight);
        tree[idx].merge(tree[2*idx], tree[2*idx + 1]);
    }

    void update_index(int idx, int leftNode, int rightNode, int update_idx, Update &u){

        // reached leadnode storign result for only a single element of the array
        if( leftNode == rightNode && update_idx == leftNode){
            u.apply(tree[idx]);
            // idx for the leafnode
            return;
        }

        if(update_idx < leftNode || update_idx > rightNode) return;

        int mid = (leftNode + rightNode)/ 2;
        // can brach out
        update_index(2*idx, leftNode,mid, update_idx, u);
        update_index(2*idx +1, mid+1, rightNode, update_idx, u);

        tree[idx].merge(tree[2*idx], tree[2*idx+1]);
    }

    Node rangeQuery(int idx, int nodeLeft, int nodeRight, int queryLeft, int queryRight){

        if( queryLeft <= nodeLeft && nodeRight <= queryRight){
            return tree[idx];
        }

        if(nodeLeft > queryRight || nodeRight < queryLeft){
            return Node();
            // default constructir value for the empty node when there is no interecation with any query range
        }

        int mid = (nodeLeft + nodeRight)/2;
        Node leftContribution = rangeQuery(2*idx, nodeLeft, mid, queryLeft, queryRight);
        Node rightContribution = rangeQuery(2*idx+1, mid+1, nodeRight, queryLeft, queryRight);
        Node ans;
        ans.merge(leftContribution, rightContribution);
        return ans;
    
    }

    public : 

    SegmentTree(int n, vector<int> a){
        this-> n = n;
        arr = a;

        s = 1;
        // 2^k >= n
        while ( s < n){
            s = s << 1;
        }
        s = s << 1;
        // 2*n -1 size
        tree.assign(s, Node());
        buildTree(1, 0, n-1);
    }
    
    // all the array indexed are 0 based
    void update(int update_idx, int new_val){
        // array of the sgmt tree we can update this
        Update u(arr[update_idx], new_val);
        // goes on to apply the change to leaf node and then updae all parents in path from leaf to root
        update_index(1, 0, n-1, update_idx, u);
        arr[update_idx] = new_val;
    }

    int distinctQuery(int queryLeft, int queryRight){
        Node ans = rangeQuery(1, 0, n-1, queryLeft, queryRight);
        int val = ans.cnt;
        return val;
    }
};

int main(){

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);

    for(int i = 0; i < n; i ++) cin >> arr[i];

    SegmentTree<Node, Update> sg (n, arr);

    for(int i = 0;i  < q; i ++){
        int a, b,c;
        cin >> a >> b >> c;

        if( a == 1){
            int ans = sg.distinctQuery(b-1, c-1);
            cout << ans << "\n";
        }
        else {
            sg.update(b-1, c);
        }
    }
    return 0;
}