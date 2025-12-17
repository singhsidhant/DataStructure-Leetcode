class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        const long long NEG = -1e18;
        
        vector<long long> none(k+1, 0);        // no position
        vector<long long> longHold(k+1, NEG);  // bought
        vector<long long> shortHold(k+1, NEG); // sold
        
        for (int price : prices) {
            for (int t = k; t >= 1; t--) {
                // close positions
                none[t] = max(none[t],
                              longHold[t] + price);
                none[t] = max(none[t],
                              shortHold[t] - price);
                
                // open positions
                longHold[t] = max(longHold[t],
                                  none[t-1] - price);
                shortHold[t] = max(shortHold[t],
                                   none[t-1] + price);
            }
        }
        
        long long ans = 0;
        for (int t = 0; t <= k; t++)
            ans = max(ans, none[t]);
        
        return ans;
    }
};
