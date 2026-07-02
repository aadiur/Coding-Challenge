class Solution {
public:
    bool fn(vector<int>nums,int mid,int m,int k){
        int n=nums.size();
        int cnt=0;
        int no=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                cnt++;
                

            }
            else{
                no+=(cnt/k);
                cnt=0;

            }
        }no+=(cnt/k);
        return no>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        long long val=(long long)m*k;
        int n=bloomDay.size();
        if(val>n)return -1;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        
        }
        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(fn(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }return low;

        
        
        
    }
};