// 4, 8, 15, 16, 23, 42

// 15 23 16 42 8 4

// map for product and possible answers : 15 values
// approach 1: take 2 queries and guess 3 elements. find c by using gcd. 
// ? I j :  1 <=i<=j <=6
// guess 1st element : rem = 3
// guess 2nd number
// know last 4 numbers, not their position
// ? 3 4 know wht are 3 and 4, not exactly where they are. Similarly know 
// ? 4 5 know exactly where all elements are

// store 6 values with their respective answers
#include<bits/stdc++.h>
using namespace std;

int ask(int i, int j){
   cout << "? " <<  i << " " <<  j << endl;
   int resp;
   cin >> resp;
   return resp;
}
int main(){
   
  int first = ask(1,1);
  int second = ask(2,2);
  vector<int> v = {15,23,16,42,8,4};

  unordered_set<int> st;
  for(auto it : v){
    st.insert(it);
  }

  first = sqrt(first);
  second = sqrt(second);

  st.erase(first);
  st.erase(second);
 
  int product_34 = ask(3,4);
  int third;
  int fourth;
  int fifth;
  int sixth;
  for(auto it : st){
     if( product_34 % it == 0 && st.count(product_34 / it) == 1 && it != product_34 / it) {
	    third = it;
        fourth = product_34 / it;
        st.erase(third);
        st.erase(fourth);
     }
  }

  long long product = 1ll * 4* 8 * 15 * 16 * 23 * 42;
  long long productUntilNow =  1ll*(first * second * product_34);
  int product_56 = product/ productUntilNow;
 
  for(auto it : st){
     if( product_56 % it == 0 && st.count(product_56 / it) == 1 && it != product_56 / it) {
	    fifth =  it;
        sixth = product_56 / it;
        st.erase(fifth);
        st.erase(sixth);
     }
  }
  
  int product_45 = ask(4,5);
  
  // 4th element is 3rd
  if( product_45 % fourth != 0) {
      swap(third,fourth);
  }
  // 4th element is 4th

//   else if ( product_45 % fourth == 0 && product_45 % third !=0){
//   }
  // 4th elememt can be any
  else if( product_45 % fourth == 0 && product_45 % third == 0) { 
      int finalfifth = product_45 / fourth;
      if( finalfifth != fifth && finalfifth != sixth ){
          swap(fourth, third);
      }
  }

  int finalfifth = product_45 / fourth;
      if( finalfifth != fifth){
         swap(fifth, sixth);
      }

  cout << "! " << first << " " << second << " " << third << " " << fourth << " " << fifth << " " << sixth << endl;
  return 0;
}




