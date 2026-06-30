#include<bits/stdc++.h>
using namespace std;


// l to r : 0 based indexing for the array. query from  0 <=  l,r <= n-1 
// segment tree nodes ae 1 based indexed.


class Node {
    public :
    long long sum;
    int lastElementSign;

    Node(){
        sum  = 0;
        lastElementSign  =  0;
    }

    Node (int val){
        sum = val;
        lastElementSign = 1;
    }

    void merge(Node &left, Node & right){

        if(left.lastElementSign == -1){
            sum = left.sum + right.sum;
            lastElementSign = (right.lastElementSign == 0) ? left.lastElementSign : right.lastElementSign;
        }
        else if(left.lastElementSign == +1){
            sum = left.sum - right.sum;

            lastElementSign = (right.lastElementSign == 0) ? left.lastElementSign : -1* right.lastElementSign;
        }

        else {
            sum = right.sum + left.sum;
            lastElementSign = right.lastElementSign;
        }
    }
};


class Update {
    int oldVal;
    int newVal;
    Update(int val1, int val2){
        oldVal = val1;
        newVal = val2;
    }

    void apply(Node & leafNode){
        leafNode.sum -= oldVal;
        leafNode.sum += newVal;
    }
};

// Update and build are similar :
// rang equery : we may have to combine the result : l,r -> some part full/ empty

// update : void update : no empty node : in case no mtch : only in rangr
// bottom leaf noe : a b c d


int main(){

    return 0;
}