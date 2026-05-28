class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        if (find(nums.begin(), nums.end(), target) == nums.end()){
            nums.push_back(target);
            sort(nums.begin(), nums.end());

            int tlow = 0;
            int thigh = nums.size() - 1;

            while(tlow<=thigh){
                int tmid = tlow + (thigh - tlow)/2;

                if (nums[tmid] == target){
                    return tmid;
                }

                else if (nums[tmid] > target){
                    thigh = tmid - 1;
                }

                else{
                    tlow = tmid+1;
                }
            }
        }

        while(low<=high){
            int mid = low + (high - low)/2;

            if (nums[mid] == target){
                return mid;
            }

            else if (nums[mid] > target){
                high = mid - 1;
            }

            else{
                low = mid+1;
            }
        }

        return -1;

    }
};