#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &cell, int height, int prefixIdx){

    vector<int> temp;
    //  2 3 4 5  : i <= 4
    // placing k bottles at once : sort them and find the max possible height for the firdge. pair the max height with second max height together to 
    for(int i = 1; i <= prefixIdx; i ++){
        temp.push_back(cell[i]);
    }
    sort(temp.begin(), temp.end());

    // check if it is possible to place all these k prefix into the firgide with height h
    long long heightSum = 0;

    for(int i = temp.size()-1; i >= 0; i -=2){

        heightSum += temp[i];
    }

    // if(temp.size() % 2){
    //     heightSum += temp.back();
    // }

    if(heightSum <= height) return true;
    return false;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;

    vector<int> cell(n+1,0);
    for(int i = 1; i <= n; i++){
        cin >> cell[i];
    }

    // height of each bottle

    // for the max no of  bottles place in one go atsame time : prefix : 1... k bottles
    int low = 0;
    int high = n;

    int ans = -1;

    while(low <= high){

        int mid = (low + high)/2;

        if(isPossible(cell, h, mid)){
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
        
    }

    cout << ans << "\n";
    return 0;
}