#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> s_occurrence;
        unordered_map<char, int> t_occurrence;

        for (char ch : s) {
            s_occurrence[ch]++;
        }

        for (char ch : t) {
            t_occurrence[ch]++;
        }

        for (auto it : s_occurrence) {
            if (t_occurrence[it.first] != it.second) {
                return false;
            }
        }

        return true;
    }
};