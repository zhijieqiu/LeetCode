/*
  s the string 
  p pattern
  index the index to be matched of s
  sIndex the index to be matched of p
*/
bool isMatch(string& s,string& p,int index,int sIndex)
{
	if (sIndex == s.length()&&index == p.length()) //if both reach the end then return true
		return true;
	if (index >= p.length()) // if index==p.length and sIndex doesn't reach the end ,return false
		return false;
	if (sIndex>s.length())
		return false;
	if (index < p.length() - 1 && p[index + 1] == '*')
	{
		//isMatch("ab", ".*") → true
		//如果 p[index]=='.' 并且 p[index+1]=='*'那么 .* 就可以匹配任意多个的字符串，尝试其中的每一种，只要有能匹配
		//的就可以
		if (p[index] == '.')
		{
			for (int i = sIndex; i < s.length(); i++)
			{
				if (isMatch(s, p, index + 2, i))
					return true;
			}
			return isMatch(s, p, index + 2, s.length());
		}
		//如果当前的字符不是 '.' 那么从当前字符开始一直往后如果出现的字符都和当前模式中的字符一直都可以用*号来匹配
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
