#include<iostream>
using namespace std;

void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){             // Inner loop to compare adjacent elements
        for(int j=0;j<n-i-1;j++){        // If the current element is greater than the next element, swap them
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);    // Swap the two elements using the swap function
            }
        }
    }
}

int main(){
    int arr []={64,34,25,11,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);

    for(int a:arr){
        cout<< a<<" ";
    }

}