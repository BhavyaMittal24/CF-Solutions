#include <bits/stdc++.h>
using namespace std;

int index( int si, int ei, vector<int>& LIS, int val){
    int mid = 0;
    int ans = -1;
    // FFFFFF TTTTT // arr[x] >= val
    while( si <= ei){
        mid = (si + ei)/2;
        if( LIS[mid] >= val){
            ans = mid;
            ei = mid - 1;
        } else {
            si = mid + 1;
        }
    }
    return ans;
} 
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> LIS;
    int maxLen = 1;
    LIS.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > LIS.back())
        {
            LIS.push_back(arr[i]);
        }
        else
        {
            int idx = index(0, LIS.size() - 1, LIS, arr[i]);
            LIS[idx] = arr[i];
        }
        maxLen = max(maxLen, (int)LIS.size());
    }

    cout << maxLen << endl;
}