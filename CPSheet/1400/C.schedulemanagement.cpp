#include<bits/stdc++.h>
using namespace std;

bool isPossible(int time, int m, int n, map<int,int> & mp){
    // m total tasks, try to see if you can make more or equal tasks in that time

    long long totalTasks = 0;
    for(int i = 1; i <= n ;i ++){
        // worker i
        if( mp.count(i) == 0){
            totalTasks += 1ll*time/2;
        }
        else {
            if( time >= mp[i]){
                totalTasks += 1ll*mp[i];
                int remTime = time - mp[i];
                totalTasks += 1ll*remTime/2;
            }
            else {
                totalTasks += 1ll*time;
            }
        }
    }

    return totalTasks >= m;
}
void solve(){

    int n, m;
    cin >> n >> m;

    // n workers , m tasks

    vector<int> taskworker(m);
    map<int,int> mp;
    
    for(int i = 0; i < m; i++){
        cin >> taskworker[i];
        mp[taskworker[i]]++;
    }

    // 1112234 , n = 5
    int low = 0;
    int high = 2*m;

    int mintime = -1;
    while( low <= high){

        int mid = (low + high)/2;
        // check if it is possible for a given time, n workers and m tasks and the cnt of tasks per proficent wprker 
        if(isPossible(mid, m, n, mp)){
            mintime = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    cout << mintime << "\n";
}
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}