
#include <iostream>
#include <climits>
using namespace std;
int main() {
 

int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){

    cin>>arr[i];
}    //[8,4,3,2,1]
int sm=INT_MAX;
int lg=INT_MIN;
int sm2;
 int lg2;
//cout<<sm<<" "<< lg;
for(int i=0;i<n;i++){
    //largest
    if(arr[i]>lg){
        lg2=lg;
        lg=arr[i];
    }
    if(arr[i]!=lg && arr[i]>lg2){
        lg2=arr[i];
    }
    
    //smallest
     if(arr[i]<sm){
        sm2=sm;
        sm=arr[i];
    }
    if(arr[i]!=sm && arr[i]<sm2){
        sm2=arr[i];
    }
}
cout<<" 2 smallest : "<< sm2<<endl;
cout<<" 2 largest : "<< lg2<<endl;
    return 0;
}



//code 2: 


#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

int main() {
    int n;

    // Input size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input validation
    if (n < 2) {
        cout << "Array must have at least two elements!" << endl;
        return 0;
    }

    // Declare and input the array
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize variables
    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    // Find largest and smallest elements
    for (int i = 0; i < n; i++) {
        // Update largest and second largest
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }

        // Update smallest and second smallest
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    // Check if second largest and second smallest exist
    if (secondLargest == INT_MIN || secondSmallest == INT_MAX) {
        cout << "Array doesn't have distinct second largest or second smallest elements." << endl;
    } else {
        cout << "Second Largest: " << secondLargest << endl;
        cout << "Second Smallest: " << secondSmallest << endl;
    }

    return 0;
}
