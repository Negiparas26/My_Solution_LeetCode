// #include<iostream>
// using namespace std;

// int partition(int arr[],int left,int right){
//     int pivot =arr[left];    // 1 element is pivort 
//     int start=left;
//     int end=right;

//     while(start<end){
//         while(arr[start]<=pivot){    // Increment start index until we find an element greater than the pivot
//             start++;
//         }
//          while(arr[end]>pivot){      // Decrement end index until we find an element less than or equal to the pivot
//             end--;
//         }
//         if(start<end){
//             swap(arr[start],arr[end]);          // If start is less than end, swap elements
//         }
//     }
//     swap(arr[left],arr[end]);    // Swap the pivot element with the element at the end pointer
//     return end;
// }

// void quickSort(int arr[],int left,int right){


// if(left<right){
//     int mid=partition(arr,left,right); // Partition the array
//     quickSort(arr,left,mid-1);
//     quickSort(arr,mid+1,right);
// }

// }
// int main() {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n=sizeof(arr)/sizeof(arr[0]);

//     cout << "Original Array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;

//     // Perform Quick Sort
//     quickSort(arr, 0, n - 1);

//     cout << "Sorted Array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right]; // Select the last element as the pivot
    int i = left - 1;       // Index for elements smaller than the pivot

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) { // If current element is smaller than or equal to the pivot
            i++;
            swap(arr[i], arr[j]); // Swap it to the correct position
        }
    }

    // Place the pivot in its correct position
    swap(arr[i + 1], arr[right]);
    return i + 1; // Return the pivot index
}


void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) { // If there's more than one element
        int mid = partition(arr, left, right); 

      
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}

int main() {
    // Input array
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    // Print the original array
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}






