class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                // We found a new lowest price to buy at
                minPrice = prices[i]; 
            } else if (prices[i] - minPrice > maxProfit) {
                // If selling today gives us a better profit, update it
                maxProfit = prices[i] - minPrice; 
            }
        }
        
        return maxProfit;
    }
};