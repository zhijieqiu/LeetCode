/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 思路：使用中序遍历，一个中序遍历必然是一个有序的从小到大的序列
 交换其中任何两个节点必然导致这个有序序列发生变化，然后我们就需要找出这两个是的有序序列发生变化的节点就可以了
 使用beforeNode记录前一个节点
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
