#include<bits/stdc++.h>

using namespace std;

int countMaxElementsLessThanOrEqualTo2(vector<int> &a, int startIdx) {
   int low = startIdx+1;
   int high = a.size() - 1;
   int ans = -1;
   while(low <=high){
    int mid = low + (high - low) / 2;
    if(a[mid] <= 2* a[startIdx]) {
        ans = mid;
        low = mid + 1; // Move to the right half
    } else {
        high = mid - 1; // Move to the left half
    }
   }
    return ans;

}
bool isPossibleToMakePairs(vector<int> &a, long long pairs) {
    // Check if we can make 'pairs' number of unordered pairs {x,y}
    // such that |x-y| <= x <= y <= |x+y|
    int n = a.size();
   
    long long count = 0;
    for(int i=0;i<n-1;i++){
        int maxIdx = countMaxElementsLessThanOrEqualTo2(a, i);
        if(maxIdx != -1){
            count += (maxIdx-i);
        }
    }
    return count >= pairs; // If we can make at least 'pairs' number of pairs
    
}

// TC is O(nlogn + log(1e18) * nlog)
int main(){
    // the number of possible values from which we can make the unordered pairs {x,y}
    // a1 a2 ... an
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i] = abs(a[i]); 
    }
    
    // find the maxiumum number of unrodered pairs {x,y} we can make such that
    // |x-y| <= x <=y <= |x+y|
    // set of possible candiadatw answers 
    sort(a.begin(), a.end());
    long long low = 0;
    long long high = 1e18;  //( n*n-1 /2)
    long long mid = 0;
    long long ans = 0;

    while( low <= high){
        mid = low + (high - low) / 2;
        if(isPossibleToMakePairs(a, mid)){
            ans = mid;
            low = mid + 1; // Try to find a larger number of pairs
        } else {
            high = mid - 1; // Try to find a smaller number of pairs
        }
    }
    cout << ans << endl; // Output the maximum number of pairs

    return 0;
}