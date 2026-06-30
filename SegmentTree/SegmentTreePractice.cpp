#include<bits/stdc++.h>
using namespace std;

// each node stores the result(sum,max,min) for a given range in the array 
// array is 0 based index
void buildTree(int node_idx, int node_left, int node_right, vector<int> & arr, vector<int> & sgmt){

    if( node_left == node_right){
        sgmt[node_idx] = arr[node_left];
        return;
    }

    int leftChild = 2* node_idx;
    int rightChild = 2* node_idx + 1;

    int mid = ( node_left + node_right )/2;
    buildTree(leftChild, node_idx, mid,arr, sgmt);
    buildTree(rightChild, mid+1, node_right, arr, sgmt);

    sgmt[node_idx] = sgmt[leftChild] + sgmt[rightChild];
    return;
}

void update_idx (int node_idx, int leftNode, int rightNode, int idx, int val, vector<int> & arr, vector<int> & sgmt){
    // recalculate the  entire sgmt array
    // check based on the interesetion for the idx

    if( idx < leftNode || idx > rightNode){
        return;
    }

    if( leftNode == rightNode && leftNode == idx){
        sgmt[node_idx] = val;
        // arr[idx] = val;
        return;
    }

    // interesection in between
    int mid = (leftNode + rightNode)/2;
    update_idx(2*node_idx, leftNode, mid, idx, val, arr, sgmt);
    update_idx(2*node_idx+1, mid+1, rightNode, idx, val, arr, sgmt);

    sgmt[node_idx] = sgmt[2*node_idx] + sgmt[2*node_idx + 1];
}

// for each sgmt tree node, node_idx : index of sgmt tree and range leftIdx, rightIdx for whcih the sum is storeed from [l,r]

int rangeQuery(int node_idx, int leftNode, int rightNode, int queryLeft, int queryRight, vector<int> & arr, vector<int> & sgmt){

    // full overlap of the node range inside the query range
    if( queryLeft <= leftNode && rightNode <= queryRight){
        return sgmt[node_idx];
    }

    // no interesction
    if( leftNode > queryRight || rightNode < queryLeft){
        return 0;
    }

    // other case : partial overlap

    int mid = (leftNode + rightNode)/2;

    int leftHalf = rangeQuery(2*node_idx, leftNode, mid, queryLeft, queryRight, arr, sgmt);
    int rightHalf = rangeQuery(2*node_idx + 1, leftNode, rightNode, queryLeft, queryRight, arr, sgmt);

    return leftHalf + rightHalf;
}

int main(){


    int n;
    cin >> n;
    vector<int> arr(n,0);

    for(int i = 0; i < n; i ++) cin >> arr[i];

    // n nodes
    // find the range query sum for a given range [L,R] 
    // update_idx[i] 
    // these two are interleaved : q * n brute force : at each update : i can find the prefix array again
    // we want it to be : q * logn : logn for update and logn for query
    // q * n : updatr -> 0(n) recompute the prefix array and query -> 0(1) using the prefix array
    // q * logn

    // total nodes : 2n - 1 : when n = 2^k
    // n nodes in the last layer : each node storign an answer 
    // 1 [0,n-1]
    // 2 nodes : 
    // 4 nodes
    // ..
    // n nodes n + n-1 nodes : k = log2n : 2^log22^n -1 : 2^ k +1 - 1 = 2n -1
    
    // n is not a power of 2 : total nodes = 2^k : first power of 2^k > n 
    // 2*n > 2^k where 2^k is >= n
    //  2^k-1 < n < 2^k
    // 2(2n) - 1 : 4n -1  < 4n
    // 1 base dindexing for a sgmt tree
    vector<int> sgmt(4*n, 0);

    // sgmt storing value for all 2n -1 nodes for each rabge
    // 1, l, r
    // node_idx, left, right : different indexes :
    // binary tree : parnet : i , leftchild : 2*i, rightCHild = 2*i + 1

    //buildTree(1,0,n-1,arr, sgmt);

    for(int i = 0; i < n; i ++){
        update_idx(1, 0, n-1, i, arr[i], arr, sgmt);
    }

    // build the tree

    // perform q queries

    int q;
    cin >> q;

    for(int i = 0; i < q; i ++){
        int a;
        cin >> a;
        int x, y;
        cin >> x >> y;
        // l,r
        // idx, val
        if( a == 1){
            
            // x, y
            int ans = rangeQuery(1, 0, n-1, x, y, arr, sgmt);
            cout << "output for range"  << ans << endl;
        }
        else {
            // at idx x put val y
            update_idx(1, 0, n-1, x, y, arr, sgmt);
        }
    }
    return 0;
}