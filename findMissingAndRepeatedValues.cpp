class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int arraySum = 0;
        int actualSum = ((n * n) * ((n * n) + 1)) / 2;
        set<int> s;
        vector<int> ans;
        int repeated = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s.find(grid[i][j]) != s.end()) {
                    repeated = grid[i][j];
                    // ans.push_back(grid[i][j]);
                }
                s.insert(grid[i][j]);
                arraySum += grid[i][j];
            }
        }

        int missingNo = actualSum - (arraySum - repeated);
        ans.push_back(repeated);
        ans.push_back(missingNo);
        return ans;
    }
};
