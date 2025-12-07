class Solution {
public:
    int countOdds(int low, int high) {
        int base = (high - low) / 2;
        if (low % 2 != 0 || high % 2 != 0)
            return base + 1;
        return base;
    }
};
// make the pair inclusive
// even - odd 4 - 9 == If either low OR high is odd, we add 1.
// even - even - 2 - 8 - 3 but last is not odd so leave it
// odd - odd - 3 - 9  ---- If both are odd add only 1
// odd - even - 3 - 8