// class Solution {
// public:
//     int waysToSplitArray(vector<int>& nums) {
//         int n=nums.size();
//         int start=0;
//         int split=0;
//         for (int i=0;i<n-1;i++){  
//              int last=0;
//             start+=nums[i];      //10  //14 //7
//             for(int j=i+1;j<n;j++){
//                 last+=nums[j];       //3  //-1       
//             }
//             if(start >=last){
//                 split++;
//             }
//         }
//         return split;
//     }
// }; 


class Solution { 
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total_sum = 0, left_sum = 0; 
        int valid_splits = 0;

        for (int num : nums) {
            total_sum += num;
        }
        // Iterate through the array
        for (int i = 0; i < nums.size() - 1; i++) {
            left_sum += nums[i];       // Update the left sum
            long long right_sum = total_sum - left_sum; // Calculate right sum
            if (left_sum >= right_sum) {
                valid_splits++;
            }
        }
        return valid_splits;
    }
};


