#include<bits/stdc++.h>
using namespace std;

// dp[i][st1 for activits chosen] [st2 for days chosen] = maxfrineds for number of days from i to n

    map<pair<int, pair<set<int>, set<int>>> , int> dp;

    vector<pair<int,int>> pwA;
    vector<pair<int,int>> pwB;
    vector<pair<int,int>> pwC;

int findMaxFriends(int i, int n, set<int>& daysChosen, set<int>&  activityChosen){

    if (i == n) return 0;

    if( daysChosen.size() == 3) return 0;

    if( activityChosen.size() == 3) return 0;

   pair<int, pair<set<int>, set<int>>> key = {i, {daysChosen, activityChosen}};

   if( dp.count(key) == 1) {
        return dp[key];
    }

    vector<int> possibleActivities = {1,2,3};

    int ans = findMaxFriends(i + 1, n, daysChosen, activityChosen);

    for(auto type : possibleActivities){

        int chosenAns = 0;
        if( activityChosen.find(type) != activityChosen.end()) continue;

        int dayChosen = -1;

        switch (type){
            case 1 : {
                dayChosen = pwA[i].second;
                chosenAns = pwA[i].first;
                break;
            }
            case 2 :{
                dayChosen = pwB[i].second;
                chosenAns = pwB[i].first;
                break;
            }

            case 3 :  {
                dayChosen = pwC[i].second;
                chosenAns = pwC[i].first;
                break;
            }
            default : {
                dayChosen = -1;
                break;
            }
        }

        if(daysChosen.find(dayChosen) != daysChosen.end()) continue;
        
        daysChosen.insert(dayChosen);
        activityChosen.insert(type);
        ans = max( ans, chosenAns + findMaxFriends(i+1, n, daysChosen, activityChosen));

        daysChosen.erase(dayChosen);
        activityChosen.erase(type);
    }

    return dp[key] = ans;
}
void solve(){

    int n;
    cin >> n;
    
    pwA = {};
    pwB = {};
    pwC = {};

    map<pair<int, pair<set<int>, set<int>>> , int> dp1;
    dp = dp1;
   
    for(int i = 0 ; i < n; i ++){
        int ai;
        cin >> ai;
        pwA.push_back({ai, i});
    }

    for(int i = 0; i < n; i ++){
        
        int bi;
        cin >> bi;
        pwB.push_back({bi, i});
    }

    for(int i = 0; i < n; i ++){
        int ci;
        cin >> ci;
        pwC.push_back({ci, i});
    }



    sort(pwA.begin(), pwA.end());
    sort(pwB.begin(), pwB.end());
    sort(pwC.begin(), pwC.end());

    reverse(pwA.begin(), pwA.end());

    reverse(pwB.begin(), pwB.end());

    reverse(pwC.begin(), pwC.end());

    set<int> daysChosen;
    set<int> activityChosen;

    int ans = findMaxFriends(0, n, daysChosen, activityChosen);

    cout << ans << endl;
   return;
}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}