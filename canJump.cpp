/*
思路：从开始往后面扫描，记录到目前为止能够跳的最远距离，如果下一个要准备的是的地方比最远的距离还远那么说明这次跳远也许是要失败了
直接跳出循环判断判断最大值是否超过了终点
*/
class Solution {// it is a test
public:
   bool canJump(int A[], int n) {
    	int maxi = 0;
    	for (int i = 0; i < n; i++)
    	{
    		maxi = maxi>(A[i] + i) ? maxi : (A[i] + i);
    		if(maxi>=n-1)
    		   return true;
    		if (maxi < i + 1)
    			break;
    	}
    	return maxi >= (n - 1);
    }
};
