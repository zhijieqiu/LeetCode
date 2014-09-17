#include <iostream>
using namespace std;

void getNext(char* pattern, int* next)
{
	
	int i = 0, j = -1;//set j to be -1
	int len = strlen(pattern);
	next[0] = -1;
	while (i < len)
	{
		//当j==-1的时候是在计算next[0] ,以此类推
		if (j == -1 || pattern[i] == pattern[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];//if patten[i]!=pattern[j] then set j = next[j];
		//for example pattern is "heohejheoheo",when i == 11 then we find that j!=-1 and j!=o 
		//then find that we set j=2(he==he),because the length of commom substring can never overflow "heohe"
	}
	for (int i = 0; i < len; i++)
	{
		cout << next[i] << " ";
	}
	cout << endl;
}
void find(char* pattern, char * str)
{
	int *next = new int[strlen(pattern)];
	getNext(pattern, next);
	int i = 0, j = 0, lenP = strlen(pattern), lenS = strlen(str);
	while (true)
	{
		if (j==-1||pattern[j] == str[i])//here we must deal with the same method like getNext
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
		if (j == lenP)
		{
			cout << "find at position " << i-lenP << endl;
			j = next[j];
		}
		if (i == lenS)
			break;
	}
}
int main(void)
{
   char *str = "loveIlovelovelovehello,world,lovejackhellohelloohello";
   char *pattern = "hello";
   find(pattern, str);
}
