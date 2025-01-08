#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the current position (i) has the smallest element
        int minIndex = i;

        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < arr[minIndex]) {
                // If a smaller element is found, update the minIndex
                minIndex = j;
            }
        }

        // If the smallest element is not at the current position, swap them
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for (int a : arr) {
        cout << a << " ";  
    }

    return 0;  
}
