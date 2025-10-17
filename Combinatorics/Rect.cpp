#include<bits/stdc++.h>
using namespace std;

 const long long mod = 1e9+7;
    vector<long long> f;
    vector<long long> invf;
    const long long N = 100000;
    
    long long exp( long long b, long long e){
        long long ans = 1;
        b  = b ;
        while(e > 0){
            if(e & 1){
                ans = (ans * b);
            }
            b = (b * b) ;
            e = e >> 1;
        }
        return ans;
    }

    void fact(){
        f.resize(N+1,1);
        invf.resize(N+1,1);
        for(long long i=2;i<=N;i++){
            f[i] = ( i* f[i-1] ) % mod;
        }
        invf[N] = exp(f[N], mod-2);  
        for(long long i=N-1;i>=1;i--){
            invf[i] =  ( (i+1) * invf[i+1] ) % mod;
        }  
    }

    int main(){
        int n;
        int m;
        cin >> n >> m;

        fact();

        int cnt = 0;
        vector<vector<int>> arr(n, vector<int>(m,0));

        vector<long long> row(n,0);
        vector<long long > col(m,0);

        for(int i=0;i<n;i++){
            long long cnt = 0;
            for(int j=0;j<m;j++){
                cin >> arr[i][j];
                if(arr[i][j] == 1){
                    cnt++;
                }
            }
            row[i] = cnt;
        }

        for(int j=0;j<m;j++){
            long long cnt = 0;
            for(int i=0;i<n;i++){
                if(arr[i][j] == 1){
                    cnt++;
                }
            }
            col[j] = cnt;
        }

        long long ans = 0;

        for(int i=0;i<n;i++){
                ans = (ans + exp(2, row[i]) -1 );
                ans = ans + exp(2, m - row[i]) -1;
        }
        for(int j=0;j<m;j++){
                ans = (ans + exp(2, col[j]) -1 );
                ans = ans + exp(2, n - col[j]) -1;
        }

        ans = ans - (1ll* m*n);
        cout << ans << endl;
        return 0;
    }