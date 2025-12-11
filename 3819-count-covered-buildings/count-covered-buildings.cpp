class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int num_buildings = buildings.size();
        if (num_buildings < 5) {
            return 0;
        }

        unordered_map<int, int> min_col_in_row;
        unordered_map<int, int> max_col_in_row;
        unordered_map<int, int> min_row_in_col;
        unordered_map<int, int> max_row_in_col;

        for (const auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            if (min_col_in_row.find(x) == min_col_in_row.end() || y < min_col_in_row[x]) {
                min_col_in_row[x] = y;
            }
            if (max_col_in_row.find(x) == max_col_in_row.end() || y > max_col_in_row[x]) {
                max_col_in_row[x] = y;
            }

            if (min_row_in_col.find(y) == min_row_in_col.end() || x < min_row_in_col[y]) {
                min_row_in_col[y] = x;
            }
            if (max_row_in_col.find(y) == max_row_in_col.end() || x > max_row_in_col[y]) {
                max_row_in_col[y] = x;
            }
        }

        int uncovered_count = 0;

        for (const auto& b : buildings) {
            int x = b[0];
            int y = b[1];
            
            if (y == min_col_in_row[x] || y == max_col_in_row[x]) {
                uncovered_count++;
                continue;
            }

            if (x == min_row_in_col[y] || x == max_row_in_col[y]) {
                uncovered_count++;
            }
        }
        return num_buildings - uncovered_count;
    }
};