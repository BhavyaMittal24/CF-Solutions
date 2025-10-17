#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    // n is numer of friends
    // d is the min diff after which a friend feels poor. D = 1e9
    // mi si : the amount of money and the friendship factor of the i-th friend. 1 <= mi, si <= 1e9
    // sort based on money 
    // [ 1 2 3 ... mi ... n]
    //  for a given subarray, [l,r] if arr[r] - arr[l] < d
    // then friedship factor is sum of all friendship factors in the subarray
    // now this is a type 1 good subarray : we find all suc hgoodsubarrays and the largest subarray would have the max friendship factor

    // [10 15 30 100 200]
    // d= 90
    //
    cin >> n >> d;
    vector<pair<long long, long long>> friends(n);
    for(int i=0;i<n;i++){
        cin >> friends[i].first >> friends[i].second;
    }
    sort(friends.begin(), friends.end());
    long long currentFriendshipFactor = 0;
    long long maxFriendshipFactor = 0;
    int left = 0, right = 0;
    while(right < n){
        currentFriendshipFactor += friends[right].second;
        while(left<=right && friends[right].first - friends[left].first >=d){
            currentFriendshipFactor -= friends[left].second;
            left++;
        }
        if( friends[right].first - friends[left].first < d){
            maxFriendshipFactor = max(maxFriendshipFactor, currentFriendshipFactor);
        }
        right++;
    }
    cout << maxFriendshipFactor << endl;
    return 0;
}