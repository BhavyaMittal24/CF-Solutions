#include<bits/stdc++.h>
using namespace std;

int findWormPile(long long worm, vector<pair<long,long>> &wormPiles) {
    int low = 0;
    int high = wormPiles.size() - 1;
    int mid  = 0;
    int ans = -1;
    while(low <= high){
        mid = low + (high - low) / 2;
       if( wormPiles[mid].first <= worm && worm <= wormPiles[mid].second){
            ans = mid;
            break;
        }
        else if(worm < wormPiles[mid].first){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans+1;

}
int main(){
    int n;
    cin >> n;
    vector<int> worms(n);
    for(int i = 0; i < n; i++){
        cin >> worms[i];
    }
    int m;
    cin >> m;
    vector<int> queries(m);
    for(int i = 0; i < m; i++){
        cin >> queries[i];
    }

    vector<pair<long,long>> wormPiles(n);
    wormPiles[0] = {1,worms[0]};
    for(int i=1; i< n;i++){
        wormPiles[i] = {wormPiles[i-1].second+1, wormPiles[i-1].second+worms[i]};
        
        //cout << wormPiles[i].first << " " << wormPiles[i].second << endl;
    }

    for(int i = 0; i < m ;i ++){
        int worm = queries[i];
        cout << findWormPile(worm, wormPiles) << endl;
    }
    return 0; 


}