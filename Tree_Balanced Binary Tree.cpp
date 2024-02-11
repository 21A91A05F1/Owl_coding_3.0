int fun(TreeNode<int>* root)
{
    if(root==NULL) return 0;
    int lh=fun(root->left);
    int rh=fun(root->right);

    if(lh==-1 or rh==-1 or abs(lh-rh)>1) return -1;

    int h=1+max(lh,rh);
    return h;
}
bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    if(root==NULL) return true;

    if(fun(root)==-1) return false;
    return true;
}
