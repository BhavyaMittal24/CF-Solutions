#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> freq;
    set<char> distinctChars;
    for(int i=0;i<n;i++){
        distinctChars.insert(s[i]);
    }
    int k = distinctChars.size();
    int left = 0;
    int right = 0;
    int minLength = INT_MAX;
    for(int right = 0; right < n; right++){
        freq[s[right]]++;
        while(freq.size() >=k){
            minLength = min(minLength,right-left+1);
            freq[s[left]]--;
            if(freq[s[left]] == 0){
                freq.erase(s[left]);
            }
            left++;
        }
    }
    cout << minLength << endl;
    return 0;
}