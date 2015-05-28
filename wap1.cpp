//
//  main.cpp
//  WAP
//
//  Created by jackqiu on 15/5/28.
//  Copyright (c) 2015年 jackqiu. All rights reserved.
//

#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int size = 510;
int dp[510][510];
int matrix[510][510];
//dp[i][j] 到某个点的最大收益值，
//dp[i][j] = max(dp[k][j-1]+dis(k,i)) k==1..n
#define MIN 0x80000000
int n,m;
/*
 test case 1:
 4 4
 -1 4 5 1
 2 -1 2 4
 3 3 -1 3
 4 2 1 2
 
 test case 2:
 4 4
 -1 4 5 1
 2 -1 2 4
 3 3 -1 -1
 4 2 1 2
 */
int main(){
    scanf("%d%d",&n,&m);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int col=1;col<=m;col++){
        for(int row=1;row<=n;row++){
            if(matrix[row][col]==-1){
                dp[row][col] = -1;
                continue;
            }
            int maxValue  = dp[row][col-1]+matrix[row][col];
            if(dp[row][col-1]==-1) maxValue = -1;
            int preSum =matrix[row][col];
            //go up
            for(int nr=row-1;nr>=1;nr--){
                if(matrix[nr][col]==-1){
                    preSum = MIN;
                    break;
                }else{
                    preSum+=matrix[nr][col];
                    if(dp[nr][col-1]==-1) continue;
                    maxValue = max(maxValue,dp[nr][col-1]+preSum);
                }
            }
            //go down
            preSum = matrix[row][col];
            for(int nr=row+1;nr<=n;nr++){
                if(matrix[nr][col]==-1){
                    preSum = MIN;
                    break;
                }else{
                    preSum+=matrix[nr][col];
                    if(dp[nr][col-1]==-1) continue;
                    maxValue = max(maxValue,dp[nr][col-1]+preSum);
                }
            }
            
            dp[row][col] = maxValue;
            
        }
        if(dp[1][col]==-1&&dp[n][col]!=-1)
            matrix[1][col]==-1?dp[1][col]=-1:dp[1][col] = matrix[1][col];
        if(dp[n][col]==-1&&dp[1][col]!=-1)
            matrix[n][col]==-1?dp[n][col]=-1:dp[n][col] = matrix[n][col];
    }
    int maxPoints = INT_MIN;
    for(int i=1;i<=n;i++){
        maxPoints = max(maxPoints,dp[i][m]);
    }
    cout<<maxPoints<<endl;
    return 0;
    
}








