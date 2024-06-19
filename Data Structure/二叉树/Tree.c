#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "Tree.h"

//typedef char BTDataType;
//typedef struct BinaryTreeNode
//{
//    BTDataType _data;
//    struct BinaryTreeNode* _left;
//    struct BinaryTreeNode* _right;
//}BTNode;

void PrevOrder(BTNode* root){

    if(root == NULL)
    {
        printf("NULL\n");
        return;
    }

    printf("%d ",root->_data);
    PrevOrder(root->_left);
    PrevOrder(root->_right);
}

void _preorderTraversal(struct BinaryTreeNode* root,int* array,int* pi)
{
    if(root == NULL)
        return;
    //...
    array[(*pi)++] = root->_data;//使用指针,这样在递归的过程中，对同一个下标i++;
    //*i++;
    _preorderTraversal(root->_left,array,pi);
    _preorderTraversal(root->_right,array,pi);
}


int *preorderTraversal(struct BinaryTreeNode* root,int *returnSize)
{
    int size = TreeSize_2(root);
    int *array = (int*) malloc(sizeof (int)*size);
    int i = 0;
    _preorderTraversal(root,array,&i);

    *returnSize = size;
    return array;
}

void InOrder(BTNode* root){

    if(root == NULL)
    {
        //printf("NULL\n");
        return;
    }

    InOrder(root->_left);
    printf("%c ",root->_data);
    InOrder(root->_right);
}

//层序遍历
void BinaryLevelOrder(BTNode *root)
{
    //队列：先进先出
    //1、根先进队列
    //2、迭代 -> 队列不为空，出队头数据，同时把出的节点的左右孩子带进去
    //3、直到队列为空，结束

    Queue q;
    //这里要让保存的结构类型不能单单只是值，需要带上左右子树的地址，所以应该保存的结构类型为二叉树节点的地址 ( BinaryTreeNode* )
    QueueInit(&q);
    if(root == NULL)
        return;
    QueuePush(&q,root);

    while (!QueueEmpty(&q))
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);

        printf("%d ",front->_data);
        //节点出来，带左右子树节点进行
        if(front->_left)
            QueuePush(&q,front->_left);
        if(front->_right)
            QueuePush(&q,front->_right);
    }

    QueueDestroy(&q);
    printf("\n");
}

void TreeSize_1(BTNode* root,int* psize)
{
    if(root == NULL)
        return;

    else
        (*psize)++;

    TreeSize_1(root->_left,psize);
    TreeSize_1(root->_right,psize);
}

int TreeSize_2(BTNode* root)
{
   if(root == NULL)
       return 0;
   else
       return 1 + TreeSize_2(root->_left) + TreeSize_2(root->_right);
}

int TreeLeafSize(BTNode* root)
{
    if(root == NULL)
        return 0;
    if(root->_left == NULL && root->_right == NULL)
        return 1 ;

    return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}


BTNode *CreateNode(BTDataType x)
{
    BTNode *node = (BTNode*)malloc(sizeof (BTNode));
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;
}

int maxDepth(struct BinaryTreeNode* root)
{
    if(root == NULL)
        return 0;
    int leftDepth = maxDepth(root->_left);
    int rightDepth = maxDepth(root->_right);
    return leftDepth > rightDepth ? leftDepth + 1 :rightDepth + 1;
    //注意：这里是return数值，不是给rightDepth(leftDepth)赋值
}

struct BinaryTreeNode* intertTree(struct BinaryTreeNode* root)
{
    if(root == NULL)
        return 0;

}

//翻转二叉树

//前序遍历
struct BinaryTreeNode* invertTree_Front(struct BinaryTreeNode* root) {
    if(root == NULL)
        return NULL;
    else
    {
        struct TreeNode* tmp = root->_left;
        root->_left = root->_right;
        root->_right = tmp;

        invertTree_Front(root->_left);
        invertTree_Front(root->_right);
    }

    return root;
}

//后序遍历
struct BinaryTreeNode* invertTree_Back(struct BinaryTreeNode* root) {
    if(root == NULL)
        return NULL;
    else
    {
        struct BinaryTreeNode* tmp = root->_right;
        root->_right = invertTree_Back(root->_left);
        root->_left = invertTree_Back(tmp);

        return root;
    }
}

//确定相同的二叉树

bool isSameTree(struct BinaryTreeNode* p,struct BinaryTreeNode* q)
{
    if(p == NULL && q == NULL)
        return true;

    //结构不同
    if(p == NULL && q != NULL)
        return false;

    //结构不同
    if(p != NULL && q == NULL)
        return false;

    //值不同
    if(p->_data != q->_data)
        return false;

    return isSameTree(p->_left,q->_left)
        && isSameTree(p->_right,q->_right);
}


