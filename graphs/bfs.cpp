#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graphs;


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
    
    unordered_set<int>visited;
    visited.insert(0);
    queue<int>qu;
    qu.push(0);
    while(qu.size()>0)
    {
        int curr=qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(int neighbour:graphs[curr])
        {
           if(visited.find(neighbour) == visited.end())
           {
            visited.insert(neighbour);
            qu.push(neighbour);
           }
        }
    } 
}