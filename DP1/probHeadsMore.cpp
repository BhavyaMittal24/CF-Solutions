// Let 
// N be a positive odd number.

// There are 
// N coins, numbered 
// 1,2,…,N. For each 
// i (
// 1≤i≤N), when Coin i is tossed, it comes up heads with probability 
// pi
// ​
// and tails with probability 
// 1−pi
// ​
// Taro has tossed all the 
// N coins. Find the probability of having more heads than tails.

// Constraints
// N is an odd number.
// 1≤N≤2999
// p 
// i
// ​
//   is a real number and has two decimal places.
// 0 <pi <1


// N is 3,5,.. 


// // n coins n tossess

// // for ith coin , we have p as prob of head
// // 1 - p as prob of tail

//  1  2    3     4 ...  N
// 0.5 0.7  0.8   0.1

// P(heads) for each coin = pi

// count of heads =X

//  n is odd, 5/2 :  > 2 : even number : 

// P(X > N/2)

// c >= ceil(N/2);

// P(X= c ) + P(X = c+1) + P(X = c + 2 ) + ... P(X = n)


// select all possible c and have their sum of products +  select any c+1 from n and have pi multiplied

// n n/2 * n/2 + ..  * n/2
// //

// // if i coins are tossed, then prob of getting all heads : Product of pi for = p1*p2 .... pi

//  p1 p2  ... [pi |  pi+1 ...  pn

// suffix : [pi pi+1  ..  pn]

// prob of getting >= some number of heads  from coins i to n 

//           [i  i+1               ]
// p(no of heads >= h) from a set of coins i to n

//  dp(heads,i) : prob of 

// for the ith coin : 
//                 getting a head               getting a tail
// dp[heads , i] = pi * dp[heads-1, i+1]     +   (1-pi) * dp[heads, i+1]


// final ans : ceil(n/2)

// dp[ceil(n.2), 1];  prob of getting ceil(n/2) or more heads from index 1 to n-1




// base case 

// // possible coins left : > no of min heads
// if(n-i+1 >  min no of heads) return 0;

// if(n-i+i == min no of heads) product of pi from i to n
//  prob multiply from n-1 to 1





// prob of 
// dp[number of heads > n] : 

#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  vector<double> p(n+1,0);
  // p of getting head for each coin i

  for(int i=1;i<=n;i++) cin >> p[i];

  vector<long double> prob_mul_heads(n+1);
  // product of prob from i  to n
  // prob_mul[i] = pi * pi+1 ... * pn
  vector<long double> prob_mul_tails(n+1);
  prob_mul_heads[n] = p[n];
  prob_mul_tails[n] = 1- p[n];

  for(int i=n-1;i>=1;i--){
   prob_mul_heads[i] = p[i] * prob_mul_heads[i+1];
   prob_mul_tails[i] = ( 1- p[i] )* prob_mul_tails[i+1];
  }
  
  int x = n/2 +1;

  vector<vector<long double>> dp(n+1, vector<long double>(n+1,0));

  // dp[i][heads] = prob of getting min no of heads >= heads from coins i to n
  
  // dp[i][heads] = pi * dp[i+1][heads-1] + 1-pi * dp[i+1][heads]

  for(int i=1;i<=n;i++) dp[i][0] = prob_mul_tails[i];
  
  for(int i = n; i>=1;i--){
       
     for(int heads = 1; heads <= n; heads++){
          
          // no of available coins  < min heads
	  if(n-i+1 < heads) {
             dp[i][heads] = 0;
             continue;
          } 
          
          // all coins should be heads
          if( n-i+1 == heads) {
             dp[i][heads] = prob_mul_heads[i];
                continue;
          }
         
          long double head = p[i] * dp[i+1][heads-1];
          long double tail = (1-p[i]) * dp[i+1][heads];
          dp[i][heads] = head + tail;
     }
     
  } 
  
  
 // 1    2       3
 // 0.3  0.7     0.2


// dp[1][2] = 0.3*dp[2,1]  

// dp[2,1] = 0.7*dp[][]
// dp[2][2] 

 long double ans = 0;

 for(int i=n/2+1;i<=n;i++) ans += dp[1][i];
    cout << fixed << setprecision(10) << ans << endl;
 return 0;
 
}

