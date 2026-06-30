#include<bits/stdc++.h>
using namespace std;

/*
*/
int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> st;
    // cnt distinct characters : all unique pokemons
    for(int i = 0; i < n; i++){
        st.insert(s[i]);
    }

    // find the shortest subarray where the cnt of all unqieu elenmetsn is st.size()
    int l = 0;
    int r= 0;

    int minLen = n;
    map<char, int> mp;
    while( r < n){
        mp[s[r]] ++;

        while(l <= r && mp.size() >= st.size()){
            
            minLen = min(minLen, r-l +1);
            mp[s[l]]--;
            if(mp[s[l]] == 0) {
                mp.erase(s[l]);
            }
            l++;
        }
        r++;
    }
    cout << minLen << "\n";
    return 0;
}