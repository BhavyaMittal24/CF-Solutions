#include<bits/stdc++.h>
using namespace std;


// find the maximum sum of a subarray which has a length between a and b

int main(){

    int n,a,b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> prefixSum(n+1,0);
    prefixSum[0] = 0;
    for(int i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1] + arr[i-1];
    }

    // For the subarray starting from L to R the sum is prefix[r] - prefix[l-1];

    // assuming the index where the subbarray ends is constant or fixed r:
    // a = 3
    // b = 5
    // for a subarray of length 3 the first ending index should be 3

    //            [b    [a    r
    // arridx     1 2  3   4  5 6 7 8 9 
    
    // prefix               
    // index 2,6 length = 5  pre[6] - pre[2-1] : left = pre[r-b]
    //       3,6        = 4
    //       4,6        = 3                             pre[r-a]
    
    //            _____
    //            b   a     R    r r r r'
    // prefix   0 1 2 3 4 5 6 7 8 9

    // hence the stargting imdex of pre can be r-b to r-a or r-b+1, r-a+1 
    // As r increases, i am also adding more elements to the window and min size cn be a hence adding r-ath element 
    // if at any given point the window also has more than b-a+1, check if index  < r-b that means remove
    //  if we are considering the subarrauy ending at r, then it's range of starting can be r-b+1, to r-a+1
    //        l-1 l       r
    // l = 1 and r = 5, then sum = prefix[5] - prefix[0] : hence in prefix array we find difference of k between l and r, size is k then r , r-k 
    //            a
    //          _______  
    //          ___________ 
    // between l and r
    //
    deque<int> dq;
    int maxSum = INT_MIN;
    for(int right = a; right <=n; right++){
        while(!dq.empty() && prefixSum[dq.back()] >=prefixSum[right-a]){
            dq.pop_back();
        }
        dq.push_back(right-a);
        if(!dq.empty() && dq.front() < right-b){
            dq.pop_front();
        }
        int leftMin = prefixSum[dq.front()];
        maxSum = max(maxSum, prefixSum[right] - leftMin);
    }
    cout << maxSum << endl;
    return 0;
}