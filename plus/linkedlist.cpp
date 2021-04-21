#include "linkedlist.h"
#include "vector"


int listLength(ListNode *list)
{

	int len = 0;
	while (list != nullptr)
	{
		len++;
		list = list->next ;
	}
	return len;
}
//19. 删除链表的倒数第 N 个结点
ListNode* removeNthFromEnd(ListNode* head, int n) {
	//1.计算链表长度，删除第n个节点。
	//对于链表删除头结点的操作通常是添加一个哑结点(dumpy)，指向头结点
	/*
	if (head->next == nullptr)
		return nullptr;
	int len = listLength(head);
	if (len == n)
		return head->next;
	ListNode* ans = head;
	ListNode* tmp = head;
	for (int i = 0; i < len - n - 1; i++)
	{
		tmp = tmp->next;
	}
	tmp->next = tmp->next->next;
	return ans;
	*/
	//2.快慢指针，first先走n-1步，然后first、second同时走
	//first走的尾结点，second即倒数第n个节点
	ListNode* first = head;
	ListNode* dumpy = new ListNode(0, head);
	ListNode* second = dumpy;
	for (int i = 0; i < n-1 ; i++)
	{
		first = first->next;
	}
	while (first->next)
	{
		first = first->next;
		second = second->next;
	}
	second->next = second->next->next;
	return dumpy->next;

}

//21.合并两个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	//1.递归法，每次返回一个节点，这个节点指向下一次返回的节点
	/*
	if (!l1) {
		return l2;
	}
	if (!l2) {
		return l1;
	}
	if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}*/
	//2.迭代法，当一个list为空即合并完成，把剩下的添加上去即可
	ListNode* dumpy = new ListNode(-1);
	ListNode* tmp = dumpy;
	while (l1 != nullptr && l2!=nullptr)
	{
		if (l1->val < l2->val)
		{
			tmp->next = l1;
			l1 = l1->next;
		} 
		else
		{
			tmp->next = l2;
			l2 = l2->next;
		}
		tmp = tmp->next;
	}
	tmp->next = (l1 == nullptr) ? l2 : l1;
	return dumpy->next;

}
//23.合并k个有序链表 
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
	ListNode* ans = nullptr;
	for (int i = 0; i < lists.size() ; i++)
	{
		ans = mergeTwoLists(ans, lists[i]);
	}
	return ans;
}

//24. 两两交换链表中的节点
ListNode* swapPairs(ListNode* head) {
	//1.迭代法，一次交换2个节点
	/*
	ListNode* dumpy = new ListNode(0, head);
	ListNode* cur = dumpy;
	while (cur->next && cur->next->next)
	{
		ListNode* node_1 = cur->next;
		ListNode* node_2 = cur->next->next;
		cur->next = node_2;
		node_1->next = node_2->next;
		node_2->next = node_1;
		cur = node_1;
	}
	return dumpy->next;
	*/
	//2.递归，终止条件head为空或head->next为空
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* newhead = head->next;
	head->next = swapPairs(newhead->next);
	newhead->next = head;
}

