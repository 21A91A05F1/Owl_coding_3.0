class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=0;
        int n=nums.size();
        for(int i=0;i<n/2;i++)
        {
            m=max(m,nums[i]+nums[n-i-1]);
        }
        return m;
    }
};
