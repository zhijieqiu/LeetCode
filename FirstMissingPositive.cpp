int firstMissingPositive(int A[], int n) {
	int i = 0;
	/*for (int j = 0; j < n; j++)
		cout << A[j] << " ";
	cout << endl;*/
	while (i<n)
	{
		if (A[i] <= 0 || A[i] > n || A[i] == i + 1 || A[A[i] - 1] == A[i])//if the value is smaller than 1 than pass 
			i++;                                          // if the value is bigger than 1 then to see pass to see the next one
			                                             // if the value is in the right position then pass 
			                                             // remember if the right position just has the right value then pass
		else // otherwise we need to swap the current value to the right position
		{
			int t = A[i];   
			A[i] = A[t - 1];
			A[t - 1] = t;
			/*for (int j = 0; j < n; j++)
				cout << A[j] << " ";
			cout << endl;*/
		}
	}
	for (i = 0; i < n; i++)//find the first value which is not in the right position
	{
		if (A[i] != i + 1)
			return i + 1;
	}
	return n + 1;
}
