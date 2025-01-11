class Solution {
public:
    bool canConstruct(string s, int k) {
    int n = s.size();

    // If k>n 
    if (k > n) return false;

    // Count character frequencies
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Count no. of ch with odd freq
    int oddCount = 0;
    for (int count : freq) {
        if (count % 2 != 0) {
            oddCount++;
        }
    }

    //  no. of odd freq is within k
    return oddCount <= k;
}
};