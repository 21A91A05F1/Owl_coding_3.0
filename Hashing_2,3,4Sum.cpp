1. Two Sum
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

  class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(target-nums[i])!=mpp.end())
            {
                //if tagret-nums[i] exsists then this block gets executed
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                  for(auto it: mpp)
                {
                    cout<<it.first<<" "<<it.second<<endl;
                }
                return ans;
            }
          
            mpp[nums[i]]=i;
            
        }
        return ans;
    }
};


15. 3Sum
  Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

sum<target i,j++;
sum>target k--;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // optimal code using 3 poniters
        /*
        if sum<0 i will remain constant j should be incremented
        if sum>0 we should decrement the k.
        */
        vector<vector<int>>ve;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int s=nums[i]+nums[j]+nums[k];
                if(s<0) j++;
                else if(s>0) k--;
                else
                {
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ve.push_back(temp);
                    j++;
                    k--;
                    while(j<k and nums[j]==nums[j-1]) j++;
                    while(j<k and nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ve;
    }
};


18. 4Sum
Solved
Medium
Topics
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

  Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


  sum< target i,j,k++;
sum>target l--;

  class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target)
                    {
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l and nums[k]==nums[k-1]) k++;
                        while(k<l and nums[l]==nums[l+1]) l--;
                    }
                    else if(sum>target) l--;
                    else k++;

                    }
            }
        }
        return ans;
    }
};
