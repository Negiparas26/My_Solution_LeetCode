
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