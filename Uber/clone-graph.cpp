#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
graphNode* cloneDfs(graphNode* node, unordered_map<graphNode*, graphNode*> &mp){
	// base case
	if (node == NULL) return node;
	if (mp.find(node) != mp.end()) return mp[node];

	// solution for one case
	graphNode* root = new graphNode(node->data);
	mp[node] = root;
	for (auto it : node->neighbours){
		root->neighbours.push_back(cloneDfs(it, mp));
	}

	return root;
}
graphNode *cloneGraph(graphNode *node)
{
    if (node == NULL) return node;
	unordered_map<graphNode*, graphNode*> mp;
	return cloneDfs(node, mp);
}