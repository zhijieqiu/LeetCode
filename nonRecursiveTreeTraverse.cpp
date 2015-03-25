    #include <iostream>
    #include <stack>
    using namespace std;
    void nonRecursiveTraversePreOrder(TreeNode* root)
    {
        stack<TreeNode*> st;
        while(root)
        {
            st.push(root);
            cout<<root->val<<' ';
            root = root->left;
        }
        TreeNode *cur = nullptr;
        while(!st.empty())
        {
            cur = st.top();
            st.pop();
            
            if(cur->right==nullptr)
                continue;
            cur = cur->right;
            while(cur)
            {
                st.push(cur);
                cout<<cur->val<<' ';
                cur = cur->left;
            }
        }
        cout<<endl;
    }
    void nonRecursiveTraverseInorder(TreeNode* root)
    {
        stack<TreeNode*> st;
        while(root)
        {
            st.push(root);
            root = root->left;
        }
        TreeNode *cur = nullptr;
        while(!st.empty())
        {
            cur = st.top();
            st.pop();
            cout<<cur->val<<' ';
            if(cur->right==nullptr)
                continue;
            cur = cur->right;
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
        }
        cout<<endl;
    }
    int main()
    {
      TreeNode *root = new TreeNode(1);
      root->left = new TreeNode(2);
      root->right = new TreeNode(3);
      root->left->left = new TreeNode(4);
      root->left->right = new TreeNode(5);
      root->right->left = new TreeNode(6);
      root->right->right = new TreeNode(7);
      nonRecursiveTraversePreOrder(root);
      nonRecursiveTraverseInOrder(root);
      return 0;
    }
