
int calculateMinimumHP(vector<vector<int> > &dungeon) {
    int width = dungeon.size();
    if(width==0)
        return 0;
    int length = dungeon[0].size();
    int dp[width+1][length+1];//it is the new attribute of C++11
    //if a new place is positive than we can place make it zero 
    dp[width][length]=dungeon[width-1][length-1]<0?-dungeon[width-1][length-1]:0;
    //dp[width][length]=dp[width][length]<0?0:dp[width][length];
    //cout<<dp[width][length]<<endl;
    for(int i=width-1;i>=1;i--)
        dp[i][length]=max(dp[i+1][length]-dungeon[i-1][length-1],0);//it at least is zero before you come into the position
    for(int j=length-1;j>=1;j--)
        dp[width][j]= max(dp[width][j+1]-dungeon[width-1][j-1],0);//it at least is zero before you come into the position
    for(int i=width-1;i>=1;i--)
        for(int j=length-1;j>=1;j--)
            dp[i][j] = max(min(dp[i+1][j],dp[i][j+1])-dungeon[i-1][j-1],0);
    return dp[1][1]+1;
}
int main()
{
    vector<vector<int> > vv;
    vector<int> v1;
    v1.push_back(-2);
    v1.push_back(-3);
    v1.push_back(3);
    vv.push_back(v1);
    v1.clear();
    v1.push_back(-5);
    v1.push_back(-10);
    v1.push_back(1);
    vv.push_back(v1);
    v1.clear();
    v1.push_back(10);
    v1.push_back(30);
    v1.push_back(-5);
    vv.push_back(v1);
    cout<<calculateMinimumHP(vv)<<endl;
    return 0;
}
