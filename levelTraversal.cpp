/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > ret;
    	vector<TreeNode*> levels[2];//轮转数组
    	vector<int> tmp;// to hold the information of the current level
    	int cur = 0;
    	if (root)
    	{
    		levels[cur].push_back(root);
    		tmp.push_back(root->val);
    		ret.push_back(tmp);
    	}
    	else
    		return ret;
    	while (true)
    	{
    		tmp.clear();
    		for (int i = 0; i < levels[cur].size(); i++)
    		{
    			if (levels[cur][i]->left)
    			{
    				tmp.push_back(levels[cur][i]->left->val);
    				levels[1 - cur].push_back(levels[cur][i]->left);
    			}
    			if (levels[cur][i]->right)
    			{
    				tmp.push_back(levels[cur][i]->right->val);
    				levels[1 - cur].push_back(levels[cur][i]->right);
    			}
    		}
    		if (levels[1 - cur].size() > 0)
    		{
    			ret.push_back(tmp);
    			levels[cur].clear();// remember to clear the array of the current one
    			cur = 1 - cur; //轮换数组
    		}
    		else
    			break;
    	}
    	return ret;
    }
};
