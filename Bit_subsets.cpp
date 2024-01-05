class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        int size=pow(2,n);
        for(int i=0;i<size;i++)
        {
            vector<int>ve;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))>0) //check if it's set bit
                {
                    ve.push_back(nums[j]);
                }
            }
            res.push_back(ve);
        }
        return res;
        /*
            To find the subsets
            The number of subsets for an array of size is given by
                2**(size of the array);
            we should find the position of setbits , the elements which are at that position , we will find the element at the given position of an array.
            Sample input: [1,2,3]
            size=2**(3)
                 1 2 3
            0 -> 0 0 0 at this bit representation there is no setbit []
            1 -> 0 0 1 set bit at 3 [3]
            2 -> 0 1 0 [2]
            3 -> 0 1 1 [2,3]
            4 -> 1 0 0 [1]
            5 -> 1 0 1 [1,3]
            6 -> 1 1 0 [1,2]
            7 -> 1 1 1 [1,2,3]
        */
    }
};
