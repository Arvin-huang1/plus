#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct ListNode
{

	float value;
	ListNode* next;
	ListNode()
	{

	}
	ListNode(float value,ListNode *next = nullptr)
	{
		this->value = value;
		this->next = nullptr;
	}
	
};
 
int ListLength(ListNode *list);

#endif // !_LINKEDLIST_H_
//