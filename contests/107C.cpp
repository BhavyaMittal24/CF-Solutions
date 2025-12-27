#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n ;

    vector<int> arr(n);

    vector<int> odd;
    vector<int> even;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0 ; i < n ; i++){
         if( arr[i] % 2 ){
            odd.push_back(arr[i]);
        }
        else {
            even.push_back(arr[i]);
        }
    }

    // even and odd arrays

    // purely an even array : alwaysd the sum would be 0
    if( odd.size() == 0) {
        for(int i = 1; i <= n ; i ++){
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }

    // purely an odd array : always sum would be alernating between max odd value amnd 0
    if( even.size() == 0){
        for(int i = 1 ; i <= n; i++){
            if( i % 2 == 0){
                cout << "0" << " ";
            }
            else {
                cout << odd.back() << " ";
            }
        }
        cout << endl;
        return;
    }

    // when we have non zero odds and ones "
    int maxOp = even.size() + 1;

    int highestOdd = odd.size() -1 ;

    int lowestOdd = 0;
    int highestEvenIndex = even.size() - 1;
    // as soon as we exceed the max goldem number : if (no of odd >=3) fine : 
    // we alternate : ans - even[lowestEven]
    // ans + even[lowestEven]
    
    // as soon as no of odd < 3 : we return 0;
    vector<long long> ans;

    bool subtractLowestEven = 1;
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){

        if( i < maxOp){
            if( i == 0) sum += odd[highestOdd];
            else sum += even[highestEvenIndex--];
            ans.push_back(sum);
        }

        // when the maxOp is over
        else {
            int noOfOdds = highestOdd - lowestOdd + 1;
            // if we dont have more than 3 odds, : as 2 odds can be used to make one operation  
            if( noOfOdds <=2) {
                ans.push_back(0);
            }

            else {
                // when we have >= 3 odds left and we use up 2 operations tom kae these 2 odds and 0 and remove the smallest even number from sum 
                if(subtractLowestEven){
                    sum -= even[0];
                    subtractLowestEven = 0;
                }
                // when these odds are still left >=3 and now we can add them to sum : total of +2 operations and same sum
                else {
                    sum += even[0];
                    subtractLowestEven = 1;
                    lowestOdd +=2;
                }
                ans.push_back(sum);
            }
        }
    }

    for(int i = 0 ; i < ans.size() ;i ++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}