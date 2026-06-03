#include<bits/stdc++.h>
using namespace std;

long long formNumber(int digit, int n){

    long long num = 0;

    for(int i = 0; i < n; i ++){
        num = num * 10 + digit;
    }

    return num;
}

long long formNumbers(vector<int> &d){
    long long ans = 0;

    for(int i = 0; i < d.size() ; i ++){
        ans = ans * 10 + d[i];
    }
    return ans;
}

void solve(){

    long long a;
    int n;
    cin >> a >> n;

    long long an = a;
    int d1; 
    int d2;
    cin >> d1 >> d2;
    // a is long long : 1e18 : 18digits at most in the numbr
    vector<long long> possibleNumbers;

    vector<int> digits;

    // 342 : 
    while(a > 0){
        int d = a % 10;
        a = a /10;
        digits.push_back(d);
    }

    reverse(digits.begin(), digits.end());

    // smallest d+1 digit number
    // largest d1 dogit number
    long long ans1 = formNumber(d1, digits.size() + 1);
    long long ans2 = formNumber(d2, digits.size() - 1);

    possibleNumbers.push_back(ans1);
    if(digits.size() >= 2) possibleNumbers.push_back(ans2);

    vector<int> num;
    vector<int> num1;
    vector<int> num2;

    int dir1 = 0;
    int dir2 = 0;

    int i = 0;
    for( ; i < digits.size(); i ++)
    {

        // dir1 and dir2 : both exists : 
        if( i == 0 && d1 == 0 ){

            if(d2 > digits[i]){
                dir1 = -1; // 123 : 3
                // keep next elements minimum
                num.push_back(d2);
                break;
            }

            else if(d2 < digits[i]){

                dir2 = +1;
                num.push_back(d2);
                break;
            }
            else {
                num.push_back(d2);
                continue;
            }
        }

        else 
        {

            int diff1 = abs(d1 - digits[i]);
            int diff2 = abs(d2 - digits[i]);

            if(diff1 < diff2){

                if(d1 > digits[i]){
                    dir1 = -1;
                    num.push_back(d1);
                    break;
                }

                else if(d1 < digits[i]){
                    dir1 = +1;
                    num.push_back(d1);
                    break;
                }
                else {
                    // same is the digit:
                    num.push_back(d1);
                    continue; 
                }
            }

            else if(diff1 > diff2){

                if(d2 > digits[i]){
                    dir1 = -1;
                    num.push_back(d2);
                    break;
                }

                else if(d2 < digits[i]){
                    dir1 = +1;
                    num.push_back(d2);
                    break;
                }
                else {
                    // same is the digit:
                    num.push_back(d2);
                    continue; 
                }

            }
            else {

                // both are equal : difference : 
                // di - d1 = d2 - di
                dir1 = +1;
                dir2 = -1;
                num1.push_back(d1);
                num2.push_back(d2);
                break;
            }
        }
    }

    i++;

    if(dir1 != 0 && dir2 == 0){

        // only dir1 is set and dir2 is not set : only 1 number
        num1 = num;
        // the first point of difference or the numbers which are intially same and then when durn is set
        for( ; i < digits.size(); i++){
            
            if(dir1 == -1){
                num1.push_back(d1);
            }
                // dir1 == +1 : keep maximum elements
            else num1.push_back(d2);
        }
    }

    else if(dir1 != 0 && dir2 != 0){

        int num1Val = num1[0];
        int num2Val = num2[0];
        num1 = num;
        num2 = num;
        num1.push_back(num1Val);
        num2.push_back(num2Val);
        for(; i < digits.size(); i ++){

            if(dir1 == +1){
                num1.push_back(d2);
            }
            else {
                num1.push_back(d1);
            }
            
            if(dir2 == +1){
                num2.push_back(d2);
            }
            else {
                num2.push_back(d1);
            }
        }     
    }

    else if(dir1 == 0 && dir2 == 0){
        num1 = num;
    }
    // num1, num2..
    long long ans3 = formNumbers(num1);
    long long ans4 = formNumbers(num2);
    if(num1.size() ) possibleNumbers.push_back(ans3);
    if(num2.size()) possibleNumbers.push_back(ans4);

    long long minDiff = 1e18;

    for(auto num : possibleNumbers){
        //cout << num << "\n";
        cout << num << '\n';
        minDiff = min(minDiff, abs(num - an));
    }

    cout << minDiff << "\n";

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}