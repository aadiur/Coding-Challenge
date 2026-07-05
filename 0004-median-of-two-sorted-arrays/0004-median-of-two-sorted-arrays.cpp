class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ind1=(n1+n2)/2;
        int ind2=ind1-1;
        int j=0;
        int i=0;
        int cnt=0;
        int el1=-1;
        int el2=-1;
        while(i<n1&&j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1)el1=nums1[i];
                if(cnt==ind2)el2=nums1[i];
                i++;
                cnt++;


            }
            else{
                if(cnt==ind1)el1=nums2[j];
                if(cnt==ind2)el2=nums2[j];
                j++;
                cnt++;


            }
           
        }
        while(i<n1){
                if(cnt==ind1)el1=nums1[i];
                if(cnt==ind2)el2=nums1[i];
                i++;
                cnt++;
        }
        while(j<n2){
            if(cnt==ind1)el1=nums2[j];
            if(cnt==ind2)el2=nums2[j];
            j++;
            cnt++;
        }
        if((n1+n2)%2==1){
            return el1;
        }
        else{
            return ((double)el1+(double)el2)/2.0;
        }

        
            

        
    }
};