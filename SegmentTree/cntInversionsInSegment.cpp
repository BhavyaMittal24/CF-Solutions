#include<bits/stdc++.h>
using namespace std;

// defines the type of data stored in a node
class Node{
    public : 
    long long ic;
    vector<int> freqCount;

    Node(){
        ic = 0;
        freqCount.assign(41,0);
    }

    Node(int val){
        ic = 0;
        freqCount.assign(41,0);
        freqCount[val]++;
    }

    void merge(Node &left, Node & right){
        ic = left.ic + right.ic;
        //  1 <= ai <= 40
        long long cntLessThan = 0;
        
        for(int i = 1; i <= 40; i ++){

            freqCount[i] = left.freqCount[i] + right.freqCount[i];
            if( i == 1) continue;
            // cnt all elements < i in the right half
            cntLessThan += right.freqCount[i-1];
            ic += 1ll* left.freqCount[i] * cntLessThan;
        }
    }
};

class Update {

    int val1;
    int val2;
    public : 
    Update(int oldVal, int newVal){
        val1 = oldVal;
        val2 = newVal;
    }

    void apply(Node & leafNode){

        leafNode.freqCount[val1] = 0;
        leafNode.freqCount[val2] = 1;
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

    long long  rangeQueryAnswer(int left, int right){

        Node ans = rangeQuery(1, 0 , n-1, left, right);
        return ans.ic;
    }

    // create an update object whcih will apply the update with value to the leaf tree[idx] node
    void updateQuery(int update_idx, int val){
        Update u = Update( arr[update_idx], val);
        updateIdx(1, 0 , n-1, update_idx, u);
        arr[update_idx] = val;
    }

};

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree<Node, Update> sg (n, arr);

    for(int i = 0; i < q; i ++){
        int a, b, c;
        cin >> a >> b >> c;

        if( a == 2){
            sg.updateQuery(b-1, c);
        }
        else {
            // 0 based indexing for array
            long long ans = sg.rangeQueryAnswer(b-1, c-1);
            cout << ans << "\n";
        }
    }

    return 0;
}