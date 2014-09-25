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
private:
    TreeNode *beforeNode=NULL,*node1=NULL,*node2=NULL;
public:
    void recoverTree2(TreeNode *root) {
    	if(root==NULL)
    		return;
    	if(root->left)
    		recoverTree2(root->left);
    	if(beforeNode!=NULL&&root->val<beforeNode->val)
    	{
    		if(node1==NULL)
    		{
    			node1 = beforeNode;
    			node2 = root;
    		}
    		else
    			node2= root;
    	}
    	beforeNode = root;
    	if(root->right)
    		recoverTree2(root->right);
    }
    void recoverTree(TreeNode* root)
    {
    	recoverTree2(root);
    	int val = node1->val;
    	node1->val = node2->val;
    	node2->val = val;
    }
};
