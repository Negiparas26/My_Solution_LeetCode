class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (string& word : words) {
            // Check if the current word starts with the given prefix
            if (word.substr(0, pref.size()) == pref) {
                ans++;
            }
        }
        return ans;
    }
};
