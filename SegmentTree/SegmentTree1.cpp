// an array of size n (0 based index) and we want to answer two types of queries which are interleafed :
// 1. update a given index : 0 to n-1 to value x - val[idx] = x
// 2. For a given range L - R, find the sum of the values in the array L,R,X 

// Answer both of these queries in <- 0( n^2)
// N, q <= 1e5

// each node storing the sum for a given segment : (0-n-1) 
// Total 2*n - 1 nodes when N is the power of 2 for an array of size N. Segment tree nodes are 1 based indexed


#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int arr[N];
int sumRange[4*N];

// complete binary tree : ith node -> 2*i left child and 2*i + 1 right child

// each node in a segment tree is uniquely identified by it's node index and it's ranges start and end in the array
// node 1 : 0 and n-1 indices in the arr

int leftChild(int idx){
    return 2*idx;
}

int rightChild(int idx){
    return 2*idx + 1;
}



// 1 -> 0,n-1 : 2 : 0, mid : 3-> mid+1, ei
void buildSegmentTree( int idx, int si, int ei){

    // base case : tree of size 2N-1 nodes
    if(si == ei) {
        sumRange[idx] = arr[si];
        return;
    }

    int mid = (si + ei) / 2;

    // leftChild = 2(idx) : 1 based indexing 
    buildSegmentTree( leftChild(idx), si, mid);

    buildSegmentTree( rightChild(idx), mid + 1 , ei);

    sumRange[idx] = sumRange[leftChild(idx)] + sumRange[rightChild(idx)];
}

// Update arr[index] to val 
// the index between 0 to n-1
// idx is between 1 to 4N-1

// idx is the segment tree node index , and index is the index 0 bbased in the array
void update_idx(int idx, int si, int ei, int index, int val){

    if(si == ei && si == index){
        // We may or may not update the values in the original array : This may or may not be done 
        //arr[index] = val;
        sumRange[idx] = val;
        return;
    }

    // the index of the arrya is not the given range for the sgmt tree node idx
    if( index < si || index > ei){
        return;        
    }
    
    // si <= index <= ei index of the array

    int mid = (si + ei) /2;
    update_idx(leftChild(idx), si, mid, index, val );
    update_idx(rightChild(idx), mid +1 ,ei, index, val);

    // This updates the value for all the nodes in the path from the root to the leaf node\
    // 0,n-1 to ... (update_index, update_index)
    // In whichever ranges the update_index is present, the sgmt[nodei]  needs to be updated
    sumRange[idx] = sumRange[leftChild(idx)] + sumRange[rightChild(idx)];
}

// idx : sgmt tree node 
// si, ei, sgme tree node ranges 
// L, R is tthe query range
long long rangeQuery(int idx, int si, int ei, int L, int R){

    // when the sgmt tree range does not contribute at all to the query

    if( si > R || ei < L) return 0;

    // when the segment tree range contrbiutes fully to the query range

    if( si >= L && ei <= R) {
        return sumRange[idx];
    }

    int mid = (si + ei) / 2;

    // since there is a partial overlap between the segment tree range and the query : L,R
    long long leftChildSegmentContribution = rangeQuery( leftChild(idx), si, mid, L, R);

    long long rightChildSegmentContribution = rangeQuery(rightChild(idx), mid + 1, ei, L, R);

    return leftChildSegmentContribution + rightChildSegmentContribution;
}


int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }


    buildSegmentTree(1, 0, n-1);
    int q;
    cin >> q;
    vector<vector<int>> query(q);
    for(int i = 0;i < q; i++){
        int a, b, c;
        cin >> a >> b >> c;

        query[i] = {a, b, c};
    }

    for(int i = 0; i < q; i ++){

        int queryType = query[i][0];

        if(queryType == 1){

            int index = query[i][1];
            int val = query[i][2];
            update_idx(1, 0, n-1, index, val);
        }
        else {

            int L = query[i][1];
            int R = query[i][2];
            long long sum = rangeQuery(1, 0, n-1, L, R);
            cout << sum << endl;
        }
    }

    return 0;
}