#include<bits/stdc++.h>
using namespace std;

// form the set of strings of a given length 3

// set of all possible strings lexogiraphically which can me made o upto length 3
set<string> st;

void formSet(int idx, string &s){

    if(idx >= 3){
        if(s != "") st.insert(s);
        return;
    }

    for(int i = 0; i<= 26; i ++ ){
        if( i == 0){
            formSet(idx+1, s);
        }
        else {
            s += 'a' + (i - 1);
            formSet(idx+1, s);
            s.pop_back();
        }
    }
}


bool checkSubStringPresent(string &sub, string &s){

    string temp = "";
    // fixed sized window of size sub.length()

    for(int i = 0; i < s.length(); i ++){

        // calls a specific operator for character addition to a string.
        temp += s[i];

        // more than sub.length() " more than k : >= k : sizeod window"
        if( i >= sub.length()){
            temp = temp.substr(1); // remove the first character
        }

        if( i >= sub.length() - 1){
            if(temp == sub) {
                return true;
            }
        }
    }

    return false;
}

void solve(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    string subString = "";

    set<string> setofAll = st;

    // ffinding all possible substrings upto length 3

    for(int len = 1; len <= 3 ; len++){

        for(int i = 0; i < s.length() - len; i ++){
            string subStr = s.substr(i,len);

            // preset in the set
            if(setofAll.find(subStr) != setofAll.end()){
                setofAll.erase(subStr);
            }
        }
    }

    string ans = "";

    ans = *setofAll.begin();

    cout << ans << "\n";
    // for(char ch = 'a' ; ch <= 'z' ; ch ++){

    //     subString = ch;
    //     if(!checkSubStringPresent(subString,s)) {
    //         cout << subString << " \n";
    //         return;
    //     }
    // }


    // // for len 2

    // subString = "";
    // // to_string(123) : converts the number 1234, 999 into a string
    // // stoi("123") : converts "123 " into an integer number : 
    // for(int i = 0; i <= 25; i ++){
    //     for(int j = 0; j <= 25; j ++){
    //         char ch1 = 'a' + i;
    //         char ch2 = 'a' + j;
           
    //         subString = string("") + ch1 + ch2;
    //         if(!checkSubStringPresent(subString,s)) {
    //             cout << subString << " \n";
    //             return;
    //         }
    //     }
    // }

    // subString= "";

    // for(int k = 0; k <= 25; k ++){
    //     for(int i = 0; i <= 25; i ++){
    //         for(int j = 0; j <= 25; j ++){
    //             char ch0 = 'a' + k;
    //             char ch1 = 'a' + i;
    //             char ch2 = 'a' + j;
    //             subString = string("") + ch0 + ch1 + ch2;

    //             if(!checkSubStringPresent(subString,s)) {
    //                 cout << subString << " \n";
    //                 return;
    //             }
    //         }
    //     }
    // }

    return;
}
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string s="";
    formSet(0,s);

    for(auto str : st){
        cout << str << "\n";
    }
    while(t--){
        solve();
    }

    return 0;
}