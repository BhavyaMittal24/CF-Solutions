#include<bits/stdc++.h>
using namespace std;

// XOR fpr a given range : 
// 1node -> 0 to n-1 ; XOR

// Segment tree node -> 
// defines the type of data stored in a node of segment tree 
class Node {
    public : 
    int val;

    Node(){
        val = 0;
        // default value for a sgmt node : for a given range in the array
    }
    Node(int p){
        val = p;
    }
    // combine the anseer from left and right halves/ child nodes
    void merge(Node &left, Node & right){
        val = (left.val) ^ (right.val);
    }
};

// Update class which is used to perform update operation on a given index with some value
// idx -> val : 
// Update object has the value which we need to update the required array index range
// we use this updat eobject then and apply update on the sgmt leaf node
class Update {

    public : 

    int updateVal;
    Update(int p){
        updateVal = p;
    }
    // apply to the leaf node : index of the array
    void apply( Node & node){
        node.val = updateVal;
    }
};


template<typename Node, typename Update>

// Sgmt is a DS whcih is actually a binary tree cintaining 2(2^k) - 1 nodes where each node stores the
// result for some operation for a given range in the array (0 indexed)
class SegmentTree{

    // private datamembers
    vector<Node> tree;
    vector<int> arr;
    int s;
    int n;

    void updateIdx(int idx, int leftArrIdx, int rightArrIdx, int update_index, Update & update){

        if( leftArrIdx == rightArrIdx && update_index == leftArrIdx){
            // update object used to store data in a given tree leaf node
            update.apply(tree[idx]);
            return;
        }

        if( update_index < leftArrIdx || update_index > rightArrIdx){
            return;
        }

        int mid = (leftArrIdx + rightArrIdx) / 2;
        updateIdx(2*idx, leftArrIdx, mid, update_index, update);
        updateIdx(2*idx+1, mid+1, rightArrIdx, update_index, update);

        tree[idx].merge(tree[2*idx], tree[2*idx+1]);
    }

     void buildTree(int idx, int leftArrIdx, int rightArrIdx){

        // for leftArrIdx, and rightArrayIdx : 
        if(  leftArrIdx == rightArrIdx){
            tree[idx] = Node(arr[leftArrIdx]);
            return;
        }

        int mid = (leftArrIdx + rightArrIdx)/2;
        buildTree(2*idx, leftArrIdx, mid);
        buildTree(2*idx + 1, mid+1, rightArrIdx);

        tree[idx].merge(tree[2*idx], tree[2*idx +1] );
    }

    Node rangeQuery(int idx, int leftArrIdx, int rightArrIdx, int left, int right){

        // node range comes inside query rang3
        if( left <= leftArrIdx && rightArrIdx <= right){
            return tree[idx];
        }

        if( left > rightArrIdx || right < leftArrIdx){
            return Node();
            // when no interesectio : rdefault value
        }

        int mid = (leftArrIdx + rightArrIdx)/ 2;
        Node leftHalf = rangeQuery(2*idx, leftArrIdx, mid, left, right);
        Node rightHalf = rangeQuery(2*idx +1, mid+1, rightArrIdx, left, right);

        // thisi intialiases the boect
        Node ans = Node();
        ans.merge(leftHalf, rightHalf);
        return ans;
    }

    public : 

    SegmentTree(int n , vector<int> a){
        s = 1;
        this-> n = n;
        arr = a;
        
        // s < n : s > n ~ nearest 2^k > n : 2* 2^k
        while( s < 2*n){
            s = s << 1;
        }

        tree.assign(s,Node());
        //fill(tree.begin(), tree.end(), Node());

        buildTree(1, 0, n-1);
    }

    int rangeQueryAnswer(int left, int right){

        Node ans = rangeQuery(1, 0 , n-1, left, right);
        return ans.val;
    }

    // create an update object whcih will apply the update with value to the leaf tree[idx] node
    void updateQuery(int update_idx, int val){
        Update u = Update(val);
        updateIdx(1, 0 , n-1, update_idx, u);
    }

};


int main(){

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    SegmentTree<Node, Update> sg(n, arr);

    int q;
    cin >> q;

    for(int i = 0; i < q; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        if( a == 1){

            int val = sg.rangeQueryAnswer(b,c);
            cout << val << endl;
        }
        else {
            sg.updateQuery(b, c);
        }
    }
    return 0;
}