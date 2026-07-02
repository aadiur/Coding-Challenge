class Solution {
public:
    int checker(vector<int>&nums,int mid){
        int n=nums.size();
        int days=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]+cnt>mid){
                cnt=nums[i];
                days++;

            }
            else{
                cnt+=nums[i];
                
            }
        }return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxi=weights[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,weights[i]);

        }int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];

        }
        while(maxi<=sum){
            int mid=(maxi+sum)/2;
            int d=checker(weights,mid);
            if(d<=days){
                sum=mid-1;

            }
            else{
                maxi=mid+1;
            }



        }return maxi;
        
    }
};