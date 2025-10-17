#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m, s, wa, wb;
    cin >> n >> m >> s >> wa >> wb;
    vector<int> a_costs(n);
    vector<int> b_costs(m);
    for(int i=0;i<n;i++) cin >> a_costs[i];
    for(int i=0;i<m;i++) cin >> b_costs[i];
    sort(a_costs.begin(), a_costs.end(), greater<int>());
    sort(b_costs.begin(), b_costs.end(), greater<int>());
    int total_items_a = min(n,s/wa);
    long long maxCost = 0;
    long long currentCost = 0;
    long long currentWeight = total_items_a * wa;
    for(int i=0;i<total_items_a;i++) {
        currentCost += a_costs[i];
    }
    maxCost = currentCost;
    int left = total_items_a-1;
    int right = 0;
    while(right < min(m,s/wb)){
        currentCost += b_costs[right];
        currentWeight += wb;
        while(left>=0 && currentWeight >s){
            currentWeight -= wa;
            currentCost -= a_costs[left];
            left --;
        }
        if(currentWeight <=s) {
            maxCost = max(maxCost, currentCost);
        }
        right++;
    }
    cout << maxCost << endl;
    return 0;
}