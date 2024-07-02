=======================================================================Tree Views=========================================================
  =====Top view( one with same level cannot be viewd from top)
  vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            Node* temp=q.front().first;
            int freq=q.front().second;
            
            q.pop();
            if(mpp.find(freq)==mpp.end()) 
            {
                mpp[freq]=temp->data;
            }
            if(temp->left!=NULL) q.push({temp->left,freq-1});
            if(temp->right!=NULL) q.push({temp->right,freq+1});
        }
        vector<int>ve;
        for(auto it:mpp) ve.push_back(it.second);
        return ve;
    }
=========================Bottom view(same as top view , but we come from down)
vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        while(!q.empty())
        {
            Node* temp=q.front().first;
            int freq=q.front().second;
            
            q.pop();
            
            mpp[freq]=temp->data;
            
            if(temp->left!=NULL) q.push({temp->left,freq-1});
            if(temp->right!=NULL) q.push({temp->right,freq+1});
            
        }
        vector<int>ve;
        for(auto it:mpp) ve.push_back(it.second);
        return ve;
    }
===================================Right view
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
