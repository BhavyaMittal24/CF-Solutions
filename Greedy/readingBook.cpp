#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i ++ ) cin >> arr[i];
    long long totalTime = 0;

    sort(arr.begin(), arr.end());

    int i = 0;
    int j = n-1;

    while( i < j){

        long long sum = 0;

        while(i < j && (sum + 1ll*arr[i]) <= arr[j]){
            sum += 1ll*arr[i];
            i++;
        }

        totalTime+= 1ll*arr[j];
        j--; 
    }

    totalTime = 2ll*totalTime;

    if(i==j){
        totalTime += 1ll*arr[i];
    }

    cout << totalTime << endl;
    return 0;
}