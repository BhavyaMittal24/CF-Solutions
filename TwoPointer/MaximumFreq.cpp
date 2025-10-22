#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);


    // for an array, find the length og longest subarray which has the freq of the max occuring element as the freq of the min occuring element in thr entire array
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    int lowestFreq = n;
    for (auto it : mp)
    {
        lowestFreq = min(lowestFreq, it.second);
    }

    // find the longest subarray that has max freq (freq of most frew element) = lowestFreq

    int maxLen = 0;

    int left = 0;
    // stores freq, element
    // maxFreq;

    // find the length of longest subarray with max freq = lowestFreq
    // search for longest subartay with frq <= lowestFreq
    // cant have max freq from a pq, set. no ds will give me the max freq in 0(1).
    int maxFreq = 0;
    map<int, int> slidingMap;
    map<int,int> freqCount;


    // main tainihn two maps : two gwt the maxFreq in the current window.
    // for that, when I remove the element from left, i basically use a map contaninh count of elements which contribute to a given frequency.
    // if the freqCount of the freq from the left element becomes 0, the nmaxFreq may change.
    // if oldFreq from left element was maxFeq and now the count for the oldFreq is -, maxFreq reduces by 1.
    // othereose in case count of oldFreq from the left is still > 0 some other element has that freq
    for (int right = 0; right < n; right++)
    {
        int element = arr[right];
        int oldFreq = slidingMap[element];
        if(oldFreq > 0){
            freqCount[oldFreq]--;
            if(freqCount[oldFreq] == 0){
                freqCount.erase(oldFreq);
            }
        }
        slidingMap[element]++;
        freqCount[oldFreq + 1]++;

        maxFreq = max(maxFreq, slidingMap[element]);
        // 1-> 3, 2->2 , 
        while (left <= right && maxFreq > lowestFreq)
        {
            element = arr[left];
            oldFreq = slidingMap[element];
            slidingMap[element]--;
            freqCount[oldFreq]--;
            freqCount[oldFreq - 1]++;
            if(freqCount[oldFreq] == 0){
                freqCount.erase(oldFreq);
                if(maxFreq == oldFreq) maxFreq = oldFreq-1;
            }
            left++;
        }
        if (maxFreq == lowestFreq)
        {
            maxLen = max(maxLen, right - left + 1);
        }
    }
    cout << maxLen << endl;

    return 0;
}