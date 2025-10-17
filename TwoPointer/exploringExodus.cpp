#include<bits/stdc++.h>
using namespace std;

// string s "001010101"
// need to find k+1 zeros and find min distance between farmer and the farthest cows

// an array of 0 indices, slide a window of size k+1, place the leftmost 0 at left, rightmost 0 at right, and median at l + (k+1)/2
// k+1 = 4
// 1 2 3 4
// med = 1 + 4/2 = 3
int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;// indices where 0s are present
    vector<int> pos;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            pos.push_back(i);
        }
    }
    
    // k+1 = 4 //
    // 0 to 3
    // med = 0 + (k/2) = 1
    int left =0;
    int med = 0;
    int ans = INT_MAX;
    for(int right=k;right<pos.size();right++){
        while( max(pos[right]-pos[med], pos[med]-pos[left]) > max(pos[right]-pos[med+1], pos[med+1]-pos[left]) ){
            med++;
        }
        ans = min(ans, max(pos[right]-pos[med], pos[med]-pos[left]));
        left++;
    }
    cout << ans << endl;
    return 0;
}

//7 2
//0100100

//02356

//01234

// k+1 = 3
// right  2        left  0    med 0+3/2 = 1 
// pos    3           0         2

// right  3        left  1    med 1+3/2 = 2
// pos    5           2         3