#include<bits/stdc++.h>
using namespace std;


int main(){

    string s;
    cin >> s;

    string reducedS;

    vector<int> bIndex;
    int cnt = 0;

    for(int i = 0 ; i < s.length() ; i ++){
        if( s[i] == 'a' || s[i] == 'b'){
            reducedS += s[i];
            if(s[i] == 'b') bIndex.push_back(cnt);
            cnt ++;
        } 
    }


    vector<int> aSegments;

    int idx = bIndex.size() ? bIndex[0] : reducedS.length();
    aSegments.push_back(idx);

    for(int i = 1 ; i < bIndex.size() ; i ++){
        aSegments.push_back(bIndex[i] - bIndex[i-1] - 1);
    }

    if( bIndex.size() > 0){
        aSegments.push_back(reducedS.length() - 1 - bIndex.back());
    }

    const long long mod = 1e9 + 7;
    long long ans = 1;

    for(auto segment : aSegments){
        ans = (ans * 1ll*(segment + 1 ) ) % mod;
    }
    ans --;

    cout << ans << endl;
    return 0;
}