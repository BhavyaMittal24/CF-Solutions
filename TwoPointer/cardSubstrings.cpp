#include<bits/stdc++.h>
using namespace std;

bool isPossibleToMakeSubstringFromT(vector<int> &freqS, vector<int> &freqT){
    for(int i=0;i<26;i++){
        if(freqT[i] < freqS[i]) return false;
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    vector<int> freqS(26,0);
    vector<int> freqT(26,0);
    for(int i=0;i<m;i++){
        freqT[t[i]-'a']++;
    }
    int left = 0, right = 0;
    long long countGoodSubstrings = 0; // can be max n*n+1/2 n ~ 1e5
    while(right < n){
        freqS[s[right]-'a'] ++;
        while(left <=right && !isPossibleToMakeSubstringFromT(freqS, freqT)){
            freqS[s[left]-'a']--;
            left++;
        }
        countGoodSubstrings += (right-left+1);
        // for each right, i see that the left is the most left such that subsarray is good
        right++;
    }
    cout << countGoodSubstrings << endl;
    return 0;
}