// get the SPF for all the numbers between 1 to 1e5

#include<bits/stdc++.h>
using namespace std;

int maxN = 1e5;

// usedPrimes[prime] = { used or not, which collider it belongs to}
vector<pair<int,int>> usedPrimes(maxN+1,{0,-1});

int colliders = 0;

vector<int> isColliderOn(maxN+1,0);
vector<int> isPrime(maxN+1,1);
vector<int> spf(maxN+1,1e9);

// Shortest prime factor for a number I
// spf[I] 
// eg spf[7] = 7;

// spf[4] = 2
// isPrime[I] = 1 : yes
// 0 = No composite number


// usedPrimes[i] = 1, alredy in use


void sieve(){
   spf[1] = 1;
   for(long long i=2;i<=maxN;i++){
        if(isPrime[i] == 1) {
            spf[i] = i;
            for(long long j=i*i;j<=maxN;j+=i) {
                isPrime[j] = 0;
                spf[j] = min(spf[j], int(i));
	        } 
        }
    }
    return ;
}

// check if there exists a gcd for i, 
// by checking if there is some prime for i which is aleady used.

int checkIfCoPrime(map<int,int> mpi){
   for(auto it : mpi){
      int prime = it.first;
      int pow = it.second;
      if(pow >= 1 && usedPrimes[prime].first == 1 && usedPrimes[prime].second != -1){
         return usedPrimes[prime].second;
      }
   }
   // no primes of i are being under use
   return -1;
}

void setUsedPrimes(map<int,int> mpi, int i){
   for(auto it : mpi){
     // whether used or not, which collider it belongs to
      usedPrimes[it.first] = {1,i};
   }
}

void resetUsedPrimes(map<int,int> mpj, int j){
    for(auto it: mpj){
       int prime = it.first;
       if(usedPrimes[prime].first == 1 && usedPrimes[prime].second == j){
          usedPrimes[prime] = {0,-1};
       }
    }
}
void activate(int i){
   map<int,int> pf;
   int x = i;

   if(isColliderOn[i]){
	cout << "Already on" << endl;
	return;
   }
   while(x != 1){
	int prime = spf[x];
        int cnt =0;
        while(x % prime == 0){
           x = x/prime;
           cnt++;
	}
        pf[prime] += cnt;
   }
   // check if not a conflict with anyone

   int conflictCollider = checkIfCoPrime(pf);
   if(colliders == 0  || conflictCollider == -1){
      setUsedPrimes(pf,i);
      isColliderOn[i] = 1;
      colliders++;
      cout << "Success" << endl;
   } 
   else if( conflictCollider != -1){
    	cout << "Conflict with " << conflictCollider << endl;
   }
}

void deactivate(int j){
  if(isColliderOn[j] == 0){
     cout << "Already off" << endl;
     return;
   }
   
   int x = j;
   map<int,int> pf; 
   while(x != 1){
	int prime = spf[x];
        int cnt =0;
        while(x % prime == 0){
           x = x/prime;
           cnt++;
	}
        pf[prime] += cnt;
   }
   resetUsedPrimes(pf,j);
   isColliderOn[j] =0;
   colliders--;
   cout << "Success" << endl;   
 
}

int main(){
   int n, m;
   cin >> n >> m;
   sieve();
//    vector<string> query(m); 
//    for(int i=0;i<m;i++){
//         cin >> query[i];
//    }
   
   for(int i=0;i<m;i++){
         char op_char;
        int num;
        cin >> op_char >> num; // Reads the operator and the number separatel;
        //int req = stoi(num);
        if(op_char == '+') {
           activate(num);
        }
        else {
          deactivate(num);
        }
   }
    return 0;

}