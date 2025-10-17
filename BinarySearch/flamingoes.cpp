// Flamingoes

// N cages : I to N/
//  each cage : cage[i] has flamingos    0<=  <= 1000
//  N coins are present : N queries :
//  In each query : L to R . total no of flamingos in all cages from L to R
//  //  L <R

// N queries : 6 quries
// // guess array using subarray sum
// // 1 4 4 6 7 8
// [2,3] = 8 :
// [1,2] = 5 :
// [1,3] = 9 : 4
// [1,4] = 15 : 6
// [1,5] = 22 : 7
// [1,6] = 30 : 8

// in n queries, we got the n-1 elements, can find 2nd element by subtracting all from total :
#include <bits/stdc++.h>
using namespace std;

vector<int> toGuess = {2, 3, 4, 5, 6, 7, 8};
bool testing = false;;

int findSum(int l, int r)
{
  int sum = 0;
  for (int i = l; i <= r; i++)
  {
    sum += toGuess[i];
  }
  return sum;
}

int ask(pair<int, int> &range)
{
  int l = range.first;
  int r = range.second;

  if (testing)
  {
    int response = findSum(l - 1, r - 1);
    return response;
  }
  else
  {
    int response;
    cout << "? " << l << " " << r << endl;;
    cin >> response;
    return response;
  }
}
int main()
{
  // number of queries/coins and number of cages
  //  2<=n <= 1e3
  int n;
  cin >> n;

  // pair of pairs and values
  vector<pair<int, int>> queries(n);
  queries[0] = {2, 3};
  for (int i = 1; i < n; i++)
  {
    queries[i] = {1, i + 1};
  }

  int sum23 = 0;
  int sum13 = 0;
  int count = 0;
  int prefixSum = 0;
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
  {
    int subArraySum = ask(queries[i]);
    int element = subArraySum - prefixSum;
    prefixSum = subArraySum;
    if (i == 0)
    {
      sum23 = subArraySum;
      prefixSum = 0;
    }

    if (i >= 2)
    {
      if (i == 2)
        sum13 = subArraySum;
      ans[i] = element;
      count += element;
    }
    if (i == n - 1)
    {
      ans[0] = sum13 - sum23;
      ans[1] = subArraySum - count - ans[0];
    }
  }
  cout << "! ";
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}