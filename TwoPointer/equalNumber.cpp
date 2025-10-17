#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    map<int,int> freq;
    vector<int> a,b;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        b.push_back(x);
        freq[x]++;
    }
    // given in non-dec order

    int i=0;
    int j=0;
    long long cnt = 0;
    while(i<n && j<m){
        if(a[i] == b[j]){
            cnt +=freq[b[j]];
            i++;
        }
        else if(a[i] < b[j]){
            i++;
        }
        else j++;
    }
    cout << cnt << endl;
    return 0;
}