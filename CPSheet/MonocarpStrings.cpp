// Your task is to determine the minimum number of consecutive letters from the string s
//  that need to be removed so that the number of letters 'a' and 'b' in the resulting string becomes equal. If it is necessary to remove all letters from the string s
//  (i.e., make it empty), report this.

// 5
// 5
// bbbab
// 6
// bbaaba
// 4
// aaaa
// 12
// aabbaaabbaab
// 5
// aabaa

// if I have to remove the entire string remove all, then -1

// bbbab : b = 4, a = 1  : a-b such that b don't become 0

// cnta == cntb : 0

// cnta == 0 || cntb == 0 return -1;

// bbbab

// a = 7, b = 5

// a-b = 2

// shortest subarray which has sum = a-b
// aabbaaabbaab

// 1 1 0 0 1 1 1 0 0 1 1 0

// aabaa

// length of the  shortest subarray with sum >= k

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s = "";
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s += c;
    }

    int a = 0;
    int b = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a') a++;
    }

    b = n - a;

    int b_count = 0;
    int a_count = 0;
    int sum = 0;
    int a_val = 0;
    int b_val = 0;
    if (a > b)
    {
        a_val = 1;
        sum = a - b;
        b_val = -1;
    }
    else
    {
        a_val = 1;
        b_val = 1;
        sum = b - a;
    }

    if (a == b)
    {
        cout << 0 << endl;
        return;
    }

    // find the min subarray with sum >= k;
    int right = 0;
    int left = 0;

    int curr = 0;
    int minLen = n + 1;
    while (right < n)
    {
        curr += (s[right] == 'a') ? a_val : b_val;
        b_count = b_count + (s[right] == 'b') ? 1 : 0;
        a_count = a_count + (s[right] == 'a') ? 1 : 0;
        while (curr >= sum && left <= right)
        {
            if (curr == sum && b_count < b && a_count < a){
                minLen = min(minLen, right - left + 1);
            }
            curr -= (s[left] == 'a') ? a_val : b_val;
            b_count = b_count - (s[right] == 'b') ? 1 : 0;
            a_count = a_count - (s[right] == 'a') ? 1 : 0;
            left++;
        }
        right++;
    }

    int len = (minLen == n + 1) ? -1 : minLen;
    cout << len << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


//aaabaaaaaba

// 1 1 1 -1 1 1 1 1 1 -1 1

// a = 9
// b = 2 

// abaaabababa

// 1 -1 1 1 1  -1 1 -1 1 -1 1

//a = 7
// b = 4
// d = 311