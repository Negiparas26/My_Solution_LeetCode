#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    //  Iterate through each element in the array starting from the second element
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // The element to be inserted in the sorted portion of the array
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key one position ahead
        // of their current position to make space for the key element
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element to the right
            j = j - 1;       // Move to the previous element
        }

        // Insert the key element at its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    for (int a : arr) {
        cout << a << " ";  
    }

    return 0;  
}
