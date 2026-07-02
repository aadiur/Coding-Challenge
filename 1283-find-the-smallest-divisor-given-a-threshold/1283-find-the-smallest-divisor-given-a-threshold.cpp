class Solution {
public:
    int soln(vector<int>&nums,int mid){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/double(mid));
        }return sum;


    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=0;
        for(int i=0;i<n;i++){
            high=max(nums[i],high);
        }
        while(low<=high){
            int mid=(low+high)/2;
            int sum=soln(nums,mid);
            if(sum>threshold){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }return low;

        
    }
};