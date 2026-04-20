class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = 0;
        for(auto i : nums) {
            t ^= i;
        }

        return t;
    }
};