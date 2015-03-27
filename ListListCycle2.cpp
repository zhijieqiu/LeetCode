/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //http://www.cnblogs.com/easonliu/p/3650677.html
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
            return NULL;
        ListNode* fast =head,*slow =head;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {  
                fast = head;//if it has cycle then move the fast pointer back to head then both slow and fast move forward util they meet each other
                while(fast)
                {
                    if(fast==slow)//meet then we got the cycle head
                        return slow;
                    fast = fast->next;
                    slow = slow->next;
                }
            }
        }
        return NULL;
    }
};
