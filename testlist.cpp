#include <iostream>
using namespace std;
#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    return nullptr;
}
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *next;
    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
ListNode *swapPairs(ListNode *head)
{
    ListNode *succ;
    succ = head->next;
    while (succ != nullptr && succ->next->next != nullptr)
    {
        head->next = succ->next->next;
        succ->next = head;
        head = head->next->next;
        succ = succ->next->next;
    }
    return head;
}
ListNode *vector2list(vector<int> vec)
{
    ListNode *dummy = new ListNode(0);
    ListNode *node = dummy;
    for (const int &c : vec)
    {
        ListNode *node1 = new ListNode(c);
        node->next = node1;
        node = node->next;
    }

    return dummy->next;
}
ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
        return nullptr;
    auto dummy = new ListNode(109), tail = dummy;
    while (head)
    {
        if (tail->val != head->val)
        {
            tail->next = head;
            tail = tail->next;
        }
        head = head->next;
    }
    tail->next = nullptr;
    return dummy->next;
}
void printList(ListNode *node)
{
    while (node)
    {
        cout << node->val << endl;
        node = node->next;
    }
}
/*
对于链表的操作有几点需要牢记：

1. 需要对链表进行有效性判断

2. 对于链表的操作过程中，首先要创建一个节点，并将头结点复制给新节点

3.如果要构建新的链表是，表头需要单独保存；同时每个节点需要创建新节点，完成赋值、指针操作；组后需要一个游标节点，负责将各个节点串联起来。

4.对于尾节点，最后一定要将其next指向NULL。
————————————————
版权声明：本文为CSDN博主「liuhuiyi」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/liuhuiyi/article/details/8688658
*/
ListNode *copyList(ListNode *node)
{
    if(node==nullptr) return nullptr;
    ListNode* pivot=node;//指针指向
    //根据指针所指的内容创建节点
    ListNode *pnode=new ListNode();
    ListNode* mnode=pnode;
    while(pivot)
    {
        ListNode* newnode=new ListNode(pivot->val);
        mnode->next=newnode;
        mnode=mnode->next;
        pivot=pivot->next;
    }
    return pnode->next;

    
}
//1、迭代反转列表法，需要三个指针
//当前链表的首元节点开始，一直遍历至链表的最后一个节点，这期间会逐个改变所遍历到的节点的指针域，另其指向前一个节点
ListNode *iterationReverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *next;
    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
//最终返回的节点是prev,因为head已经是空了

//2、递归反转链表
//递归反转法的实现思想是从链表的尾节点开始，依次向前遍历，遍历过程依次改变各节点的指向，即另其指向前一个节点
ListNode *recursiveReverse(ListNode *head)
{
    //递归结束
    if (head == nullptr || head->next == nullptr)
    {
        return head; //空链或者有只有一个节点
    }
    ListNode *newhead = recursiveReverse(head->next);
    //当逐层退出时，new_head 的指向都不变，一直指向原链表中最后一个节点；
    //递归每退出一层，函数中 head 指针的指向都会发生改变，都指向上一个节点。
    //每退出一层，都需要改变 head->next 节点指针域的指向，同时令 head 所指节点的指针域为 NULL。
    head->next->next = head;
    head->next = nullptr;
    return newhead;
}
//可以补一张图
//3、头插法
ListNode *headReverse(ListNode *head)
{
    ListNode *newhead = nullptr;
    ListNode *temp;
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    while (head)
    {
        temp = head;
        //将 temp 从 head 中摘除
        head = head->next; //更新

        temp->next = newhead; //temp是要插在节点的前面，然后更新temp
        newhead = temp;
    }
    return newhead;
}
//4、就地反转法,多两个指针
ListNode *localRreverse(ListNode *head)
{
    ListNode *beg = NULL;
    ListNode *end = NULL;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    beg = head;
    end = head->next;
    while (end != NULL)
    {
        //将 end 从链表中摘除
        beg->next = end->next;
        //将 end 移动至链表头
        end->next = head;
        head = end;
        //调整 end 的指向，另其指向 beg 后的一个节点，为反转下一个节点做准备
        end = beg->next;
    }
    return head;
}
//5、反转前N个节点，使用递归的方法

