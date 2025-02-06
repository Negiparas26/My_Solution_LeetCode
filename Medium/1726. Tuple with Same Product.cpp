class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j];
                int count = productCount[product];
                result += 8 * count;
                productCount[product]++;
            }
        }

        return result;
    }
};
