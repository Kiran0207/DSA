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
    void dfs(Node* node,unordered_map<Node*,Node*>&mapp,Node* newNode){
        vector<Node*>neigh=node->neighbors;
        for(auto i:neigh){
            if(mapp.find(i)==mapp.end()){
                Node* newNodee=new Node(i->val);
                mapp[i]=newNodee;
                newNode->neighbors.push_back(newNodee);
                dfs(i,mapp,newNodee);
            }
            else{
                newNode->neighbors.push_back(mapp[i]);
            }
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        Node* newNode=new Node(node->val);
        unordered_map<Node*,Node*>mapp;
        mapp[node]=newNode;
        dfs(node,mapp,newNode);
        return newNode;
    }
};