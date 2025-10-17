#include<bits/stdc++.h>
using namespace std;

bool possibleToMeet(vector<int> &x, vector<int> &v, double time){
  int n = x.size();
  double miny1y2 = INT_MAX;
  double maxx1x2 = INT_MIN;
  for(int i=0;i<n;i++){
     double xi = x[i] - v[i]*time;
     double yi = x[i] + v[i]*time;
     maxx1x2 = max(maxx1x2,xi);
     miny1y2 = min(miny1y2,yi);
     if( miny1y2 < maxx1x2) return false;
  }
  return true;
}
int main(){

// Find the minimum time where you can have all he points meet
// given an array of coordinates  -1e9 <= xi <= 1e9
// array of respective speeds  1 <= vi <= 1e9
// points can move in both places
// the time  can also be in decimal, bec we require precison upto 6 decimal places :
// iterations have to be fixed : 1e18 * 1e7 " 
// SS = log(1e25) = 100 
   int n;
   cin >> n;
   vector<int> x(n);
   vector<int> v(n);
   for(int i=0;i<n;i++){
      cin >> x[i];
   } 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
   cout << setprecision(6) << endl;
    double low = 0;
    double high = 1e9;
    double mid = 0;
    double ans = 0;
    double precision = 1e-6;
   
    // using a for loop for bs on decimal
   for(int i=0;i<60;i++){
	mid = low + (high -low)/2;
        cout << "low = " << low << " high = " << high << " mid = " << mid << endl;
        if(possibleToMeet(x, v, mid)){
            high = mid-precision;
            ans = mid;
        }
        else{
            low = mid+precision;
        }
   }
   cout << ans << endl;;
   return 0;
 }