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
//19. ɾ������ĵ����� N �����
ListNode* removeNthFromEnd(ListNode* head, int n) {
	//1.���������ȣ�ɾ����n���ڵ㡣
	//��������ɾ��ͷ���Ĳ���ͨ�������һ���ƽ��(dumpy)��ָ��ͷ���
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
	//2.����ָ�룬first����n-1����Ȼ��first��secondͬʱ��
	//first�ߵ�β��㣬second��������n���ڵ�
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

//21.�ϲ�������������
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	//1.�ݹ鷨��ÿ�η���һ���ڵ㣬����ڵ�ָ����һ�η��صĽڵ�
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
	//2.����������һ��listΪ�ռ��ϲ���ɣ���ʣ�µ������ȥ����
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
//23.�ϲ�k���������� 
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
	ListNode* ans = nullptr;
	for (int i = 0; i < lists.size() ; i++)
	{
		ans = mergeTwoLists(ans, lists[i]);
	}
	return ans;
}

//24. �������������еĽڵ�
ListNode* swapPairs(ListNode* head) {
	//1.��������һ�ν���2���ڵ�
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
	//2.�ݹ飬��ֹ����headΪ�ջ�head->nextΪ��
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* newhead = head->next;
	head->next = swapPairs(newhead->next);
	newhead->next = head;
}

