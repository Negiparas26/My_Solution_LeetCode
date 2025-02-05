// class Solution {
// public:
//     bool areAlmostEqual(string s1, string s2) {
//         unordered_map<char,int> mp;
//         // int index=0;
//         vector<int>index;
//         int count=0;
//         for(int i=0;i<s1.size();i++){
//             if(s1[i]!=s2[i]){
//                 index.push_back(i);
//                 count++;
//             }
            
//         }
//         if (index.size() == 0) {
//             return true;
//         }
//         if (index.size() == 2) {
//             int i = index[0], j = index[1];
//             return s1[i] == s2[j] && s1[j] == s2[i];
//         }
//         return false;
         
//     }
// };

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;

        // so we can make both the strings equal iff there is 2 characters differs in s1 and s2
        int firstIdx = -1, secondIdx = -1;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                if(firstIdx == -1) firstIdx = i;
                else if(secondIdx == -1){
                    secondIdx = i;
                    swap(s2[firstIdx], s2[secondIdx]);
                    return s1 == s2;
                }
            }
        }
        return secondIdx != -1;
    }
};