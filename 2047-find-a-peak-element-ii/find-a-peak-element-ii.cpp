class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int maxi = INT_MIN;

        int row = -1;
        int column = -1;

        vector<int> ans;

        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){

                if (mat[i][j] > maxi){
                    maxi = mat[i][j];
                    row = i;
                    column = j;
                }
            }
        }

        ans.push_back(row);
        ans.push_back(column);

        return ans;
    }
};