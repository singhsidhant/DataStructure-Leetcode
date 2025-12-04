class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length();
        if (n == 0) return 0;
        
        // Find the starting index (Skip all leading 'L's)
        int start = 0;
        while (start < n && directions[start] == 'L') {
            start++;
        }
        // If the string is all 'L's (or empty after check), no collisions.
        if (start == n) {
            return 0;
        }

        // Find the ending index (Skip all trailing 'R's)
        int end = n - 1;
        while (end >= 0 && directions[end] == 'R') {
            end--;
        }
        
        // Count total collisions in the effective segment [start, end]
        int total_collisions = 0;
        
        for (int i = start; i <= end; ++i) {
            char car = directions[i];
            if (car == 'R' || car == 'L') {
                total_collisions++;
            }
        }
        
        return total_collisions;
    }
};