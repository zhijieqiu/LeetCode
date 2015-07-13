int sort(int sa[],int arr[], int left, int right,int tmp[],int result[]){
	if (left >= right) return 0;
	//if (left == right - 1) return 0;
	int mid = left + ((right - left) >> 1);
	int lcount = sort(sa,arr, left, mid, tmp,result);
	int rcount = sort(sa,arr, mid + 1, right, tmp,result);
	int t = left, i = left, j = mid + 1;
	int count = 0;
	while (i <= mid&&j <= right){
		if (sa[arr[i]] < sa[arr[j]]){
			result[arr[i]] += (right-j+1);
			tmp[t++] = arr[i++];
		}
		else{
			tmp[t++] = arr[j++];
		}
	}
	while (i <= mid)
		tmp[t++] = arr[i++];
	while (j <= right)
		tmp[t++] = arr[j++];
	cout << left << " ----   " << right << endl;
	for (int i = left; i <= right; i++){
		arr[i] = tmp[i];
		cout << arr[i] << " ";
	}
	cout << endl;

//	for ()
	return count + lcount + rcount;
}
int surpasser(int arr[], int n){
	int *tmp = new int[n];
	int *source = new int[n];
	int *result = new int[n];
	for (int i = 0; i < n; i++){
		source[i] = arr[i];
		arr[i] = i;
		result[i] = 0;
	}
	cout << sort(source,arr, 0, n - 1, tmp,result) << endl;
	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
