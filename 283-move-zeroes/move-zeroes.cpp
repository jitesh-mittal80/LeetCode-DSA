class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i=0; i<n; i++){
            if (nums[i] == 0){
                count++;
            }
        }

        int k =0;
        int remian = n - count;
        vector<int> ans(remian);
        for (int j = 0; j<n; j++){
            if (nums[j] != 0){
                ans[k] = nums[j];
                k++;
            }
        }
        int x = 0;
        for (int a = 0; a<remian ; a++){
            nums[a] = ans[x];
            x++; 
        }

        for (int b = remian; b<n; b++){
            nums[b] = 0;
        }

    }
};