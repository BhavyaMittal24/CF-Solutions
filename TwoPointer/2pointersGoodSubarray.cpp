#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    // find the longest subarray with sum <= k and also the count of all suubarrays with sum <= k
    int left = 0, right = 0;
    int currentSum = 0;
    int maxLength = 0;
    int countSubarrays = 0;
    while(right < n){
        currentSum += arr[right];
        // find the longest subarray with sum <= k
        while(left <=right && currentSum > k){
            currentSum -= arr[left];
            left ++;
        }
        if(currentSum <=k){
            maxLength = max(maxLength, right - left + 1);
            countSubarrays += (right - left + 1);
        }
        right++;
    }

    cout << "Max length and count of subarrays with sum <= " << k << " is: ";
    cout << maxLength << " " << countSubarrays << endl;

    currentSum = 0;
    int minLength = INT_MAX;
    left = 0;
    right = 0;
    countSubarrays = 0;

    // 1 2 3 4 5    k = 10
    // l = 0
    // r = 3
    // 
    // find the smallest subarray with sum >= k
    while(right < n){
        currentSum += arr[right];
        while(left <=right && currentSum >=k){
            minLength = min(minLength, right -left+1);
            currentSum -= arr[left];
            left++;
            countSubarrays += (n - right); // all subarrays starting from left to right and ending at right to n-1 will have sum >= k
        }

        right++;
    }
    return 0;

}