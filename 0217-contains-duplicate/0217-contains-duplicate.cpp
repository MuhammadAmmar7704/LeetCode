class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set <int> ans;
        for(int i = 0; i < nums.size(); ++i)
            ans.insert(nums[i]);
        return nums.size() != ans.size();
    }
};