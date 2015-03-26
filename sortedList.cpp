class Solution {	
private:
	ListNode* merge(ListNode* left,ListNode* right)
	{
		if (left == nullptr || right == nullptr)
			return left == nullptr ? right : left;
		ListNode *head =new ListNode(0),*ret = head;//设定一个头标兵，方便编程
		while (left&&right)
		{
			if (left->val < right->val)
			{
				ret->next = left;
				left = left->next;
			}
			else
			{
				ret->next = right;
				right = right->next;
			}
			ret = ret->next;
		}
		left != nullptr ? left = left : left = right;
		ret->next = left;
		return head->next;
	}
public:
	ListNode *sortList(ListNode *head) {
		if (head == nullptr||head->next==nullptr)
			return head;
		ListNode * fast = head, *slow = head,*pre=nullptr;
		//快慢指针找到中点，中点就是slow，使用pre记录中点的上一个节点
		while (fast&&fast->next)
		{
		  pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = nullptr;
		ListNode*left = sortList(slow);
		ListNode* right = sortList(head);
		return merge(left,right);
	}
};
