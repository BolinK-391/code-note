//给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。

//插入排序 算法的步骤:
//插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//重复直到所有输入数据插入完为止。

//输入: head = [4,2,1,3]
//输出: [1,2,3,4]

#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node* sortHead = head;
    Node* cur = head->next;
    sortHead->next = NULL;
    while(cur)
    {
        Node *next = cur->next;

        //把cur插入到sortHead链表中，并且保持有序
        if(cur->val <= sortHead->val)
        {
            //头插
            cur->next = sortHead;
            sortHead = cur;
        }
        else
        {
            //中间插
            Node *sortPrev = sortHead;
            Node *sortCur = sortPrev->next;
            while (sortCur)
            {
                if(cur->val <= sortCur->val)
                {
                    sortPrev->next = cur;
                    cur->next = sortCur;
                    break;
                }
                else
                {
                    sortPrev = sortCur;
                    sortCur = sortCur->next;
                }
            }

            //尾插
            if(sortCur == NULL)
            {
                sortPrev->next = cur;
                cur->next = NULL;
            }
        }

        cur = next;
    }

    return sortHead;
}

//方法取结点往前面插入