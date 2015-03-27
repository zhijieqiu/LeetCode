//nextRedPos record the next postion to place red element
//cur record the position it scans to
//nextBluePos record the position to place blue element
void NelerLand(char ch[], int n)
{
        for (int i = 0; i < n; i++)
                cout << ch[i] << " ";
        cout << endl;
        int nextRedPos = 0, cur = 0, nextBluePos = n - 1;
        while (cur <= nextBluePos)
        {
                if (ch[cur] == 'R')//when cur is red
                {
                        swap(ch[nextRedPos], ch[cur]);
                        cur++, nextRedPos++;
                }
                else if (ch[cur] == 'W')
                        cur++;
                else//when cur is blue
                {
                        swap(ch[nextBluePos],ch[cur]);
                        nextBluePos--;
                }
        }
        for (int i = 0; i < n; i++)
                cout << ch[i] << " ";
        cout << endl;
}
int main()
{
   char ch[] = {'R','W','R','W','B','R','B','R','W'};
   NelerLand(ch,sizeof(ch)/sizeof(char));
   return 0;
}
