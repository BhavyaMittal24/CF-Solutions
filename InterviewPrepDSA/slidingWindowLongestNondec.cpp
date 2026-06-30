given an array find a the largest length of the longest non dec order subarray

// [1 2 -1 2 5 6 1 9 5]

// -1 2 5 6


vector<int> longestNonDecreasingSubArray( vector<int> &a) {

   int n= a.size();
   int maxLen = 0;
   int si = -1;
   int left = 0;
   int right = 0;
   for(;right<n;right++){
      // shrink the window when arr[right] is not >= arr[right-1] 
      if(right>0 && a[right] < a[right-1]) {
         left = right;
      } 
      if(maxLen < right-left+1){
         si=left;
         maxLen = (right-left+1);
      }
   }
   
   // si = 2
   // Minlen = 4
   //  [si, si+minelen-1]
   vector<int> ans;
   for(int i=si;i <si+minLen; i++){
      ans.push_back(a[i]);
   } 

   cout << minLen<< " ";
   return ans;
}


// Now I need to find the longest subarray length and the aray which is non dec when I can change only one element in the array to anything

