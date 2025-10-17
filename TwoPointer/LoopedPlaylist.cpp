#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int n;
//     long long k;
//     cin >> n >> k;
//     long long sum = 0;
//     vector<long long> a(n);
//     for(int i=0;i<n;i++) {
//         cin >> a[i];
//         sum += a[i];
//     }
//     long long times = ceil(k/sum)+1;
//     times = (times +1)* n;
//     // cout << times << endl;
//     // long long i = 0;
//     // while(times--){
//     //     a.push_back(a[i]);
//     //     i = (i+1)%n;
//     // }

//     // n = a.size();
//     // // cout << n << endl;
//     int left = 0;
//     int right = 0;
//     long long currentSum = 0;
//     long long sI = -1;
//     long long minLen = INT_MAX;
//     long long rightMoves = 0;
//     long long leftMoves = 0;
//     while(rightMoves < times){
//         currentSum += a[right];
//         while( currentSum >= k){
//             if( rightMoves - leftMoves + 1 < minLen){
//                 minLen = rightMoves - leftMoves + 1;
//                 sI = left;
//             }
//             currentSum -= a[left];
//             left = (left + 1)%n;
//             leftMoves++;
//         }
//         right = (right + 1)%n;
//         rightMoves++;
//     }
//     cout << sI+1 << " " << minLen << endl;
//     return 0;
// }



// looped playlist 
// two cases k 
// find the shortest subarray with sum >=k
// if the sum ai >=k, then I can find the shortest subarray in the original array
// or i can also find it in the orgiginal + original array


// case 1 : sum >= k
    
// [a1 a2         an] [a1 a2 ..   an]


// case 2 : sum < k
// playlists would have to be looped multiple times k/sum times

// sum = 6, k = 20
// 20/6 = 3.33
// [1 2 3][1 2 3][1 2 3][1 2 3]

// hence  rem = k% sum
// [a1 a2 ... an ] [ ]  [ ] [ ] [ a1 a2 ... an]

int main(){
    int n;
    long long k;
    cin >> n >> k;
    // find shortes subarray with sum >=k, and the arrays can be looped if possible

    long long sum = 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }

    long long extraArrays = k/sum;
    long long rem = k % sum;
    // if ( k > sum) we can loop the array extraArrays, else sum >= k, then two arrays are enough
    // rem = k% sum if k > sum, else it would be just k

    for(int i=0;i<n;i++){
        a.push_back(a[i]);
    }

    int left = 0;
    int right = 0;
    long long currentSum = 0;
    long long minLen = INT_MAX;
    long long si = -1;
    while(right < 2*n){
        currentSum += a[right];
        while(left<=right && currentSum >= rem){
            if(right-left+1< minLen){
                minLen = right-left+1;
                si=left;
            }
            currentSum -=a[left];
            left++;
        }
        right++;
    }

    // now we have the minLen of the subarray with sum >= rem
    minLen = minLen + (extraArrays * n);
    // edge case for when rem = 0, I can have minLen = just the wntire whole arrays and can pick any index
    if(rem == 0) {
        minLen = extraArrays * n;
        si= 0;
    }
    cout << si+1 << " " << minLen << endl;
    return 0;
}