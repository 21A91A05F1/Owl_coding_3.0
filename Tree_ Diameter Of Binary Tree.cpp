int d=0;
int fun(TreeNode<int> *root)
{
    if(root==NULL) return 0;
    int lh=fun(root->left);
    int rh=fun(root->right);

    d=max(d,lh+rh);

    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    fun(root);
    return d;
}
