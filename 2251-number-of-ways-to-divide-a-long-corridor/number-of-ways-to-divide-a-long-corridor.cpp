class Solution {
private:
    const long long MOD = 1e9 + 7;

public:
    int numberOfWays(string corridor) {
        int n = corridor.length();
        
        vector<int> seatIndices;
        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S') {
                seatIndices.push_back(i);
            }
        }
        
        int numSeats = seatIndices.size();
        
        if (numSeats == 0 || numSeats % 2 != 0) {
            return 0;
        }
        
        long long totalWays = 1;
        
        for (int i = 1; i < numSeats - 1; i += 2) {
            int s_end_index = seatIndices[i];
            int s_start_index = seatIndices[i + 1];
            
            long long numPlants = s_start_index - s_end_index - 1;
            
            long long waysInThisGap = numPlants + 1;
            
            totalWays = (totalWays * waysInThisGap) % MOD;
        }
        
        return (int)totalWays;
    }
};