========================================================Traversal Techniques===========================================================

==============preorder traversal:(root,left,right)
void preorder(TreeNode* root,vector<int>&ve)
{
        if(root==NULL)
        {
            return;
        }
        ve.push_back(root->val);
        preorder(root->left,ve);
        preorder(root->right,ve);
}     
=============postorder traversal:(left,right,root)
void postorder(TreeNode* root,vector<int>&ve)
{
        if(root==NULL)
        {
            return;
        }
        
        postorder(root->left,ve);
       postorder(root->right,ve);
       ve.push_back(root->val);
} 
============inorder traversal:(left,root,right)
void inorder(TreeNode* root,vector<int>&ve)
{
        if(root==NULL)
        {
            return;
        }
        
        inorder(root->left,ve);
        ve.push_back(root->val);
       inorder(root->right,ve);
       
} 
===============level order:(will go level wise)
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=nullptr) 
                {
                    q.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            res.push_back(level);
        }
        return res;
    }
======================Zigzag order traversal (same as level order , but in this case we will reverse the array elements when row%2==0)
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        int c=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
            }
            vector<int>rev=level;
            reverse(level.begin(),level.end());
            if(c%2) res.push_back(level);
            else res.push_back(rev);
            c++;
        }
        return res;
    }
============================vertical order traversal ({root,{vertical,level}})
vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>res;

        //should consider a map
        map<int,map<int,multiset<int>>>mpp;

        queue<pair<TreeNode*,pair<int,int>>>q;

        q.push({root,{0,0}});
        while(!q.empty())
        {
           auto x=q.front();

            q.pop();
            TreeNode* temp=x.first;

            int vertical=x.second.first;
            int level=x.second.second;

            mpp[vertical][level].insert(temp->val);

            if(temp->left)
            {
                q.push({temp->left,{vertical-1,level+1}});
            }
            if(temp->right)
            {
                q.push({temp->right,{vertical+1,level+1}});
            }
        }
        for(auto it:mpp)
        {
            vector<int>col;
            for(auto i:it.second)
            {
                col.insert(col.end(),i.second.begin(),i.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
===============================================Boundary traversals(should return all the boundary elements)
void rightb(Node *root,vector<int>&ve)
    {
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL)
        {
            return;
        }
        if(root->right) rightb(root->right,ve);
        else rightb(root->left,ve);
        ve.push_back(root->data);
    }
    void leaf(Node *root,vector<int>&ve)
    {
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL)
        {
           // cout<<root->data;
            ve.push_back(root->data);
            return;
        }
        leaf(root->left,ve);
        leaf(root->right,ve);
    }
    void leftb(Node *root,vector<int>&ve)
    {
         if(root==NULL) return;
        if(root->left==NULL and root->right==NULL) return;
        ve.push_back(root->data);
        if(root->left!=NULL) leftb(root->left,ve);
        else leftb(root->right,ve);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(root==NULL) return {};
        stack<int>st;
        vector<int>ve;
        ve.push_back(root->data);
    
        leftb(root->left,ve);
        leaf(root->left,ve);
        leaf(root->right,ve);
        rightb(root->right,ve);
        
        return ve;
    }
=================================================================================================================================
