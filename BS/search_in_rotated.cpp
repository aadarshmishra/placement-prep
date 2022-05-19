class Solution {
public:
    int bs(vector<int> &nums, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= target) high = mid - 1;
            else if (nums[mid] <= target) low = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1,minIdx, ans;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int prev = (mid - 1 + n) % n, next = (mid + 1) % n;
            if (nums[low] == nums[high]) {
                minIdx = low;
                break;
            }
            else if (nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
                minIdx = mid;
                break;
            }
            else if (nums[mid] <= nums[high]) high = mid - 1;
            else if (nums[mid] >= nums[low]) low = mid + 1;
        }
        ans = bs(nums,minIdx,n-1,target);
        if (ans != -1) return ans;
        ans = bs(nums,0,minIdx-1,target);
        if (ans != -1) return ans;
        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int start = 0, end = sz - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[start] <= nums[mid]) {
                if (nums[start] <= target and target <= nums[mid]) end = mid - 1;
                else start = mid + 1;
            }
            else {
                if (nums[mid] <= target and target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};