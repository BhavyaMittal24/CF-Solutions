#include<bits/stdc++.h>
using namespace std;    

//Function to find the maximum distance between the median zero and a corner zero.
// The subarray is defined by the 'first' and 'second' indices.
int findMaxDistance(const std::string& rooms, int first, int second) {
    // Step 1: Find and store the indices of all zeros in the subarray.
    std::vector<int> zeroIndices;
    for (int i = first; i <= second; ++i) {
        if (rooms[i] == '0') {
            zeroIndices.push_back(i);
        }
    }

    // Check if there are enough zeros (k+1) to proceed.
    // The user's problem statement implies this is always true.
    if (zeroIndices.size() < 2) {
        return 0; // Not enough zeros to calculate distance.
    }

    // Step 2: Determine the indices of the median zero, first zero, and last zero.
    int medianIndexInVector = zeroIndices.size() / 2;
    int medianZeroPosition = zeroIndices[medianIndexInVector];

    int firstZeroPosition = zeroIndices.front();
    int lastZeroPosition = zeroIndices.back();

    // Step 3: Calculate the distances from the median zero to the corner zeros.
    int distanceFromFirstCorner = std::abs(medianZeroPosition - firstZeroPosition);
    int distanceFromLastCorner = std::abs(medianZeroPosition - lastZeroPosition);

    // Step 4: Return the maximum of the two distances.
    return std::max(distanceFromFirstCorner, distanceFromLastCorner);
}


int main(){

    int n,k;
    cin >> n >> k;
    string rooms;
    cin >> rooms;
    // find the shortest substring which has number of zeros >= k+1
    // i will place cows and john there
    int left =0;
    int right = 0;
    int minLength = n+1;
    pair<int,int> subarray;
    long long countZero = 0;
    while(right <n){
        if(rooms[right] == '0') countZero++;
        while(left<=right &&  countZero >=k+1){
            if(minLength > right -left+1){
                minLength = right-left+1;
                subarray = {left,right};
            }
            if(rooms[left] == '0') countZero--;
            left++;
        }
        right++;
    }
    //cout << subarray.first << " " << subarray.second << endl;
    // now i have right and left of the desired subarray
    int positionOfJohn = -1;
    long long cntZero = 0;
    int firstZero = -1;
    // int minDistance = INT_MIN;
    // for(int i = subarray.first;i<=subarray.second;i++){
    //     if(rooms[i] == '0'){
    //         if(positionOfJohn != -1 && firstZero != -1) firstZero = i;
    //         if(positionOfJohn ==-1 && cntZero == (k+1)/2) {
    //             positionOfJohn = i;
    //         }
    //         cntZero++;

    //     }
    // }
    // for(int i=subarray.second; i>positionOfJohn;i--){
    //     if(rooms[i] == '0'){
    //         minDistance = max(minDistance, abs(i - positionOfJohn));
    //     }
    // }
    // cout << minDistance << endl;
    int maxDistance = findMaxDistance(rooms, subarray.first, subarray.second);
    cout << maxDistance << endl;
    return 0;
}