class Solution {
public:
    int maxe(vector<int>&v){
        int maxi=INT_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            maxi=max(v[i],maxi);
        }
        return maxi;
    }
    long long count(vector<int>&v,int m){
        int n=v.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt=cnt+ceil((double)v[i]/(double)m);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=maxe(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long long num=count(piles,mid);
            if(num<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }return low;
        
    }
};