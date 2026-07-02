class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int cost=prices[i]-mini;
            if(cost>profit){
                profit=cost;
            }
            if(prices[i]<mini){
                mini=prices[i];
            }
        }return profit;

        
    }
};