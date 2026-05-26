class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        sort(nums1.begin(), nums1.end());
        int k = nums1.size();
        int low = 0;
        int high = k-1;
        int mid = low + (high - low)/2;
        double ans = (double)nums1[mid];
        if (k % 2 == 0){
            ans = ((double)(nums1[mid] + nums1[mid+1])/2);
        }

        return ans;
    }
};