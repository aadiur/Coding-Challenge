class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1=INT_MIN;
        int el2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0&&nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0&&nums[i]!=el1){
                el2=nums[i];
                cnt2=1;
            }
            else if(nums[i]==el1)cnt1++;
            else if(nums[i]==el2)cnt2++;
            else{
                cnt1--;
                cnt2--;
            }

        }
        cnt1=0;
        cnt2=0;
        vector<int>ls;
        int mini=(int)n/3+1;
        for(int i=0;i<n;i++){
            if(nums[i]==el1)cnt1++;
            if(nums[i]==el2)cnt2++;
        }
        if(cnt1>=mini)ls.push_back(el1);
        if(cnt2>=mini)ls.push_back(el2);
        return ls;
    }
};