/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	ListNode *ptr1 = l1, *ptr2 = l2;
	ListNode *ptr = head;
	ListNode *preptr = NULL;
	int carry = 0;
	while(ptr1 != NULL && ptr2 != NULL)
	{
		ptr -> val = (ptr1 -> val + ptr2 -> val + carry) % 10;
		carry = (ptr1 -> val + ptr2 -> val + carry) / 10;
		ListNode *node = (ListNode*)malloc(sizeof(ListNode));
		ptr -> next = node;
		preptr = ptr;
		ptr = node;
		ptr1 = ptr1 -> next;
		ptr2 = ptr2 -> next;
	}
	if(ptr1 == NULL)
	{
		while(ptr2 != NULL)
		{
			ptr -> val = (ptr2 -> val + carry) % 10;
			carry = (ptr2 -> val + carry) / 10;
			ListNode *node = (ListNode*)malloc(sizeof(ListNode));
			ptr -> next = node;
			preptr = ptr;
			ptr = node;
			ptr2 = ptr2 -> next;
		}
	}
	else if(ptr2 == NULL)
	{
		while(ptr1 != NULL)
		{
			ptr -> val = (ptr1 -> val + carry) % 10;
			carry = (ptr1 -> val + carry) / 10;
			ListNode *node = (ListNode*)malloc(sizeof(ListNode));
			ptr -> next = node;
			preptr = ptr;
			ptr = node;
			ptr1 = ptr1 -> next;
		}
	}
	if(ptr1 == NULL && ptr2 == NULL)
	{
		if(carry != 0)
		{
			ptr -> val = carry;
			preptr = ptr;
		}
	}
    preptr -> next = NULL;
    return head;
}