class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n);
        int pos=0;
        int neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                arr[pos]=nums[i];
                pos+=2;
            }else{
                arr[neg]=nums[i];
                neg+=2;
            }
        }return arr;
        
    }
};