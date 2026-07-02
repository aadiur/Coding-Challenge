class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 1;

        for(auto it : st) {

            // Check if it is the start of a sequence
            if(st.find(it - 1) == st.end()) {

                int cnt = 1;
                int x = it;

                while(st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};