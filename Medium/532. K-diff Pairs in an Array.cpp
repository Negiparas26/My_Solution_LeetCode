class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
           if (k < 0) return 0;  // No valid pairs for negative k

        unordered_map<int, int> mp;
        int count = 0;

        // Count frequency of each element
        for (int num : nums) {
            mp[num]++;
        }

        // Traverse the map to find valid k-diff pairs
        for (auto &pair : mp) {
            int num = pair.first;

            if (k == 0) {
                // If k == 0, count elements with frequency >= 2
                if (pair.second > 1) count++;
            } else {
                // Otherwise, check if num + k exists in the map
                if (mp.find(num + k) != mp.end()) count++;
            }
        }

        return count;
    }
};class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
           if (k < 0) return 0;  // No valid pairs for negative k

        unordered_map<int, int> mp;
        int count = 0;

        // Count frequency of each element
        for (int num : nums) {
            mp[num]++;
        }

        // Traverse the map to find valid k-diff pairs
        for (auto &pair : mp) {
            int num = pair.first;

            if (k == 0) {
                // If k == 0, count elements with frequency >= 2
                if (pair.second > 1) count++;
            } else {
                // Otherwise, check if num + k exists in the map
                if (mp.find(num + k) != mp.end()) count++;
            }
        }

        return count;
    }
};