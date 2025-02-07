//Sieve of Eratosthenes algorithm.

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (int j = i * 2; j < n; j = j + i) {
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }
};

// bool isPrime(int arr){
//      if(arr<2) return false;
//     for(int i=2;i<arr;i++){
//         if(arr%i==0)return false;
//     }
//     return true;
// }
// bool isPrime(int arr){
//     if(arr<2) return false;
//     int sqt=sqrt(arr);
//     for(int i=2;i<=sqt;i++){
//         if(arr%i==0)return false;
//     }
//     return true;
// }