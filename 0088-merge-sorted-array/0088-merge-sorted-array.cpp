class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        int f = 0;
        int s = 0;

        vector<int> nums3;

        while(f < m && s < n) {
            if(nums1[f] <= nums2[s]) {
                nums3.push_back(nums1[f]);
                f++;
            }
            else {
                nums3.push_back(nums2[s]);
                s++;
            }
        }

        while(f < m) {
            nums3.push_back(nums1[f]);
            f++;
        }

        while(s < n) {
            nums3.push_back(nums2[s]);
            s++;
        }

        for(int i = 0; i < m+n; i++) {
            nums1[i] = nums3[i];
        }
    }
};