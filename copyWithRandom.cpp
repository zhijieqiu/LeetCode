class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *aHead =head,*ret,*tmp = new RandomListNode(0);
        ret = tmp;
        map<RandomListNode*,RandomListNode*> mapInfo;
        while(aHead)
        {
            tmp->next = new RandomListNode(aHead->label);
            tmp = tmp->next;
            mapInfo[aHead] = tmp;
            aHead = aHead->next;
        }
        aHead = head;
        while(aHead)
        {
            if(aHead->random!=nullptr)
                mapInfo[aHead]->random = mapInfo[aHead->random];
            aHead = aHead->next;
        }
        return ret->next;
    }
};
