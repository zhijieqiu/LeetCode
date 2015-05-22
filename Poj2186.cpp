#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int low[10010],df[10010],instack[10010],num[10010],du[10010];
stack<int> st;
int id=1,scc=0;
vector<vector<int> > graph(10010);
void dfs(int u){
    low[u]=df[u] = id++;
    instack[u] =1;
    st.push(u);
    for(int i=0;i<graph[u].size();i++){
      int v = graph[u][i];
      if(!df[v]){
        dfs(v);
        low[u] = min(low[u],low[v]);
      }else if(instack[v]){
        low[u] = min(low[u],df[v]);
      }
    }
    if(df[u]==low[u]){
      scc++;
      while(!st.empty()){
        int t = st.top();
        num[t] = scc;
        instack[t] = 0;
        if(t==u) break;
      }
    }
}
int main(){
  scanf("%d%d",&N,&M);
  int a,b;
  for(int i=0;i<M;i++){
    scanf("%d%d",&a,&b);
    graph[a].push_back(b);
  }
  for(int i=1;i<=N;i++){
    if(df[i]==0){
      dfs(i);
    }
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<graph[i].size();i++){
      if(num[i]!=num[graph[i][j]])
        du[num[i]]++;
    }
  }
  int duS = 0;
  int tmp=  0;
  for(int i=1;i<=scc;i++){
    if(!du[i]){
      duS++;
      tmp=i;
    }
  }
  if(duS>1) printf("0\n");
  if(duS==1){
    duS = 0;
    for(int i=1;i<=N;i++){
      if(num[i]==tmp)
        duS++;
    }
    printf("%d\n",duS);
  }
  printf("0\n");
}
