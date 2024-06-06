//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则返回 true 。否则，返回 false 。

//快慢指针

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    struct ListNode * slow = head;
    struct ListNode * fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}


证明快指针是如何追上慢指针的？
如果慢指针一次走一步，快指针一次走三步行不行？四步呢？n步？
假设慢指针进入环之后
fast和slow之间的距离是X
fast和slow按速度每走一次，他们之间距离缩小1步
X
X-1
X-2
X-3
...
0


如果fast一次走三步
X
X-2
X-4
X-6
...
如果X是奇数就会导致错过，不能相遇。如果错过以后，再算差距还是奇数。
就会导致下一次还是错过，如果极端情况下每次差距都是奇数，就会一直错过，无法相遇。
一次走N步，类似道理