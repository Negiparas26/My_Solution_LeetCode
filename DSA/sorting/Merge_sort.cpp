#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    // Calculate the size of the two sub-arrays to be merged
    int n1 = mid - left + 1;  // Size of the left sub-array
    int n2 = right - mid;     // Size of the right sub-array

    // Create temporary arrays to store the elements of the two sub-arrays
    int leftArr[n1], rightArr[n2];

    // Copy data into the temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    int i = 0;    // Initial index of leftArr
    int j = 0;    // Initial index of rightArr
    int k = left; // Initial index of merged sub-array

    // Merge the two arrays while comparing elements
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point to split the array
        int mid = left + (right - left) / 2;

        // Recursively split the array into two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the two halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

  
    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
