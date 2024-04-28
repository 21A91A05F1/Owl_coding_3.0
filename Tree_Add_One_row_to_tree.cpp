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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int curr=1;
        if(depth==curr)
        {
            TreeNode* nroot=new TreeNode(val);
            nroot->left=root;
            return nroot;
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            while(size>0)
            {
                size--;
                TreeNode *node=q.front();
                q.pop();

                if(curr==depth-1)
                {
                    TreeNode* nleft=new TreeNode(val);
                    TreeNode* nright=new TreeNode(val);
                    if(node->left !=NULL)
                    {
                        nleft->left=node->left;
                    }
                    node->left=nleft;
                    if(node->right !=NULL)
                    {
                        nright->right=node->right;
                    }
                    node->right=nright;
                    q.push(nleft);
                    q.push(nright);
                }
                else
                {
                    if(node->left!=NULL) q.push(node->left);
                    if(node->right !=NULL) q.push(node->right);
                }
            }
            curr++;
        }
        return root;
    }
};
