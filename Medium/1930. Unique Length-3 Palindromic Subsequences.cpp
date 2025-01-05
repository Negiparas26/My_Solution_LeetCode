class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        vector<pair<int,int>>indices(26,{-1,-1});
        for(int i=0;i<n;i++){
            char ch=s[i];
            int idx= ch-'a';  //a=0,b=1..
            if(indices[idx].first==-1){
                indices[idx].first=i;
            }
            indices[idx].second=i;
        }
        int result=0;

        for(int i=0;i<26;i++){

            int left_idx=indices[i].first;
            int right_idx=indices[i].second;
            if(left_idx==-1){
                continue;
            }
        

        unordered_set<char>st;
        for(int mid=left_idx+1;mid<=right_idx-1;mid++){
            st.insert(s[mid]);
        }
        result+=st.size();

        }
        return result;
        
    }
};