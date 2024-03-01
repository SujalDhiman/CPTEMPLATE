#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graphs;
unordered_set<int>visited;

void create_graph(int src,int dest,bool bi_direc=true)
{
    graphs[src].push_back(dest);
    if(bi_direc)
        graphs[dest].push_back(src);
}

void display_graph()
{
    for(int i=0;i<graphs.size();i++)
    {
        cout<<i<<" -> ";
        for(auto ele:graphs[i])
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

void dfs(int src,int dest,vector<int>& paths)
{
    if(src == dest)
    {
        paths.push_back(src);
        for(int i=0;i<paths.size();i++)
            cout<<paths[i]<<" ";
        cout<<endl;
        paths.pop_back();
        return ;
    }
    visited.insert(src);
    paths.push_back(src);
    for(int neighbour:graphs[src])
    {
        if(visited.find(neighbour) == visited.end())
        {
            dfs(neighbour,dest,paths);
        }
    }
    visited.erase(src);
    paths.pop_back();
}


int main()
{
    int v;
    cin>>v;
    graphs.clear();
    graphs.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--)
    {
        int s,d;
        cin>>s>>d;
        create_graph(s,d);
    }
    int src;
    cin>>src;
    int dest;
    cin>>dest;
    vector<int>paths;
    dfs(src,dest,paths);
}