class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
    	if(!head||!head->next)
    		return head;
    	//每次从最开始扫描，前面的部分是已经排好序了的，后面的部分是没有排好序的，lastNode记录最后一个排好序的元素
    	//lastBefore 每次记录扫描的最后一个比当前的元素小的元素
    	ListNode* cur = head->next,*lastBefore = nullptr,*lastNode = head;
    	while(cur)//cur represent the next element need to insert , the nodes before the node is in order
    	{
    		ListNode* headTmp = head,*lastBefore = nullptr;
    		while(cur->val>headTmp->val)
    		{
    			lastBefore = headTmp;
    			headTmp = headTmp->next;
    		}
    		if(lastBefore==nullptr)
    		{
    			lastNode->next = cur->next;
    			cur->next = head;
    			head = cur;
    			cur = lastNode->next;
    		}
    		else if(headTmp == cur)
    		{
    			lastNode = cur;
    			cur = cur->next;
    		}
    		else {
    			lastNode->next = cur->next;
    			lastBefore->next = cur;
    			cur->next = headTmp;
    			cur = lastNode->next;
    		}
    	}
    	return head;
    }
};