ListNode *succOnlyone = nullptr;
ListNode *recursiveReverseN(ListNode *head, int n)
{

    if (n == 1)
    {
        succOnlyone = head->next;
        return head;
    }
    ListNode *last = recursiveReverseN(head->next, n - 1);
    head->next->next = head;
    head->next = succOnlyone;
    return last;
}
//删除链表中重复的节点
ListNode *deleteDuplicationAndSaveone(ListNode *pHead) //去重
{
    if (pHead == nullptr || pHead->next == nullptr)
    {
        return pHead;
    }
    ListNode *dummy = new ListNode();
    dummy->next = pHead;
    //初始化完毕
    ListNode *prev = dummy;
    while (pHead)
    {
        if (pHead->val != prev->val)
        {
            prev = prev->next;
            pHead = pHead->next;
        }
        else
        {
            prev->next = pHead->next;
            pHead = pHead->next;
        }
    }
    return dummy->next;
}

//删除链表中重复的节点，出现重复的一个不留
ListNode *deleteDuplication(ListNode *pHead) //
{
    if (pHead == nullptr || pHead->next == nullptr)
    {
        return pHead;
    }
    ListNode *dummy = new ListNode();
    dummy->next = pHead;
    //初始化完毕
    ListNode *prev = dummy;
    ListNode *succ;
    succ = pHead->next; //注意一边是指针赋值，一边是节点复制  这里需要对点进行操作。
    while (succ && pHead)
    {
        if (pHead->val != succ->val)
        {
            prev = prev->next;
            pHead = pHead->next;
            succ = succ->next;
        }
        else
        {
            while (pHead->val == succ->val)
            {
                pHead = pHead->next;
                succ = succ->next;
            }
            prev->next = succ;
            pHead = pHead->next;
            succ = succ->next;
        }
    }
    return dummy->next;
}
ListNode *deleteDuplicationCopy(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;

    ListNode *dummyHead = new ListNode(0); //构造一个呀节点

    auto preNode = dummyHead;
    preNode->next = pHead;
    //初始的两个指针初始化
    auto curNode = pHead;

    while (curNode && curNode->next)
    {
        if (curNode->val == curNode->next->val)
        {
            while (curNode->val == curNode->next->val)
                curNode = curNode->next; //小循环内一直在走

            preNode->next = curNode->next;
            curNode = curNode->next;
        }
        else
        {
            preNode = curNode;
            curNode = curNode->next;
        }
    }

    return dummyHead->next;
}

void test1()
{
    vector<int> vec{1, 2, 3, 4};
    ListNode *node = vector2list(vec);
    printList(node);
    cout << "***********" << endl;
    ListNode *rev = reverseList(node); //在这里node已经被更改
    printList(rev);
    cout << "***********" << endl;
    ListNode *rev1 = iterationReverseList(vector2list(vec));
    printList(rev1);
    cout << "***********" << endl;
    ListNode *rev2 = iterationReverseList(vector2list(vec));
    printList(rev2);
    cout << "***********" << endl;
    ListNode *rev3 = headReverse(vector2list(vec));
    printList(rev3);
    cout << "***********" << endl;
    ListNode *rev4 = localRreverse(vector2list(vec));
    printList(rev4);
    cout << "***********" << endl;
}

void test2()
{
    vector<int> vec{1, 2, 3, 3, 4, 4, 5, 6};
    ListNode *node = vector2list(vec);
    printList(node);
    ListNode *rec = deleteDuplication(node);
    printList(rec);
    ListNode *rec1 = deleteDuplicationCopy(vector2list(vec));
    printList(rec1);
}

//链表中倒数第k个结点
ListNode *getKthFromEnd(ListNode *head, int k)
{
    ListNode* fast=head;
    ListNode* slow=head;
    int count=0;
    while(fast)
    {
        if(count>=k)
        {
            slow=slow->next;
        }
        fast=fast->next;
        count++;
        
    }
    return slow;
}

void test3()
{
    vector<int> vec{1, 2, 3, 3, 4, 4, 5, 6};
    ListNode *node = vector2list(vec);
    printList(getKthFromEnd(node,2));
    
}
void test4()
{
    vector<int> vec{1, 2, 3, 3, 4, 4, 5, 6};
    ListNode *node = vector2list(vec);
    printList(node);
    ListNode *node1=copyList(node);
    printList(node1);

}
int main()
{
    
    test4();

    return 0;
}
