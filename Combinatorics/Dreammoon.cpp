#include<bits/stdc++.h>
using namespace std;

long long factorial[11];

void setFactorial(){
    factorial[0] = 1;
    for(int i=1;i<=10;i++){
        factorial[i] = i * factorial[i-1];
    }
}
long double choose(int n, int r){

    long double ans = 1.0;
    ans = 1.0*factorial[n];

    long double den = 1.0*factorial[n-r] * factorial[r];
    ans = 1.0*ans / den;   
    return ans;
}
int main(){
    string s1;
    string s2;

    cin >> s1 >> s2;

    setFactorial();
    
    if(s1.length() != s2.length()) {
        cout << 0 << endl;
        return 0;
    }

    int cntPlusS1 = 0;
    int cntMinusS1 = 0;

    int cntPlusS2 = 0;
    int cntMinusS2 = 0;

    int cntQ = 0;
    for(int i=0;i<s1.length();i++){
        if(s1[i] == '+') cntPlusS1++;
        else if(s1[i] == '-') cntMinusS1++;
     }


    for(int i=0;i<s2.length();i++){
        if(s2[i] == '+') cntPlusS2++;
        else if(s2[i] == '-') cntMinusS2++;
        else cntQ++;
    }

    if(cntQ == 0){

        if( (cntMinusS1 == cntMinusS2) && (cntPlusS1 == cntPlusS2)) {
        cout << setprecision(8) << 1 << endl;
        }
        else {
            cout << setprecision(8) << 0 << endl;
        }
        return 0;
    }

    else {
        if(cntMinusS2 > cntMinusS1 || cntPlusS2 > cntPlusS1){
            cout << setprecision(8) << 0 << endl;
            return 0;
        }

        int diffMinus = cntMinusS1 - cntMinusS2;
        int diffPlus = cntPlusS1 - cntPlusS2;

        if( cntQ == (diffMinus + diffPlus)){

            long double ans = choose(cntQ, diffMinus);
            long double den = 1;

            for(int i=1;i<=cntQ;i++){
                den = den * 2;
            }
            ans = ans/den;
            cout << setprecision(14)  << ans << endl;
        }
    }

    return 0;
}