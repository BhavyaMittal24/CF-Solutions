#include<bits/stdc++.h>
using namespace std;

// Node class 
class Node{

    public : 
    // value which is stored for a given range in a sgmt tree node
    int val;

    // defaut value for the segmt tree node when it is intialised
    Node(){
        val = 0;
    }

    // Assign a value to the leaf node when building the tree using Parametrised constructor
    Node(int p1){
        val = p1;
    }

    // When we perform a query, to return the result from left or right part we merge the left child and right child contributions
    // When building a tree, we use this to store the value in a parent from the two child segment tree nodes
    void merge(Node &a, Node &b){
        val = a.val + b.val;
    }
};  

class Update{

    public:
    // val with which you will update the tree node value
    int val;

    // val with which you want to update a given leaf node
    // You can take in multiple parameters, and get one value with which you will update the leaf node

    // form the value for update : eg a[update_idx] ^ x = p1
    Update(int p1){
        val = p1;
    }

    // apply the update to the tree node using the object of class Update
    void apply(Node & node){
        node.val = val;
    }
};



// Create two classes for Node and Upodate
// Node : class for the value present in the segment tree, Value formed from contribution for left and right child
// Update : class used to Update the leaf node : changing the value for the leaf node using Update object using apply ()

template<typename Node, typename Update>
class SegmentTree{

    public :
    vector<long long> arr;
    // size of the segment tree 
    int s;
    int n;
    // tree containing the node at each index
    vector<Node> tree;

    void buildTree(int node_idx, int start, int end){

        if( start == end){
            // use parametrised constructor to assing the value to the object Node 
            tree[node_idx] = Node(arr[start]);
            return;
        }

        int mid = (start + end) / 2;
        buildTree(2*node_idx, start, mid);
        buildTree(2*node_idx +1 , mid+1, end);

        // updating the value for the node_idx to it's children using the merge function
        tree[node_idx].merge(tree[2*node_idx], tree[2*node_idx + 1]);
    }


    SegmentTree(int n, vector<long long> & a){

        // n size of the array of elements
        // a is the original array

        s = 1;
        arr = a;
        this->n = n;
        // size of the segment tree should be  2. 2*k - 1 where 2^k is the nearest power of 2

        while( s < n){
            s = s << 1;
        }

        // s = 2^k

        s = s << 1;
        tree.resize(s);

        // assigning the value Node() for all the indices in the tree to initialise them
        fill(tree.begin(), tree.end(), Node());

        // build the segment tree
        buildTree(1, 0, n-1);
    }

    Node queryRangeHelper(int node_idx, int start, int end, int L, int R){

        if(  L <= start && end <= R ){
            return tree[node_idx];
        }

        if( start > R || end < L) {
            // default value
            return Node();
        }

        int mid = (start + end) / 2;

        Node leftContribution = queryRangeHelper(2*node_idx, start, mid, L, R);
        Node rightContribution = queryRangeHelper(2*node_idx +1, mid+1, end, L, R);

        // get the contribution of left and right
        Node ans = Node();
        ans.merge(leftContribution, rightContribution);

        return ans;
    }
    
    int rangeQuery(int L, int R){

        Node ans = Node();
        ans = queryRangeHelper(1, 0, n-1, L, R);

        // val from the ans node : ans object of class Node and returnign its property
        return ans.val;
    }

    void update_index_value(int node_idx, int start, int end, Update & u, int update_idx){

        if( start == end && update_idx == start){
            // get the tree node leaf to this value using Update object
            // You can even do something like : 
            // tree[node_idx] = Node(arr[update_idx])
            u.apply(tree[node_idx]);
            return;
        }

        int mid = (start + end) / 2;

        if( start > update_idx || update_idx > end) return;

        update_index_value(2*node_idx, start, mid, u, update_idx);
        update_index_value(2*node_idx + 1, mid+1, end, u, update_idx);

        tree[node_idx].merge(tree[2*node_idx] ,tree[2*node_idx + 1]);
    }

    void updateIndex(int update_idx, int val){
        
        // val to update to the leaft index
        // replace this value to the treenode
        Update u = Update(val);
        update_index_value(1, 0, n-1, u, update_idx);
    }

};


int main(){

    int n;
    cin >> n;

    vector<long long> arr(n);

    for(int i = 0 ; i < n; i++) cin >> arr[i];

    // array size and the total array
    SegmentTree<Node, Update> sg = SegmentTree<Node, Update>(n, arr);

    // 1 : update i to x  : 1 i x 
    // 2 : give answer as sum from index L to R : 2 L R
    int q;
    cin >> q;

    while(q--){
        int type, u , v;
        cin >> type >> u >> v;

        if( type == 1){
            sg.updateIndex(u, v);
        }
        else {
            long long ans = sg.rangeQuery(u,v);
            cout << "Answer for [" << u << " : " << v << "] is "  <<   ans << endl;
        }
    }

    return 0;
}