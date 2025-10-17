// Maximum average segment

#include<bits/stdc++.h>
using namespace std;

// given n and d , where 1 <= d <=n <= 1e5,
// find the [l,r] of a subarray of length atleast d with the maximum mean

// values of array can be  0<=ai<=100

// monotonic predicate function 
// f(x) = T if there is a subarray with mean >= x
// 2 4 6 9 "15" 20 21 30 45 
// T T T T  T  F  F F F
// ai + ai+1 ..   ai+k-1 >= kx


pair<int,int> subArrayWithSumGreaterThanMean(long double mean, int n, int d, vector<long double>& a){
   vector<long double> transformedArray(n);
   for(int i = 0;i<n;i++){
      transformedArray[i] = a[i] - mean;
   }
   vector<long double> prefix(n);
   prefix[0] = transformedArray[0];
   for(int i=1;i<n;i++){
     prefix[i] = prefix[i-1] + transformedArray[i];
   }

   int bestLeftIndex = -1;
   long double bestSum = 1e10;
   for(int right = d-1; right < n;right++){
        bestSum = prefix[right] - (bestLeftIndex == -1 ? 0 : prefix[bestLeftIndex]);
        if(bestSum >= 0){
           return {bestLeftIndex + 1, right}; // 1-based index
        }
        if( bestLeftIndex == -1 && prefix[right-d+1] < 0 ){
              bestLeftIndex = right - d + 1; // first index where prefix is negative
        }
        else if( prefix[right-d+1] < prefix[bestLeftIndex] ){
              bestLeftIndex = right - d + 1;
        }
   }
    return {-1, -1}; // no such subarray exists
}

// subarray of length >= d with maximum sum of subaray
long double maxSubArraySum( vector<long double> transformedArray, int d){
   int n = transformedArray.size();
   vector<long double> prefix(n);
   prefix[0] = transformedArray[0];
   for(int i=1;i<n;i++){
     prefix[i] = prefix[i-1] + transformedArray[i];
   }
             
  // Prefix [r] - prefix [l-1] : sum of subarray from l to r
   long double minSoFar = 0;
   long double ans = INT_MIN;
   for(int right = d-1; right<n; right++){
      long double bestSubArrayEndingAtRight = prefix[right] - minSoFar;
      ans = max(ans, bestSubArrayEndingAtRight);
      minSoFar = min(minSoFar, prefix[right-d+1]); 
   }
   return ans;
}

bool f(long double x, int n, int d, vector<long double>& a){
   vector<long double> transformedArray(n);
   for(int i = 0;i<n;i++){
      transformedArray[i] = a[i] - x;
   }
   return maxSubArraySum(transformedArray, d) >=0;
}


int main() {

  int n;
  int d;
  cin >> n >> d;
  vector<long double> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  
 // number of iterations = 0(SS)
 // SS = 100 * (no of decimal places - 30)
 // log(1e32) : 32 * 3.5 ~100 = 150 iterations
 
 long double low = 0;
 long double high = 100;
 long double ans  = -1;
 long double mid = 0;

 for(int i = 0;i<100;i++){
   mid = low + (high - low)/2;
   if(f(mid,n,d, a)){
      low = mid;
    }
   else 
     high = mid;
 }
 
 //cout << fixed << setprecision(10) << low << endl;
 pair<int, int> result = subArrayWithSumGreaterThanMean(low, n, d, a);
 cout << result.first+1 << " " << result.second+1
  << endl;
  return 0;
}