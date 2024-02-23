class Solution {
public:
    void fun(TreeNode* root,vector<int>&ve,int level )
    {
        if(root==NULL) return;
        if(level==ve.size()) ve.push_back(root->val);
        
        fun(root->right,ve,level+1);
        fun(root->left,ve,level+1);
       
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        fun(root,res,0);
        return res;
    }
};
