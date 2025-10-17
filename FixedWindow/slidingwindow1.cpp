#include <bits/stdc++.h>
using namespace std;

struct comp {

bool operator()(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}
};

int main()
{

    // find the subarray of size k  with maximum sum
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < n; i++)
    {

        currentSum += arr[i];

        // The secind window is reached.
        if (i >= k)
        {
            currentSum -= arr[i - k];
        }
        // the first window is closed and we can have the answer comuptation
        if (i >= k - 1)
        {
            maxSum = max(maxSum, currentSum);
        }
    }
    cout << maxSum << endl;

    // FInd the subarray of size k with maximum distinct elements
    map<int, int> freqMap;

    // for the first sliding window
    for (int i = 0; i < k; i++)
    {
        freqMap[arr[i]]++;
    }

    int ans = freqMap.size();

    for (int i = k; i < n; i++)
    {
        freqMap[arr[i]]++;
        freqMap[arr[i - k]]--;

        if (freqMap[arr[i - k]] == 0)
        {
            freqMap.erase(arr[i - k]);
        }
        ans = max(ans, (int)freqMap.size());
    }

    cout << ans << endl;
    // find thw subarray of size k with maximum sum and all elements should be distinct
    int sum = 0;
    ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {

        // Woth every new element in the window, we add it to the sum and the freq
        sum += arr[i];
        mp[arr[i]]++;

        // remove the first element on the window if size exceeds k
        if (i >= k)
        {
            sum = sum - arr[i - k];
            mp[arr[i - k]]--;

            if (mp[arr[i - k]] == 0)
            {
                mp.erase(arr[i - k]);
            }
        }

        if (i >= k - 1)
        {
            if (mp.size() == k)
            {
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;

    // find the index of the minimum element in the subarray of size k

    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

    // 1 2 3 3 2 4 5
    // _____
    // minIndex = 1
    //  I = 3
    //  minIndex ?
    // urrentIndex
    //  have the information of the next min element. after 1

    // q of size k that keeps all elements in a sorted manner and pq.top() gives the smallest value
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }

    ans = pq.top().second;
    cout << ans << " ";

    for (int i = k; i < n; i++)
    {
        pq.push({arr[i], i});
        while( !pq.empty() && pq.top().second <= i-k){
            pq.pop();
        }

        ans = pq.top().second;
        cout << ans << " ";
    }

    // solve the same problem using deque
    deque<pair<int,int>> dq;
    return 0;
}