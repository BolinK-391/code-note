#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 非递归迭代实现，二叉树的前序、中序、后序

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//前序遍历
class Preorder_Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        stack<TreeNode*> st; // 栈（先进后出） 用来储存节点，方便找右子树
        TreeNode* cur = root;

        while(cur || !st.empty())
        {
            // 1、先访问树左路节点
            // 2、再访问左路节点的右子树

            while(cur){
                ret.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            //取栈中左路节点的右子树出来访问
            TreeNode*top = st.top();
            st.pop();
            cur = top->right;
        }
        return ret;
    }
};


//中序遍历
class Inorder_Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        stack<TreeNode*> st; // 栈（先进后出） 用来储存节点，方便找右子树
        TreeNode* cur = root;

        while(cur || !st.empty())
        {
            // 1、先访问树左路节点
            // 2、再访问左路节点的右子树

            while(cur)
            {
                //ret.push_back(cur->val);   // 和前序遍历的区别点
                st.push(cur);
                cur = cur->left;
            }
            //取栈中左路节点的右子树出来访问
            TreeNode*top = st.top();
            ret.push_back(top->val);   // 和前序遍历的区别点
            st.pop();
            cur = top->right;
        }
        return ret;
    }
};


//后序遍历
class Postorder_Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        stack<TreeNode*> st; // 栈（先进后出） 用来储存节点，方便找右子树
        TreeNode* cur = root;

        while(cur || !st.empty())
        {
            // 1、先访问树右路节点
            // 2、再访问右路节点的左子树
            // 3、倒转ret数组（左右镜像前序遍历后反方向）

            while(cur)
            {
                ret.push_back(cur->val);
                st.push(cur);
                cur = cur->right;
            }
            //取栈中左路节点的右子树出来访问
            TreeNode*top = st.top();
            st.pop();
            cur = top->left;
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }
};