#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin >> c[i];

    // n <= 100
    // ci <= 1000
    set<int> s;
    s.insert(0);

    for(int i=n-1;i>=0;i--){
        set<int> s1 = s;
        for(auto it : s1){
            int newValue = it+c[i];
            s.insert(newValue);
        }
    }
    s.erase(0);

    cout << s.size() << endl;

    for(auto it : s){
        cout << it << " "; 
    }
    return 0;
}