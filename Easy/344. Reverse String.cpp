class Solution {
public:
    void reverseString(vector<char>& s) {
        int it=s.size()-1;
        for(int i=0;i<it;it--,i++){
                  int temp=s[i];
                  s[i]=s[it];
                  s[it]=temp;
            }

    }
};