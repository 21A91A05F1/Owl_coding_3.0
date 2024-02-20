/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>res;
        if(root==NULL) return res;
        map<int,map<int,multiset<int>>>mpp;
        queue<pair<TreeNode*,pair<int,int>>>q;

        q.push({root,{0,0}});
        while(!q.empty())
        {
           auto top=q.front();
           q.pop();
           TreeNode* node=top.first;
           int vertical=top.second.first;
           int level=top.second.second;

           mpp[vertical][level].insert(node->val);

           if(node->left!=NULL) q.push({node->left,{vertical-1,level+1}});
           if(node->right!=NULL) q.push({node->right,{vertical+1,level+1}});

        }
        for(auto it1:mpp)
        {
            vector<int>temp;
            for(auto it2:it1.second)
            {
                for(auto it3:it2.second)
                {
                    temp.push_back(it3);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
