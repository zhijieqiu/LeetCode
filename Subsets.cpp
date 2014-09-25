
/*
method:subsets
count:the subset element number
fromIndex: the current begin index to search
cur:the cur elements in current subset
result:to hold the subsets
*/
void subsets(int count,int fromIndex, vector<int> cur, vector<vector<int> >& result,vector<int>& S)
{
	if (cur.size() == count)
	{
		result.push_back(cur);
		return;
	}
	for (int i = fromIndex; i < S.size(); i++)
	{
		vector<int> tmp = cur;
		tmp.push_back(S[i]);
		if (tmp.size() + S.size() - i - 1 < count)//if the current element add all the rest elements still small then count 
		                                          //then there is no need to add go on the way
			continue;
		subsets(count, i + 1, tmp, result, S);
	}
}
vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int> > ret;
	ret.push_back(vector<int>());//the empty subset must add here
	sort(S.begin(), S.end());
	for (int i = 1; i <= S.size(); i++)
	{
		subsets(i, 0, vector<int>(), ret, S);//add the subset which has i element
	}
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	return ret;
}
