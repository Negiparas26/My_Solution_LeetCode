class Solution {
public:
    
bool canBeValid(string s, string locked) {
    int n = s.size();
    
    if (n % 2 != 0) return false; //[(omly even )]

    // Left-to-right pass ==>
    int open = 0;  // N0. of open '(' 
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' || locked[i] == '0') {
            open++;
        } else {
            open--;
        }
        if (open < 0) return false; // Too many ')'  
    }

    // Right-to-left pass <==
    int close = 0;  // no. of close ')' 
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ')' || locked[i] == '0') {
            close++;
        } else {
            close--;
        }
        if (close < 0) return false; // Too many '('
    }

    return true;
}
};