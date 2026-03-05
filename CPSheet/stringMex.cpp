#include<bits/stdc++.h>
using namespace std;

set<string> sortedSet;

void getString(int idx, string &s){

    if( idx >= 3){
        if(s != "") {
            sortedSet.insert(s);
            cout << s << endl;
        }
        return;
    }

    for(int i = 0 ; i <= 26; i ++){

        if(i == 0) {
            getString(idx+1, s);
        }

        char ch = 'a' + i - 1;
        s.push_back(ch);
        getString(idx+1, s);
        s.pop_back();
    }

}
void solve(){

    // find all the substrings of length <= 3
    // vector<string> st;


    int n;
    string s;
    cin >> n >> s;
   
    set<string> isPresent;
    for(int len = 1; len <= 3; len ++){
        // len = i
        
        for(int i = 0; i <  n ; i ++){

            string str = "";
            for(int j = i; j < i + len && j < n; j ++){
                str += s[j];
                cout << str << endl;
            }
           
            isPresent.insert(str);
        }

    }

    // set of all possible substrings of length <= 3;
    string mex ;
    for(string s : sortedSet){

        cout << s << " " << endl;
        if(isPresent.count(s) == 0) {
            mex = s;
            break;
        }

    }
    cout << mex << "\n";
    return;
}



int main(){

    
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    string str;
    getString(0, str);

    while(t--){
        solve();
    }

    return 0;
}