/*
 given a number of n queues, how to count the number of ways to place queues
 
*/

class Solution {
public:
    bool canPlace(int r,int c,vector<int> &cur)//to make sure where the new one is ok
    {
    	for(int i=0;i<cur.size();i++)
    	{
    		if(c==cur[i])// the queue is conflict with before queues for in the same column
    			return false;
    		if(abs(r-i-1)==abs(c-cur[i]))// the queue is conflict with before queues for with slap is 1 or -1
    			return false;
    	}
    	return true;
    }
    /*
    function name: countQueue
    row: the row need to place queue
    n: number of queues
    result: a out paramenter
    cur: a vector to store the before results
    */
    void countQueue(int row,int n,int &result,vector<int> cur)
    {
    	if(row==n+1)
    	{
    		/*for(int i=0;i<cur.size();i++)
    			cout<<cur[i]<<" ";
    		cout<<endl;*/
    		result++;
    		return;
    	}
    	for(int i=1;i<=n;i++)
    	{
    		if(canPlace(row,i,cur))
    		{
    			vector<int> tmp = cur;
    			tmp.push_back(i);
    			countQueue(row+1,n,result,tmp);
    		}
    	}
    }
    int totalNQueens(int n) {
    	vector<int> cur;
    	int result = 0;
    	countQueue(1,n,result,cur);
    	return result;
    }
};
