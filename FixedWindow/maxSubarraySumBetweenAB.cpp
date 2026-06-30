#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> arr(n+1,0);

    vector<long long> prefix(n+1,0);

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }

    // max prefix sum in between a and b
    // lwt the subrray end at r :                          [    b               [    a       ]                   
    // pre[r] - min pre[l-1] for a size between a and b :  [r-b  r-b+1      r-a r-a+1       r]

    // sroe the min value in the window between (r-b, r-a) at the go always store the min value and when r++ still gave that value

    long long maxSum = -1e18;
    //-1,  0 1 2 3 4 5  a = 2, b=  5
    // storing the min value in range [r-b, r-a]
    set<pair<long long, int>> minPrefix;

    // now trying to optimise the usage of deque instead of a set
    // dequeu storing the indexes for the prefox

    deque<int> dq;
    dq.push_back(0);
    //minPrefix.insert({0,0});

    for(int r = a; r <= n; r ++){
        // subarray ends at [ r]
        // can consider adding new elements to left min
        if(r >= a+1){

            //minPrefix.insert({prefix[r-a], r-a});
            while( !dq.empty() && prefix[dq.back()] > prefix[r-a]){
                dq.pop_back();
                // remove all the x-1, x, x+1 ... Y ill x < Y : if prefox[r] is less, we must havrit as latesrt inthe windoe 
            }

            dq.push_back(r-a);
        }

        if( r >= b+1){
           // minPrefix.erase({prefix[r-b-1], r-b-1});
           while(!dq.empty() && dq.front() <= r - b - 1){
              dq.pop_front();
           }
        }

        // length is atleast a
        if( r >= a){
            long long minPrefixSum = prefix[dq.front()];
            maxSum = max(maxSum, prefix[r] - minPrefixSum);
        }
    }
    cout << maxSum << '\n';
    return 0;
}