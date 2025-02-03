class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int maxi = 0;
        int cnt_in = 1;
        int cnt_de = 1;

        for(int i =0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                cnt_in++;
                cnt_de = 1;
                maxi = max(cnt_in,maxi);
            }
            else if(nums[i] > nums[i+1]){
                cnt_in = 1;
                cnt_de++;
                maxi = max(cnt_de,maxi);
            }
            else{
                cnt_in = 1;
                cnt_de = 1;
                maxi = max(cnt_in,maxi);
            }
        }
        return maxi;
    }
};

// class Solution {
// public:
//     int longestMonotonicSubarray(vector<int>& nums) {
//          if (nums.empty()) {
//             return 0;
//         }

//         int maxLen = 1; 
//         int currentLen = 1; 
//         bool increasing = false;
//         bool decreasing = false; 

//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] > nums[i - 1]) {
//                 if (decreasing) { 
//                     currentLen = 1; // Reset length for a new increasing sequence
//                     decreasing = false;
//                 }
//                 increasing = true;
//                 currentLen++;
//             } else if (nums[i] < nums[i - 1]) { 
//                 if (increasing) { 
//                     currentLen = 1; // Reset for new decreasing sequence
//                     increasing = false;
//                 }
//                 decreasing = true;
//                 currentLen++;
//             } else { 
//                 currentLen = 1; // Reset length for equal elements
//                 increasing = false;
//                 decreasing = false;
//             }
//             maxLen = max(maxLen, currentLen); 
//         }
//         return maxLen;
//     }
// };class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int maxi = 0;
        int cnt_in = 1;
        int cnt_de = 1;

        for(int i =0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                cnt_in++;
                cnt_de = 1;
                maxi = max(cnt_in,maxi);
            }
            else if(nums[i] > nums[i+1]){
                cnt_in = 1;
                cnt_de++;
                maxi = max(cnt_de,maxi);
            }
            else{
                cnt_in = 1;
                cnt_de = 1;
                maxi = max(cnt_in,maxi);
            }
        }
        return maxi;
    }
};

// class Solution {
// public:
//     int longestMonotonicSubarray(vector<int>& nums) {
//          if (nums.empty()) {
//             return 0;
//         }

//         int maxLen = 1; 
//         int currentLen = 1; 
//         bool increasing = false;
//         bool decreasing = false; 

//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] > nums[i - 1]) {
//                 if (decreasing) { 
//                     currentLen = 1; // Reset length for a new increasing sequence
//                     decreasing = false;
//                 }
//                 increasing = true;
//                 currentLen++;
//             } else if (nums[i] < nums[i - 1]) { 
//                 if (increasing) { 
//                     currentLen = 1; // Reset for new decreasing sequence
//                     increasing = false;
//                 }
//                 decreasing = true;
//                 currentLen++;
//             } else { 
//                 currentLen = 1; // Reset length for equal elements
//                 increasing = false;
//                 decreasing = false;
//             }
//             maxLen = max(maxLen, currentLen); 
//         }
//         return maxLen;
//     }
// };