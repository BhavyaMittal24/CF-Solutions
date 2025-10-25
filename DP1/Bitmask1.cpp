#include<bits/stdc++.h>
using namespace std;

// generate all the permutations from 1 to n

// build a sequence from 0 to n-1 : Once index becomes equal to n, we print the sequence

// TC is : no of calls : subproblems : 0 ( n! * n )
void generatePermutations(int idx, vector<int>& arr, int n, int & bitmask){
    //cout << idx << " " << bitmask << endl;
    if(idx == n) {
        for(auto it : arr){
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // we want to add numbers from 1 to n to our sequence provided they  have not been added /
    for(int i=0;i<n;i++){
        // if the ith bit is not already set
        // num 1 -> 0th bit
        // num 2 -> 1st bit
        // eg array : 1 2 4 : 1011
        if((bitmask & (1 <<i)) == 0){
            arr.push_back(i+1);
            // set the ith bit
            bitmask = bitmask | (1 << i);
            generatePermutations(idx+1,arr,n,bitmask);
            arr.pop_back();
            // set the ith bit back to 0
            // 0 ^ 1 = 1
            // 1 ^ 1 = 0
            bitmask = bitmask ^ (1 << i);
        }
    }
}

// TC is : no of calls : subproblems : 0 ( n! * n )
// repeated subproblems : now each state is basically the//

// fn to print the number of permutations when prefix of 0- idx-1 has been set. and we want to set idx to n-1 more places
// and bitmask represents the used up places

int cntPermutations(int idx, int n, int bitmask){
    if(idx == n) {
        return 1;
    }

    int sum = 0;
    for(int i=0;i<n;i++){
        // if the ith bit is not already set
        // num 1 -> 0th bit
        // num 2 -> 1st bit
        // eg array : 1 2 4 : 1011
        
        if((bitmask & (1 <<i)) == 0){
            
            sum += cntPermutations(idx+1,n,(bitmask | (1 << i)));
        }
    }
    return sum;
}

//                 0, 000
//       1, 001
//  2, 011    2, 111
// 3, 111
int main(){
    int n;
    cin >> n;

    cout << cntPermutations(0,n,0);
    return 0;
}