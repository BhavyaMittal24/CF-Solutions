#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}
void solve(){
    int n,m;
    cin >> n >> m;

    int cnt=0;
    vector<int> a(n,0);
    vector<int> b(m,0);
    vector<int> c(m,0);

    multiset<int> ms;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ms.insert(a[i]);
    }

    for(int i=0;i<m;i++) cin >> b[i];

    for(int i=0;i<m;i++){
        cin >> c[i];
    }

    vector<pair<int,int>> healthReward;;
    vector<pair<int,int>> zeroRewards;
    for(int i=0;i<m;i++){
        // monster health , reward for sword you get back
        if(c[i] == 0){
            zeroRewards.push_back({b[i], c[i]});        
        }
        else {
            healthReward.push_back({b[i], c[i]});
        }
    }

  
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    sort(healthReward.begin(), healthReward.end(), compare);
    sort(zeroRewards.begin(), zeroRewards.end(), compare);

    for(int i=0;i<zeroRewards.size();i++){
        healthReward.push_back({zeroRewards[i].first, zeroRewards[i].second});
    }

    for(int i=0;i<m;i++){
        int lifevalue = healthReward[i].first;
        int reward = healthReward[i].second;

        //cout << lifetime << " " << reward << endl;
        // find first value greater than the minster health
        auto it = ms.lower_bound(lifevalue);        

        if(it != ms.end()){
             // it is an interator pointing to the value
             // *it is the actual value
            cnt++;
            if(reward == 0){
                ms.erase(it);
            }
            else if(reward > *it) {
                ms.erase(it);
                ms.insert(reward);
            }
        }
    }
    cout << cnt << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}