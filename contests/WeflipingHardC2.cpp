#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long long, long long>& a, pair<long long, long long> &b)
{
    return abs(a.first - a.second) > abs(b.first - b.second);
}

void solve(){

    int n;
    cin >> n;
 
    vector<int> arr(n+1,0);

    vector<long long> prefix(n+1,0);
    vector<long long> suffix(n+1,0);

    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
        prefix[i] = prefix[i-1] + abs(arr[i]);
    }

    for(int i = n; i>= 1; i--){
        
        if( i == n) suffix[i] = arr[i];
        else suffix[i] = suffix[i+1] + arr[i];
    }


    // find the best positive index : where max value of prefix[i] -2*arr[i] + suffix[i] - arr[i] : a1 + a2 ... aidx-1 -aidx + 
    int maxIdx = -1;

    long long maxSum = suffix[1];
    int cnt = 0;
    for(int i = 1 ; i <= n; i ++){
        if(arr[i] > 0){


            cnt++;
            long long newSum = prefix[i] - 3ll*arr[i] + suffix[i];
            //cout << newSum << " " << maxSum << "\n";
            if(newSum > maxSum){
                maxIdx = i;
                maxSum = newSum;
            }
        }
    }

    if( maxIdx == -1 || cnt == n){
        cout << "0\n";
        return;
    }



    vector<int> op;

    // maxIdx : idx1 ..... idx2 ............ idx3 ............ idx4 : 
    // final outpu :      a1 a2 ....... aidx-1 -aidx .......same as rest : 
    int i = maxIdx - 1;

    int flips = 0;
    while( i>=1){

      
        // find first index which is positive
        int j = i;
        int val = arr[j];
        if(flips % 2 == 0 ) val = arr[j];
        else val = -1* arr[j];
        while( j >= 1 && val < 0){
            j--;
            if(flips % 2 == 0 ) val = arr[j];
            else val = -1* arr[j];
        }

        // j is the value where we have first positive;
        if(j != 0) op.push_back(j);
        flips++;
        i = j;
    }

    op.push_back(maxIdx);
    cout << op.size() << "\n";

    for(auto it : op){
        cout << it << " ";
    }

    cout << "\n";

    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}