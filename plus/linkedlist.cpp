#include "linkedlist.h"

int ListLength(ListNode *list)
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
	int len = ListLength(head);
	ListNode* ans = head;
	ListNode* tmp = head;
	for (int i = 0; i < len -n -1; i++)
	{
		tmp = tmp->next;
	}
	tmp->next = tmp->next->next;
	return ans;
}