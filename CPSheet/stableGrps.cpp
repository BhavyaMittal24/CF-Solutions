#include<bits/stdc++.h>
using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, x;
    cin >> n >> k >> x;

    vector<long long> arr(n);

    for(int i = 0; i < n; i ++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<long long> gaps;

    for(int i = 0; i < n; i ++){
        if(i == 0) continue;

        // new gap 
        if( arr[i] - arr[i-1] > x) {
            gaps.push_back(arr[i] - arr[i-1]);
        }
    }

    // with a given gap value : gap[i]
    // no of extra levels to bridge the gap :  ceil(gap[i]/x) - 1

    sort(gaps.begin(), gaps.end());

    long long minGrps = gaps.size()+1;

    // 4 4 7
    // x = 3
    // k = 2

    for(auto gap : gaps){

        //cout << gap << " ";
        long long extraLevels = (gap/x) -1;

        if(gap % x) {
            // 8 / 3 
            extraLevels++;
        }
        
        //cout << k << " " << extraLevels << endl;
        if( k >= extraLevels) {
            minGrps --; // gap bridged between two diff stable grouops
            k -= extraLevels;
        }
        else break;
    }

    cout << minGrps << endl;
    return 0;
}