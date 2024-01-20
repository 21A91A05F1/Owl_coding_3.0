class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root->val==p->val or root->val==q->val) return root;
        TreeNode* l=NULL;
        TreeNode* r=NULL;
        l=lowestCommonAncestor(root->left,p,q);
        r=lowestCommonAncestor(root->right,p,q);
        if(l==NULL) return r;
        else if(r==NULL) return l;
        else return root;
     }
};
