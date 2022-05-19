class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = nums.size();
        int start = 0, end = sz - 1;
        vector<int> ans(2,-1);
        while(start <= end) {
            int mid = start + (end - start)/2;
            if (target <= nums[mid]) {
                if (target == nums[mid]) ans[0] = mid;
                end = mid - 1;
            }
            else if (target > nums[mid]) start = mid + 1;
        }
        start = 0; end = sz - 1;
        while(start <= end) {
            int mid = start + (end - start)/2;
            if (target >= nums[mid]) {
                if (target == nums[mid]) ans[1] = mid;
                start = mid + 1;
            }
            else if (target < nums[mid]) end = mid - 1;
        }
        return ans;
    }
};