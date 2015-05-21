struct Node{
    int v,w;
    string name;
    bool isUsed;
    Node(int vv,const string & nm):v(vv),name(nm),isUsed(false){}
};
/*
--->
____
|___|___
    |___|
*/
vector<vector<Node> > graph(10000);
void Eular(int u,int parent){
    for(int i=0;i<graph[u].size();i++){
        if(graph[u][i].isUsed==false){//这里判断一条边是否被使用过了，如果
            graph[u][i].isUsed = true;
            Eular(graph[u][i].v,u);
        }
    }
    ret.push_back(u);//这里使用当所有的邻边搜索完了才将节点加入到结果结合中
    if(parent!=-1){
        for(int i=0;i<graph[parent].size();i++){
            if(graph[parent][i].v == u){
                names.push_back(graph[parent][i].name);
                break;
            }
        }
    }
}
int main()
{
    vector<pair<int,int> > edges;
    edges.push_back({1,2});
    edges.push_back({2,3});
    edges.push_back({3,4});
    edges.push_back({4,1});
    edges.push_back({3,5});
    edges.push_back({5,6});
    edges.push_back({6,7});
    edges.push_back({7,3});
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first,v = edges[i].second;
        string str=to_string(u)+"-"+to_string(v);
        graph[u].push_back(Node(v,str));
    }
    Eular(1,-1);
    for(int i=ret.size()-1;i>=0;i--){
        cout<<ret[i]<<" ";
    }
    cout<<endl;
    for(int i=names.size()-1;i>=0;i--){
        cout<<names[i]<<" ";
    }
    cout<<endl;
}
