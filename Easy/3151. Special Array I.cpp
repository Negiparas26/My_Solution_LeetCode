class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i)
            if (!((nums[i] ^ nums[i-1]) & 1)) // XOR 
                return false; // 
        return true; 
    }
};

// class Solution {
// public:
//     bool isArraySpecial(vector<int>& nums) {
//         for(int i = 0; i < nums.size() - 1; i++) {
//             if (nums[i] % 2 == nums[i + 1] % 2) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };