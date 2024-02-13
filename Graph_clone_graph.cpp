/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node==NULL) return NULL;
    //map is used to keep track of mapping between original nodes and corresponding cloned nodes
        unordered_map<Node*,Node*>mpp;
        queue<Node*>q;
    //this indicates the first node in the cloned graph.
        Node* copy= new Node(node->val,{});
     //The mapping between the original and cloned nodes is stored in the unordered map 
        mpp[node]=copy;
        q.push(node);

        //bfs
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();

            for(auto it:curr->neighbors)
            {
                if(mpp.find(it)==mpp.end())
                {
                //For each neighbor, it checks if the neighbor is already in the map.
                // If not, a new node (copy1) is created with the neighbor's value, and the mapping is updated in the map.
                    Node* copy1=new Node(it->val,{});
                    mpp[it]=copy1;
                    q.push(it);
                }
              //  Finally, the code updates the neighbors of the cloned current node by pushing the corresponding cloned neighbor (mpp[it]) into the neighbors vector.
                mpp[curr]->neighbors.push_back(mpp[it]);
            }
        }
       
        return copy;
    }
};
