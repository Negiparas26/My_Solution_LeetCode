class Solution {
public:

    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);
        for (int i = 0; i < n; i++) {
            int hours = stoi(timePoints[i].substr(0, 2));
            int minutes = stoi(timePoints[i].substr(3, 2));
            minutes[i] = hours * 60 + minutes;
        }
        
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        
        for (int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, minutes[i + 1] - minutes[i]);
        }
        
        minDiff = min(minDiff,min( 1440 + minutes[0] - minutes[n - 1],minutes[n-1]-minutes[0]));
        
        return minDiff;
    }
};