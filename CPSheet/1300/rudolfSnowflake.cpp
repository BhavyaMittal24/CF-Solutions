#include<bits/stdc++.h>
using namespace std;


void solve(){

    long long val;
    cin >> val;

    // picked up the total number of nodes in a snowflake : 
    // for some k > 1 : k = 2 to k = x : the no of nodes = 1 + k + k^2 +... k^..
    // for max k, the expression is 1 + k + k^2 <= 1e6
    // k goes from 2 to 1e3

    // and the maxium terms can be kn - 1/ k -1 where n = 20 for minimum k

    // monotonic : the expression  : min no of nodes(k) >= value
    //          FFFFFFFFFFFFFFFFFFTTTTTTTTTTTTTTTT
    // WHEN MIN NO OF NODES (k) == value : break
    // min no mof nodes(k) < value : we try to chec kfor all possible lengths : and compare: we go up : oncrease the value of k
    // 

    int low = 2;
    int high = 1000;

    bool isPossible = false;
    while(low <= high){

        int mid = low;

        long long minValue = 1 + 1ll*mid + 1ll*mid*mid;
        if( minValue == val){
            isPossible = true;
            break;
        }

        else if( minValue > val){
            break;
        }

        else {
            // check for all possible combinations : when minValuw < val

            long long extra = mid * mid;
            for(int i = 3; i <= 20; i ++){

                extra = 1ll*extra * mid; 

                minValue += extra;

                if( minValue > val) break;

                if(minValue == val){
                    isPossible =true;
                    break;
                }
            }

            if(isPossible) break;
        }
        
        low++;
    }

    (isPossible) ? cout << "YES\n" : cout << "NO\n";
    return; 
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t ;

    while(t--){
        solve();
    }
    return 0;
}