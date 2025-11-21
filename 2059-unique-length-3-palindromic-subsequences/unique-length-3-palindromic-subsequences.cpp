class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> pos(26);

        for (int i = 0; i < n; ++i) {
            pos[s[i]-'a'].push_back(i);
        }

        int ans = 0;
        for (int a = 0; a < 26; ++a) {
            if (pos[a].size() < 2) continue;

            int L = pos[a].front();
            int R = pos[a].back();

            vector<bool> seen(26, false);
            for (int i = L+1; i < R; ++i) {
                seen[s[i]-'a'] = true;
            }
            for (int b = 0; b < 26; ++b) if (seen[b]) ++ans;
        }
        return ans;
    }
};
