/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
private:
	ListNode* reverse(ListNode * head)//reverse a linklist
	{
		if (!head || !head->next)
			return head;
		ListNode* ret = head;
		head = head->next;
		ret->next = NULL;
		while (head)//every time to move cur element back to front
		{
			ListNode* cur = head;
			head = head->next;//remember we need to do it before cur->next = ret;
			cur->next = ret;
			ret = cur;
		}
		return ret;
	}

public:
	void reorderList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return;
		ListNode *fast = head, *slow = head, *pre = NULL;
		while (fast&&fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		ListNode* secondHalf = reverse(slow);
		ListNode* tmp = new ListNode(0);
		while (head&&secondHalf)
		{
			tmp->next = head;
			head = head->next;
			tmp = tmp->next;
			tmp->next = secondHalf;
			secondHalf = secondHalf->next;
			tmp = tmp->next;
			
		}
		head != NULL ? tmp->next = head : tmp->next = secondHalf;
	}
};
