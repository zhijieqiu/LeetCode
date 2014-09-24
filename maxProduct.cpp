int maxProduct(int A[], int n) {
    int ret = 0;
  	if(1==n)// 当只有一个元素的时候直接返回
  	    return A[0];
    int *max_p = new int[n];
    int *max_n = new int[n];
    max_p[0] = A[0]>0?A[0]:0;
    max_n[0] = A[0]<0?A[0]:0;
  	ret = max(ret,max_p[0]);
    for(int i=1;i<n;i++)
    {
        if(A[i]>0)
        {
            int max1 = max_p[i-1]*A[i],max2=A[i];//如果A[i]大于0，那么下一个最大正数的来源就有可能有两种途径
  		    int min1 = max_n[i-1]*A[i];
  			max_p[i]=max(max1,max2);
  			max_n[i]=min1;
        }
        else if(A[i]<0)
        {
            int max1 = max_n[i-1]*A[i];
          	max_p[i] = max1;
  			int min1 = A[i]*max_p[i-1],min2 = A[i];////如果A[i]小于0，那么下一个最大负数的来源就有可能有两种途径
  			max_n[i]=min1<min2?min1:min2;
        }
        else
    	{
    		max_p[i]=0;
    		max_n[i]=0;
    	}
    	if(max_p[i]>ret)
    		ret = max_p[i];
    	cout<<max_p[i]<<'\t'<<max_n[i]<<endl;
    }
    	
    return ret;
}
