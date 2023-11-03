class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = m - 1, tt = 0;
        while(i <= j) {
            tt = i + (j - i) / 2;
            if(target > matrix[tt][n - 1]) {
                i = tt + 1;
            } else if(target < matrix[tt][0]) {
                j = tt - 1;
            } else {
                break;
            }
        }
        if(i <= j) {
            int s = 0, e = n - 1;
            while(s <= e) {
                int m = s + (e - s) / 2;
                if(matrix[tt][m] == target) {
                    return true;
                } else if(target > matrix[tt][m]) {
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            } 
        } return false;
    }
};