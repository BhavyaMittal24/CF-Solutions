#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,s;
    cin >> n >> s;
    vector<int> weights(n);
    vector<int> cost(n);
    for(int i=0;i<n;i++){
        cin >> weights[i];
    }
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }

    long long currentWeight = 0;
    long long maxCost = 0;
    long long currentCost = 0;

    for(int right = 0 ,left = 0;right < n;right++){
        currentWeight += weights[right];
        currentCost += cost[right];

        while( left <= right && currentWeight > s){
            currentWeight -= weights[left];
            currentCost -= cost[left];
            left++;
        }
        if(currentWeight <= s) maxCost = max(maxCost, currentCost);
    }

    cout << maxCost << endl;
    return 0;
}