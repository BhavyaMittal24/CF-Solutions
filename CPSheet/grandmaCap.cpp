#include<bits/stdc++.h>
using namespace std;

int findMinOp(char ch, string & s){

    int i= 0;
    int j = s.length() - 1;

    int minOp = 0;

    // for the character ch, is it possible to remove some occurences and the string can become palindromic

    while( i <= j) {

        if(s[i] == s[j] ){
            i++;
            j--;
            continue;
        }

        else if(s[i] == ch && s[j] != ch){
            i++;
            minOp++;
            continue;
        }

        else if(s[i] != ch && s[j] == ch){
            j--;
            minOp++;
            continue;
        }
        else if( s[i] != ch && s[j] != ch && s[i] != s[j]){
            return -1; // impossible
        }
    }

    return minOp;
}

void solve(){
    int n;
    string s;

    cin >> n;
    cin >> s;

    // take in the input n and the string s;

    // each character/ letter can be selected and any occurences are removed
    int ans = 1e9;

    // if not possible to make string  a palindrome by removing only one character's occurences : -1 Impossible 

    set<char> uniqueChars;

    for(int i = 0; i < s.length() ; i++){
        uniqueChars.insert(s[i]);
    }
    // len(s) * log(26)

    // select each character and find min operations to remove

    for(auto ch : uniqueChars){

        int op = findMinOp(ch, s);

        if( op != -1) ans = min(ans, op); 
    }

    if(ans == 1e9) ans = -1;

    cout << ans << "\n";
    return;
}

int main(){

    std :: ios_base ::sync_with_stdio(false);
    cin.tie(NULL); // output buffer : acts as intermediate storign space between the actual print console screen
    // when we do cin, whatever is present in the buffer is flushed out. We dont tie that now with cin. Niw even if we do cin, nithin would be flushed out

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}