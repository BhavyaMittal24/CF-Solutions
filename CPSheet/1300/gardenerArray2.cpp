#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<vector<int>> setBits(n+1);

    map<int,int> cntOccurences;
    for(int i = 1; i <= n; i ++){
        int k;
        cin >> k;

        while(k--){
            int bitPos;
            cin >> bitPos;
            // bitPos : no of indixes it is a part of
            cntOccurences[bitPos]++;
            setBits[i].push_back(bitPos);
        }
    }

    bool isPossible = false;

    for(int i = 1; i <= n; i ++){
        // check for all the indices : if for one indixe : all its set bits have their cnt >= 2 : ie one more same bitPos is present for all the bitPos for that number
        // i  = 1 :  2, 4 : if both 2 and 4 have some other indices where they are also present
        
        vector<int> bitPositions = setBits[i];
        
        bool flag = true;

        for(auto bit : bitPositions){
            if(cntOccurences[bit] <= 1){
                flag = false;
                break;
            }
        }

        if(flag == true) {
            isPossible = true;
            break;
        }
    }

    if(isPossible){
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

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