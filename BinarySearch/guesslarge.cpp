// Guess the greatest hard version

// n different numbers :    2<=n <= 1e5
// distinct integers

//indexes from 1 to n of array of size n
// ? [l r] gives us the result for the index of second largest element in the subarray


// i = index of second largest element
// ? [1,n]

//                [       ]
// 1---[x--------i] - --x-------n 

// [mid,i]
//We can know which half is the largest element in : 
// [1,i] : 
//[i,n] : 
// These 2 queries return the second largest element and if that is i, it means largest is present in them


//It could be for some index x, that subarray ? [x,i] returns i, otherwise it would return some other value
// the first value for x is the answer
// low = 1
// high = i-1;
// TTTTTTTTTTTTFFFFFFF

// if right half : low = i+1
// high = n;
// FFFFTTTTTT 

// bs : log(1e5) ~ 20

#include<bits/stdc++.h>
using namespace std;

int ask(int l, int r){
   int resp;
   if(l == r) return 0;
   cout << "? " << l << " " << r << endl;
   cin >> resp; 
   return (l != r ) ? resp : 0;
}

int main(){
	int n;
	cin >> n;
	int secondLargestIdx = ask(1,n);
	int leftHalf = ask(1,secondLargestIdx);
    int rightHalf = ask(secondLargestIdx,n);

	int low = 1;
    int high = secondLargestIdx-1;
    int mid=0;
	int ans = -1;
	// largest lies in left half
    if( leftHalf && leftHalf == secondLargestIdx){
	   while(low <= high){
	  	    mid = (low+high)/2;
           	int idx = ask(mid,secondLargestIdx);
	   	    if(idx ==secondLargestIdx){
			    ans = mid;
			    low = mid+1;
            }
            else{
                high = mid-1;
            }
	    }
    }
	else if (rightHalf && rightHalf == secondLargestIdx){
         low = secondLargestIdx+1;
	     high = n;
	     while(low <=high){
		    mid = (low+high)/2;
		    int idx= ask(secondLargestIdx,mid);
		    if( idx == secondLargestIdx){
		        ans = mid;
		        high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
    }	
    cout << "! " << ans << endl;
	return 0;
}

// 1 3 5 2 4 