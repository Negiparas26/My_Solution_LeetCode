
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); 

        //max feq in words2
        for (string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        //  in words1
        vector<string> result;
        for (string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool isUniversal = true;           // max [e:1 o:1]  
            for (int i = 0; i < 26; i++) { //freq[a :2 m:1 z:1 o:1 n:1 e:0 o:0]=> [e:0<e:1] not found
                if (freq[i] < maxFreq[i]) {   // ,freq[f:1 a:1 c:1 e:1 b:1 o:2 k:1 ]
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};