bool isSubtree(struct BinaryTreeNode* root, struct BinaryTreeNode* subRoot)
{
    if(root == NULL)
        return false;
    if(isSameTree(root,subRoot))
        return true;

    return isSubtree(root->_left,subRoot) || isSubtree(root->_right,subRoot);
    //遍历每个节点所在的子树，都比较一下
}

//判断是否是平衡二叉树(该树所有节点的左右子树的深度相差不超过 1 )
bool _isBalanced(struct BinaryTreeNode* root,int* pDepth)
{
    if(root == NULL)
    {
        *pDepth = 0;
        return true;
    }
    else
    {
        int leftDepth = 0;
        if(_isBalanced(root->_left,&leftDepth) == false)
            return false;
        int rightDepth = 0;
        if(_isBalanced(root->_right,&rightDepth) == false)
            return false;
        if(abs(leftDepth - rightDepth) > 1)
            return false;

        *pDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
        return true;
    }
}
//后序判断
//判断的同时把高度带给上一层的父亲

bool isBalanced(struct BinaryTreeNode* root)
{
    int depth = 0;
    return _isBalanced(root,&depth);
}

//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
//建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。


//将数组转化为先序遍历二叉树
BTNode *CreateTree(char* str,int* pi)
{
    if(str[*pi] == '#')
    {

        (*pi)++;
        return NULL;

    }
    else
    {
        BTNode *root = (BTNode*) malloc(sizeof (BTNode));
        root->_data = str[*pi];
        (*pi)++;
        root->_left = CreateTree(str,pi);
        root->_right = CreateTree(str,pi);

        return root;
    }
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{

    //当前树的第k层可以转换成左右子树的第k-1层
    //层数==1时就不需要再分解

    if(root == NULL)
        return 0;

    if(k == 1)
        return 1;
    return BinaryTreeLevelKSize(root->_left,k-1) + BinaryTreeLevelKSize(root->_right,k-1);
}


// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    if(root == NULL)
        return NULL;
    if(root->_data == x)
        return root;
    BTNode *node = BinaryTreeFind(root->_left,x);
    if (node)
        return node;
    node = BinaryTreeFind(root->_right,x);
    if(node)
        return node;

    return NULL;

}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
    if(root == NULL)
        return;
    BinaryTreeDestory((*root)->_left);
    BinaryTreeDestory((*root)->_right);
    free(*root);
    *root = NULL;
}


// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
    //是返回1，不是返回0
    Queue q;
    QueueInit(&q);
    if(root == NULL)
        return 1;
    QueuePush(&q,root);
    while(!QueueEmpty(&q))
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);

        if(front == NULL)
        {
            break;
        }

        QueuePush(&q,front->_left);
        QueuePush(&q,front->_right);
    }

    while (!QueueEmpty(&q))
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);

        if(front)
        {
            QueueDestroy(&q);
            return 0;
        }
    }

    QueueDestroy(&q);
    return 1;
}


int main()
{
    BTNode *A = CreateNode(1);
    BTNode *B = CreateNode(2);
    BTNode *C = CreateNode(3);
    BTNode *D = CreateNode(4);
    BTNode *E = CreateNode(5);
    BTNode *F = CreateNode(6);
    A->_left = B;
    A->_right = C;
    B->_left = D;
    B->_right = E;
    C->_left = F;

    BTNode *root = CreateNode(1);
    BTNode *root_left = CreateNode(1);
    BTNode *Subroot = CreateNode(1);

    root->_left = root_left;

    isSubtree(root,Subroot);

    printf("\n%d ", isSubtree(root,Subroot));
    PrevOrder(A);


    printf("\n\n");

    int sizeA = 0;
    TreeSize_1(A,&sizeA);
    printf("TreeSize:%d\n",sizeA);

    int sizeB = 0;
    TreeSize_1(B,&sizeB);
    printf("TreeSize:%d\n",sizeB);

    int size_A = TreeSize_2(A);
    printf("TreeSize:%d\n",size_A);

    int sizeleaf = TreeLeafSize(A);

    printf("TreeLeafSize:%d\n",sizeleaf);
    int r = 0;
    int * arr = preorderTraversal(A,&r);
    for(int i = 0; i < r; i++)
    {
        printf("%d ",arr[i]);
    }

    BinaryLevelOrder(A);

    char str[100];
    scanf("%s",str);

    int i = 0;
    BTNode *root_Tree = CreateTree(str,&i);

    InOrder(root_Tree);

    return 0;


}

