bool isMatch(string& s,string& p,int index,int sIndex)
{
	if (sIndex == s.length()&&index == p.length())
		return true;
	if (index >= p.length())
		return false;
	if (sIndex>s.length())
		return false;
	if (index < p.length() - 1 && p[index + 1] == '*')
	{
		//isMatch("ab", ".*") → true
		if (p[index] == '.')
		{
			for (int i = sIndex; i < s.length(); i++)
			{
				if (isMatch(s, p, index + 2, i))
					return true;
			}
			return isMatch(s, p, index + 2, s.length());
		}
		for (int i = sIndex; i < s.length(); i++)
		{
			
			if (s[i] == p[index])
			{
				if (isMatch(s, p, index + 2, i+1))
					return true;
			}
			else
				break;
		}
		return isMatch(s, p, index + 2, sIndex);//*匹配空
	}
	else
	{
		if (s[sIndex] != p[index] && p[index] != '.')
			return false;
		else
		{
			return isMatch(s, p, index + 1, sIndex + 1);
		}
	}
	return false;
}
bool isMatch(const char *s, const char *p) {
	return isMatch(string(s), string(p), 0, 0);
}
