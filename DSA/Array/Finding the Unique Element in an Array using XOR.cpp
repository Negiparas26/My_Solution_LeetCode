#include <iostream>
#include <vector>
using namespace std;

// Function to find the unique number using XOR
int find(vector<int> v) {
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans = ans ^ v[i]; // XOR operation
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // Assign input directly to vector
    }

    int uni = find(v);
    cout << uni << " is the unique element." << endl;

    return 0;
}
