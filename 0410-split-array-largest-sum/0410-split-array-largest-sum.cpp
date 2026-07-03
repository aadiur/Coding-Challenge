class Solution {
public:
    int checker(vector<int>& nums, int mid) {
        int subarrays = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (sum + nums[i] > mid) {
                subarrays++;
                sum = nums[i];
            }
            else {
                sum += nums[i];
            }

        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = 0;
        int high = 0;

        for (int i = 0; i < nums.size(); i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }

        while (low <= high) {

            int mid = (low + high) / 2;

            int subarrays = checker(nums, mid);

            if (subarrays > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};