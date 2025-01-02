// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {}; 
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // Stores the number and its index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // The value we need to find
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i}; // Return indices of the two numbers
            }
            num_map[nums[i]] = i; // Store the current number with its index
        }
        return {}; // Return empty if no solution is found
    }
};
