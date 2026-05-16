#include<bits/stdc++.h>
using namespace std;

bool isPossible(int power, vector<pair<int,pair<int,int>>> & maxRowVal){

    bool canDestroy = true;

    int n = maxRowVal.size();
    for(auto monster : maxRowVal){

        // check if this power can destroy all the monster armours for eeach cave
        // cave i -> maxMonter armour 
        if( power >= monster.first){
            power += monster.second.second;
        }
        else {
            canDestroy = false;
            break;
        }
    }
    return canDestroy;
}
void solve(){

    int n;
    cin >> n;

    vector<pair<int,pair<int,int>>> maxRowVal;
    for(int i = 0; i < n; i ++){
        int k;
        cin >> k;

        int maxValIdx = -1;
        int maxVal = 0;

        // for each cave i : find the max power required : monster amrour + j + 1
        // j is the position of the monster in the cave
        for(int j = 0; j < k; j ++){
            int x;
            cin >> x;
            
            if(maxValIdx == -1){
                maxVal = x+1;
                maxValIdx = 0;
            }
            else {
                if(maxVal < x + 1 - j){
                    maxVal = x + 1 - j;
                    maxValIdx = j;
                }
            }
        }

        // push the maxMonster value required and for killing which monster : 
        maxRowVal.push_back({maxVal, {maxValIdx,k}});
    }

    sort(maxRowVal.begin(), maxRowVal.end());

    // we can add at the end of each cave : add + n-i for the next cave : it is better to destroy them in icreasing order
    // given some value x : max val for row1, max val for row2, ... orted order
    // x : 1, 5 ,6 , 9 , 11
    // x = 5 : i can gain some values also

    int low = maxRowVal[0].first;
    int high = maxRowVal.back().first;


    int ans = -1;
    while( low <= high){

        int mid = (low + high) / 2;
        
        //cout << mid << "\n";
        if( isPossible(mid, maxRowVal)){
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
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