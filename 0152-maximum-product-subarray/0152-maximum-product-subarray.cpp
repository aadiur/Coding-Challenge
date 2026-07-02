class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre=1;
        int suf=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(suf==0)suf=1;
            if(pre==0)pre=1;
            pre=pre*nums[i];
            suf=suf*nums[n-i-1];
            maxi=max(maxi,max(pre,suf));

        }return maxi;
        
    }
};