#include<bits/stdc++.h>
using namespace std;


const int N = 100000;

// 1 based index for the Priority Queue
// Based on a heap : which is a complete binary tree : where there is no node left: all are covered : each node has two children and so on
// only the nodes in the last level are empty and no gap between them as well

// height for a binary tree is log2(n)

int lastIndex = 1;
int arr[N];

// implementing a max heap

void push(int val){

    arr[lastIndex] = val;
    lastIndex ++;

    // up heapify : go from bottom to up
    int curr = lastIndex - 1;

    int parent = curr / 2;

    while ( curr !=1 && arr[curr] > arr[parent]){
        swap(arr[curr] , arr[parent]);
        curr = parent;
        parent = parent/2;
    }
}

void pop(){

    swap(arr[1], arr[lastIndex - 1]);
    lastIndex--;

    // Down healpify
    int curr = 1;
    int leftChild = 2*curr;
    int rightChild = 2*curr  + 1;

    int maxNode = curr;
    // take the max out of both of them
    while(rightChild < lastIndex){

        maxNode = curr;
        if( arr[maxNode] < arr[leftChild]){
            maxNode = leftChild;
        }

        if( arr[maxNode] < arr[rightChild]){
            maxNode = rightChild;
        }

        if( maxNode == curr) break;

        swap(arr[curr], arr[maxNode]);
        curr = maxNode;
        leftChild = 2*curr;
        rightChild = 2*curr + 1;
    }

    if( leftChild < lastIndex){
        if( arr[curr] < arr[leftChild]){
            swap(arr[curr], arr[leftChild]);
        }
    }
}

int top(){
    return arr[1];
}

int main(){


    for(int i = 1 ; i <= 10 ; i ++) push(i);

    for(int i = 1 ; i <= 10 ; i ++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 1 ; i <= 10 ; i ++){
        cout << top() << " ";
        pop();
    }

    return 0;
}