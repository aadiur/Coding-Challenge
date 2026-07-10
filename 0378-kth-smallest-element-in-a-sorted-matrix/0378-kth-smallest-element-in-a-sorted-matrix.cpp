class Solution {
public:
    int ul(vector<int>& row, int m, int target) {
        int low = 0;
        int high = m - 1;
        int ans = m;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (row[mid] > target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int countSmallEqual(vector<vector<int>>& matrix,
                        int n, int m, int target) {

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += ul(matrix[i], m, target);
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
                int n = matrix.size();
        int m = matrix[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = countSmallEqual(matrix, n, m, mid);
            if (cnt < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
        
    }
};