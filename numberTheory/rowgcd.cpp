// You are given two positive integer sequences a1,…,an
//  and b1,…,bm
// . For each j=1,…,m
//  find the greatest common divisor of a1+bj,…,an+bj
// .

// Input
// The first line contains two integers n
//  and m
//  (1≤n,m≤2⋅105
// ).

// The second line contains n
//  integers a1,…,an
//  (1≤ai≤1018)
// .

// The third line contains m
//  integers b1,…,bm
//  (1≤bj≤1018)
// .

// n,m : 4  4
// ai : 1 25 121 169
// bi : 1 2 7 23

// for all j = 1 to n
// gdc( a1+bj, a2 + bj...   , an + bj) ,

// gcd(3,15) = gcd(3,12)
// gcd(a,b) = gcd(a, b - a)

// gcd(a1+bj, a2-a1, a3-a1 .. an-a1)

// a % b
// b,a = > a % b, b

#include <bits/stdc++.h>
using namespace std;

long long gcd(long long b, long long a)
{
    while(b){
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> b(m);

    long long common = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        common = gcd(common, abs(a[i] - a[0]));
    }
    vector<long long> ans(m, 0);
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
        ans[j] = gcd(a[0] + b[j], common);
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}