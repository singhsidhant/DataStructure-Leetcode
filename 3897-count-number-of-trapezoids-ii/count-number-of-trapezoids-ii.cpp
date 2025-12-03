class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        // t: grouped by normalized slope (sx, sy)
        // v: grouped by exact direction vector (dx, dy)
        unordered_map<int, unordered_map<int, int>> t;
        unordered_map<int, unordered_map<int, int>> v;

        int n = (int)points.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Normalize direction (make it a consistent half-plane)
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                int g = gcdAbs(dx, std::abs(dy));
                int sx = dx / g;   // normalized x
                int sy = dy / g;   // normalized y

                // line descriptor for this slope family
                int des = sx * points[i][1] - sy * points[i][0];

                // key packing as in Java: (sx << 12) | (sy + 2000)
                int key1 = (sx << 12) | (sy + 2000);  // normalized slope key
                int key2 = (dx << 12) | (dy + 2000);  // exact vector key

                ++t[key1][des];
                ++v[key2][des];
            }
        }

        return countGroups(t) - countGroups(v) / 2;
    }

private:
    static int countGroups(const unordered_map<int, unordered_map<int, int>>& mp) {
        long long ans = 0;
        for (const auto& kv : mp) {
            const auto& inner = kv.second;

            long long sum = 0;
            for (const auto& kv2 : inner) sum += kv2.second;

            long long running = sum;
            for (const auto& kv2 : inner) {
                int val = kv2.second;
                running -= val;
                ans += 1LL * val * running;
            }
        }
        return (int)ans;
    }

    static int gcdAbs(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a == 0 ? 1 : a;
    }
};
