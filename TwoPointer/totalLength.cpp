#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    long long total_sum_of_lengths = 0;
    int left = 0; 
    long long sum = 0;
    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum > k) {
            sum -= a[left];
            left++;
        }
        long long current_window_length = right - left + 1;
        total_sum_of_lengths += (current_window_length * (current_window_length + 1)) / 2;
    }
    cout << total_sum_of_lengths << endl;
    return 0;
}