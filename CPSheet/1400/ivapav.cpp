#include <bits/stdc++.h>

using namespace std;

void solve(){

    int n;
    cin >> n;

    // bitmasks : ai  <= 1e9 // 32 bits
    // n <= 2e5
    
    // arr[i] -> 32 size array storign the cnt of 1s for each bit pos : no of bitpos set till the prefix

    vector<vector<int>> pre(n+1, vector<int> (32,0));

    // for eah numner : 1 to index : we have 32 bit positions : 1e9 : 2^32 - 1 : 31 is themsb

    vector<int> arr(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> arr[i];

        for(int bitNumber = 0; bitNumber <= 31; bitNumber ++){

            pre[i][bitNumber] = pre[i-1][bitNumber];
            if( (arr[i] & (1 << bitNumber) ) != 0 ){
                // bitNumber is sset
                pre[i][bitNumber]++;
            } 
        }
    }

    int q;
    cin >> q;

    vector<pair<int,int>> queries(q);
    for(int i = 0; i < q; i ++){
        int l, k;
        cin >> l >> k;
        queries[i] = {l,k};
    }

    for(int i = 0; i < q; i ++){
        int l = queries[i].first;
        int k = queries[i].second;

        int low = l;
        int high = n;

        int ans = -1;
        // find the greatest r such that (l-1,r) >= k

        while(low <= high){
            int mid = (low + high)/2;

            // find the number in the a& from l to r

            int x = 0;
            for(int i = 0; i < 32; i ++){
                
                // form the number betwrrn l to r : by umultiple ANDs
                int cntSetBitsForPosI = 0;
                cntSetBitsForPosI = pre[mid][i] - pre[l-1][i];
                if( cntSetBitsForPosI == mid - l + 1 ) x = x | (1 << i);
            }

            // ..l .......r >= k .. dec function
            if( x >= k){
                ans = mid;
                low = mid+1;
            }
            else {
                // x < k
                high = mid-1;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {

    ios_base :: sync_with_stdio(false);
cin.tie(NULL);	// cin.sync_with_stdio(false); // fast IO

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

/*
Time Complexity (TC): O(n * logA + q * logn * logA)
Space Complexity (SC): O(n * logA)
*/
