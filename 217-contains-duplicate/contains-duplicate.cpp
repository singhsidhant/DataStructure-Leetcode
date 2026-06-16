#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int it : nums) {
            if (mp[it] != 0) {
                return true;
            }
            mp[it]++;
        }

        return false;
    }
};