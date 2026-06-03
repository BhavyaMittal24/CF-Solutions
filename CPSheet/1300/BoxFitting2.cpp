#include<bits/stdc++.h>
using namespace std;

bool checkPlace(int height, int W, multiset<int> widths){

    // msb for each numebr is there : you can find if that bit is present in W or not 

    // widths is all the memebers you need to place in the box

    while(height-- && widths.size() > 0){

        int maxWidth = W;
        vector<int> removeW;
        auto it = widths.rbegin();
        while( it != widths.rend()){

            int width = *it;
            if( maxWidth >= width){
                maxWidth = maxWidth - width;
                removeW.push_back(width);
            }
            else if(maxWidth == 0) break;
            it++;
        }

        for(auto w : removeW){
            widths.erase(widths.find(w));
        }
    }

    if(widths.size() > 0) return false;

    return true;
}


void solve(){
    int n;
    int W;
    cin >> n >> W;
    
    // cin >> wi : powers of 2 : boxes of height 1 and width  : 2^ i : powers of 2 from 1 to 1e6 (1 << i)

    vector<int> cntPowers(21,0); // cntPowers[i] : no of (1 << i)

    for(int i = 0; i < n; i ++){

        int x;
        cin >> x;
        int power = log2(x);
        cntPowers[power]++;
        // powers : 0, 1, 2 ,2 , ...
    }

    int height = 1;
    int placed = 0;
    while(placed < n){

        int remWidth = W;
        for(int i = 20; i >= 0; i --){

            if(cntPowers[i] == 0){
                continue;
            }

            int width = (1 << i);

            if(width > remWidth) continue;

            int cnt = remWidth/width;
            if(cnt >= cntPowers[i]){
                remWidth = remWidth - cntPowers[i]*width;
                placed += cntPowers[i];
                cntPowers[i] = 0;
            }

            else {
                // cnt < cntPowers[i]

                remWidth = remWidth - cnt*width;
                cntPowers[i] -= cnt;
                placed += cnt;
            }
        }

        if(placed == n) break;
        height++;
    }

    cout << height << "\n";
    return ;

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;

    while(t--){
        solve();
    }

    return 0;
}

/*

1001
34 944
4 256 512 16 1 16 1 64 4 16 64 256 128 4 64 128 16 2 512 512 1 512 128 512 8 4 8 2 32 2 1 32 128 4
97 590
4 2 32 1 1 1 16 256 32 32 2 8 512 1 16 64 64 512 8 128 8 64 4 2 64 256 16 32 16 128 16 16 32 512 128 2 1 256 128 4 4 1 64 1 4 128 128 2 4 128 512 256 4 2 64 16 2 128 128 512 32 32 8 64 128 16 8 4 16 8 64 1 128 64 128 256 4 512 8 1 1 64 16 64 8 1 128 8 2 64 8 512 256 8 64 64 1
63 250
4 32 4 4 32 2 8 64 4 16 16 16 1 128 16 32 2 16 1 64 16 32 2 2 16 16 16 16 128 2 1 1 1 1 8 8 64 1 64 64 ...
*/