#include <iostream>
using namespace std;

// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 输入：
// {10,6,14,4,8,12,16}

// 返回值：
// From left to right are:4,6,8,10,12,14,16;
// From right to left are:16,14,12,10,8,6,4;
----------------------------------------------
// 输入：
// {5,4,#,3,#,2,#,1}

// 返回值：
// From left to right are:1,2,3,4,5;
// From right to left are:5,4,3,2,1;

// 说明：
//                     5
//                   /
//                 4
//               /
//             3
//           /
//         2
//       /
//     1
// 树的形状如上图 

// 说明：
// 输入题面图中二叉树，输出的时候将双向链表的头节点返回即可。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:

    void ConvertList(TreeNode* cur, TreeNode* &prev)
    {
        if(cur == NULL)
            return;

        ConvertList(cur->left, prev);
        //cur在这里出现的顺序就是中序，也就是有序

        //当前节点的左指向前一个
        cur->left = prev;
        //当前节点的右指向后一个，但是我不知道后一个是谁?
        //但是我知道前一个节点是谁，那么前一个节点右指针就可以指向我
        if(prev)
            prev->right = cur;
        prev = cur;  //这里更改在内部更改返回上一步中的prev，所以要用引用&（也可以用二级指针）

        ConvertList(cur->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {

        TreeNode* prev = NULL;
        ConvertList(pRootOfTree, prev);

        TreeNode* head = pRootOfTree;
        while(head && head->left)
        {
            head = head->left;
        }

        return head;

    }
};
