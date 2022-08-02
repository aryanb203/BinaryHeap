#include<bits/stdc++.h>
using namespace std;

void Insert(int A[], int n){

    int i=n, temp;
    temp = A[n];
    while(i>1 && temp > A[i/2]){
        A[i] = A[i/2];
        i=i/2;
    }
    A[i]= temp;
}

void Delete(int A[], int n){

    int i, j;
    A[1]=A[n];
    i=1; j=2*i;
    while(j<n-1){
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j]){
            swap(A[i], A[j]);
            i=j;
            j=2*i;
        }
        else
            break;
    }
}

void HeapSort(int A[], int n){

    
    for(int k=n; k>=1; k--){
    int x, i, j;
    x=A[1];
    A[1]=A[k];
    i=1; j=2*i;
    while(j<k-1){
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j]){
            swap(A[i], A[j]);
            i=j;
            j=2*i;
        }
        else
            break;
    }
    A[k]=x;

    }

}


void heapify(int arr[], int n, int i){  //i is root node and n is the size of heap
    int large=i;
    int l=2*i;   //left child of root
    int r=2*i+1;  //right child of root

    if(l<=n && arr[l]>arr[large])  //checking if left index is valid and if its data is larger than large
        large=l;
    if(r<=n && arr[r]>arr[large])
        large=r;
    if(i!=large){
        swap(arr[i], arr[large]);
        heapify(arr, n, large);
    }
}

void createHeap(int arr[], int n){
    for(int i=n/2; i>=1; i--){
        heapify(arr, n, i);
    }
}


int main(){

int H[]= {0, 10, 20, 30, 25, 5, 40, 35};

// for(int i=2; i<=7; i++)
//     Insert(H, i);
createHeap(H, 7);
HeapSort(H, 7);
for(int i=1; i<=7; i++)
    cout<<H[i]<<" ";
return 0;
}