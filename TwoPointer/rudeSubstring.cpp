#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long c;
    cin >> n >> c;
    string s;
    cin >> s;
    int left = 0;
    int right = 0;
    int maxLength = 0;

    long long a =0;
    long long b = 0;
    long long countRude = 0;
    while(right < n){
        if(s[right] == 'a') a++;
        if(s[right] == 'b'){
            b++;
            countRude += a;
        }
        while(left<=right && countRude > c){
            if(s[left] == 'b') b--;
            if(s[left] == 'a') {
                a--;
                countRude -= b;
            }
            left++;
        }
        if(countRude <=c){
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
    }
    cout << maxLength << endl;
    return 0;
}