#include<bits/stdc++.h>
using namespace std;

// n 

int ask(int l, int r){
    vector<int> resp(r-l+1);
    cout << "? " << l << " " << r << endl;
    int cnt = 0;
    for(int i = 0; i < r-l+1; i++){
        cin >> resp[i];
        if(resp[i] >= l && resp[i] <= r){
            cnt++;
        }
    }
    return cnt;
}

// n is odd
//        l .....x..y... r
// x and y can be in range : cnt elements bw [l,r] : even
//        l .....z ....r .....x
// even : 0
// only 1 element would be in place : actually which would mke it odd
//        1 2 3 4 5
//        actual  2 [1 4] 3 5
//        concept 1 [2 3] 4 5 
          // l = 2
          // r = 3
          // cnt = 0;
 
int main(){
   int t;
   cin >> t;
   while(t--){
        int n;
        cin >> n;
        int low = 1;
        int high = n;
        int mid = 0;
        int ans = -1;
        while(low <=high){
            mid = (low + high) / 2;
            int cnt = ask(low,mid);
            if(cnt % 2 == 0){
                low =mid+1;
            }
            else {
                ans = mid;
                high = mid-1;
            }
        }
        cout << "! " << ans << endl;
    }
    return 0;
}