class Solution {
public:
    vector<int> getRow(int rowIndex){
        vector<vector<int>> ans;

        for (int i = 0; i<=rowIndex; i++){
            vector<int> rows(i+1,1);

            for (int j = 1; j<i; j++){
                rows[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            ans.push_back(rows);
        }

        return ans.back();
    }
};