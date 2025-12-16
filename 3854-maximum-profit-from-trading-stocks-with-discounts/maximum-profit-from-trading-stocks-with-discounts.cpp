class Solution {
public:
    struct myPair {
        vector<int> dp0; // Parent NOT bought
        vector<int> dp1; // Parent bought
    };

    void mergeOneChild(vector<int>& cur, const vector<int>& childDp, int budget) {
        vector<int> newCur(budget + 1, 0);
        for (int b = 0; b <= budget; ++b) {
            int best = 0;
            for (int x = 0; x <= b; ++x) {
                best = max(best, cur[b - x] + childDp[x]);
            }
            newCur[b] = best;
        }
        cur.swap(newCur);
    }

    myPair dfs(int u, vector<vector<int>>& child, vector<int>& present, vector<int>& future, int budget) {
        vector<int> sub0(budget + 1, 0);
        vector<int> sub1(budget + 1, 0);

        for (int i = 0; i < child[u].size(); ++i) {
            int v = child[u][i];
            myPair r = dfs(v, child, present, future, budget);

            mergeOneChild(sub0, r.dp0, budget);
            mergeOneChild(sub1, r.dp1, budget);
        }

        myPair res;
        res.dp0.assign(budget + 1, 0);
        res.dp1.assign(budget + 1, 0);

        int fullCost = present[u];
        int halfCost = present[u] / 2;

        for (int b = 0; b <= budget; ++b) {
            // Not buy u
            res.dp0[b] = sub0[b];
            res.dp1[b] = sub0[b];

            // Buy u
            if (b >= fullCost) res.dp0[b] = max(res.dp0[b], sub1[b - fullCost] + (future[u] - fullCost));
            if (b >= halfCost) res.dp1[b] = max(res.dp1[b], sub1[b - halfCost] + (future[u] - halfCost));
        }

        return res;
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> child(n, vector<int>());
        for (int i = 0; i < hierarchy.size(); ++i) {
            child[hierarchy[i][0] - 1].push_back(hierarchy[i][1] - 1);
        }

        myPair root = dfs(0, child, present, future, budget);
        return root.dp0[budget];
    }
};