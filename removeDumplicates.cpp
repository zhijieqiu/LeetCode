class Solution {
public:
   int removeDuplicates(int A[], int n) {
    	if (n == 0)
    		return 0;
    	int curElement = A[0], nextSlot = 1, count = 1;
    	int total = 1;
    	for (int i = 1; i < n; i++)
    	{
    		if (A[i] == curElement)
    		{
    			if (count >= 2)
    			{
    				continue;
    			}
    			else
    			{
    				A[nextSlot] = A[i];
    				nextSlot++;
    				total++;
    			}
    			count++;
    		}
    		else
    		{
    			A[nextSlot] = A[i];
    			count = 1;
    			nextSlot++;
    			curElement = A[i];
    			total++;
    		}
    	}
    	return total;
    }
};
