class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> delta(n + 1, 0); // Difference array
        
        // Update the difference array for each shift
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int value = (direction == 1) ? 1 : -1;
            delta[start] += value;
            delta[end + 1] -= value;
        }
        
        // Calculate the prefix sum to get the net shifts
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += delta[i];
            int shiftValue = (netShift % 26 + 26) % 26; // Handle negative shifts
            s[i] = 'a' + (s[i] - 'a' + shiftValue) % 26; // Apply the shift
        }
        
        return s;
    }
};
