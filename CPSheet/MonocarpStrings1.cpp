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
        a_val = -1;
        b_val = 1;
        sum = b - a;
    }

    if (a == b)
    {
        cout << 0 << endl;
        return;
    }

    // map storing the prefux sum to the index : l-1
    // i based indexing
    unordered_map<int,int> mp;
    mp[0] = 0;

    int min_len = n+1;
    int curr_sum = 0;
    for(int i=1;i<=n;i++){
        if(s[i-1] == 'a') curr_sum += a_val;
        else curr_sum += b_val;

        if(curr_sum == sum){
            min_len = min(min_len, i);
        }

        if(mp.find(curr_sum -sum) != mp.end()){
            min_len = min(min_len, i - mp[curr_sum-sum]);
        }

        mp[curr_sum] = i;
    }

    min_len = (min_len >= n) ? -1 : min_len;
    cout << min_len << endl;

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
// d = 3

//4
// aaaa


// 5 

// a a b a a
// 1 2 1 2 3
// a = 4
//b = 1

// 8
// bbbbabbb