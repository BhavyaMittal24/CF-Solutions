#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    
    vector<pair<int,int>> pwA;
    vector<pair<int,int>> pwB;
    vector<pair<int,int>> pwC;
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


    //reverse(activities.begin(), activities.end());
    vector<int> activityTypeDone(3, 0);

    vector<int> isIdxVisited(n,0);
    long long maxFun = 0;
   
    int i = 0;
    int j = 0;
    int k = 0;

    int cnt = 0;
    while( i < n && j < n && k < n  && cnt < 3){

        int valA = pwA[i].first;
        int idxA = pwA[i].second;
        
        int finalMaxVal = 0;
        int activityChosen = -1;
        int idxChosen = -1;

        if( activityTypeDone[0] ||  isIdxVisited[idxA]){
            i++;
        }
        else {
            activityChosen = 0;
            idxChosen = idxA;
            finalMaxVal = valA;
            i++;
        }

        int valB = pwB[j].first;
        int idxB = pwB[j].second;

        if( activityTypeDone[1] || isIdxVisited[idxB]){
            j++;
        }

        else if(valB > finalMaxVal) {

            activityChosen = 1;
            idxChosen = idxB;
            finalMaxVal = valB;
            j++;
        }
    

        int valC = pwC[k].first;
        int idxC = pwB[k].second;

        if( activityTypeDone[2] || isIdxVisited[idxC]){
            k++;
        }

        else if( valC > finalMaxVal){
            activityChosen = 2;
            idxChosen = idxC;
            finalMaxVal = valC;
            k++;
        }

        if( activityChosen != -1){
            activityTypeDone[activityChosen] = 1;
            isIdxVisited[idxChosen] = 1;
            maxFun += finalMaxVal;
            cnt++;
        }

    }

    cout << maxFun << endl;

}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}