#include<bits/stdc++.h>
using namespace std;
//    1 2 3

// 1  1 2 3
// 2  2 4 6
// 3  3 6 9

//1 2 2 3 3 4 6 6 9//

bool isPossibleMedian(long long n, long long mid){
    // for the value to be median it should have (n*n/2)+1 elements befire it 
    long long idealCount = (n*n)/2+1;
    long long count = 0;
    for(int row = 1; row <=n; row++){
        count += min(n, mid/row);
        // for each row, we can have at most n elements
    }
    return count >= idealCount; // if we have enough elements less than or equal to mid
}

int main(){
    long long n;
    cin >> n;

    // find the median of a n*n matrix given n is an odd number
    // range of possible medians is from 1 to n*n;

    // n <= 1e6
    long long low = 1;
    long long high = n * n;
    long long mid = 0;
    long long ans = 1e13;

    while(low <= high){
        mid = (low + high) / 2;
        if(isPossibleMedian(n,mid)){
            if(ans ==-1) ans = mid;
            else ans = min(ans,mid);
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans << endl;
    return 0;

}