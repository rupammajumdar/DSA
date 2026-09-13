class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;
        
        // Step 1: Dono images mein se 1s ke coordinates nikal lo
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1) ones1.push_back({i, j});
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        
        // Step 2 & 3: Shifts calculate karo aur count karo
        map<pair<int, int>, int> shiftCount;
        int maxOverlap = 0;
        
        for(auto& p1 : ones1) {
            for(auto& p2 : ones2) {
                // p1 ko p2 tak pahunchane ke liye kitna shift karna padega?
                int shift_x = p2.first - p1.first;
                int shift_y = p2.second - p1.second;
                
                // Us shift ka count badha do
                shiftCount[{shift_x, shift_y}]++;
                
                // Sath hi sath max overlap update karte raho
                maxOverlap = max(maxOverlap, shiftCount[{shift_x, shift_y}]);
            }
        }
        
        return maxOverlap;
    }
};