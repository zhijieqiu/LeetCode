int search(int A[], int n, int target) {
	int left = 0,right = n-1;
	while(left<right)
	{
		int mid = (left+right)>>1;
		if(A[mid]==target)
			return mid;
		else if(A[mid]>target)// we need find the new valid area which smaller then A[mid]
		{
			if(A[mid]<A[left])// it means there is peak between [left,mid]
				right = mid-1;// then it means we just need to search this range
			else
			{
				if(A[left]<=target)//it means [left,mid] is assending so if A[left]<=target then the search range is [left,mid-1]
					 right = mid-1;
				else   // it means [left,mid] is assending so if A[left]>target then the search range is [mid+1,right]
					left = mid+1;
			}
		}
		else// we need find the new valid area which greater then A[mid]
		{
			if(A[mid]<A[left])//it means there is peak between [left,mid]
			{
				if(target<=A[right])//from mid to right is assending, if target<=A[right],then new range is [mid+1,right]
					left = mid+1;
				else// if it is not in [mid+1,right] then it is in [left,mid-1]
					right = mid-1;
			}
			else   //it means we can just find target from [mid+1, right]
				left = mid+1;
		}
	}
	if(A[left]==target)
		return left;
	else
		return -1;
}
