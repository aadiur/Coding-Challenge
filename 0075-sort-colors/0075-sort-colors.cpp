class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[start],nums[mid]);
                start++;
                mid++;
                
                }
            else if(nums[mid]==1){
                mid++;

            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }                
        }

        
    }
};