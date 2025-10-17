#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long binaryExp(long long base, long long exp)
{
    long long res = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp >> 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pf(n);
    for (int i = 0; i < n; i++)
        cin >> pf[i].first >> pf[i].second;

    long long div = 1;
    long long div_prod = 1;
    long long div_sum = 1;
    long long div1 = 1;

    for (int i = 0; i < n; i++)
    {
        int p = pf[i].first;
        int k = pf[i].second;
        long long numerator = (binaryExp(p, k + 1) - 1 + mod) % mod;
        long long inv = binaryExp(p - 1, mod - 2) % mod;

        long long term_sum = (numerator * inv) % mod;

        int power_sum = k * (k + 1) / 2;
        int term = binaryExp(p, power_sum);
        div_sum = (div_sum * term_sum) % mod;
        div_prod = div_prod * binaryExp(term, div1) % mod;
        div = (div * (k + 1)) % mod;
        div1 = div1 * (k + 1) % (mod - 1);
    }

    cout << div << " " << div_sum << " " << div_prod << endl;
    return 0;
}