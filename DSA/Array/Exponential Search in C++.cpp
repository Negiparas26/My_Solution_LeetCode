#include <iostream>
#include <vector>
using namespace std;

// Binary search function
int binarySearch(vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Found target
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}

// Exponential search function
int exponentialSearch(vector<int>& arr, int target) {
    int n = arr.size();
    if (arr[0] == target)
        return 0;

    // Find the range where the target may be present
    int i = 1;
    while (i < n && arr[i] <= target)
        i *= 2;

    // Perform binary search in the found range
    return binarySearch(arr, i / 2, min(i, n - 1), target);
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 15, 24, 33, 47, 59};
    int target = 15;

    int index = exponentialSearch(arr, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
