// local minimum
#include<bits/stdc++.h>
using namespace std;

// n = 7
// 2 4 3 6 5 7 1

int ask(int idx){
  cout << "? " << idx << endl;
  int input;
  cin >> input;
  return input;
}
int main(){
//     l r   r     
//     1 3 2 4 5 6 7
// 1e9 4 1 3 7 5 6 2
// 1e9 3 5 6 7 9 10 1 2 1e9
	int n;
    cin >> n;
    int low = 1;
 	int high = n;
	int mid = 0;
	int ans = -1;
        while(low <=high){
            mid = (low+high)/2;
            int curr=ask(mid);
            int next= (mid == n) ? 1e9 : ask(mid+1);
            //int prev = (mid == 1) ?1e9 : ask(mid-1);
            if( curr<next){
                ans = mid;
                high = mid-1;
            }
            else {
            low = mid+1;
            }
        }
	cout << "! " << ans << endl;
    return 0;
}