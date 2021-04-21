#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct ListNode
{

	float val;
	ListNode* next;
	ListNode()
	{

	}
	ListNode(float val,ListNode *next = nullptr)
	{
		this->val = val;
		this->next = nullptr;
	}

};

int listLength(ListNode *list);

#endif // !_LINKEDLIST_H_
//