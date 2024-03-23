#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<list<int>>graphs;
int v;
void add_edge(int a,int b,bool direc=true)
{
    graphs[a].push_back(b);
    if(direc)
    {
        graphs[b].push_back(a);
    }
}
void topo()
{
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto ele:graphs[i])
        {
            indegree[ele]+=1;
        }
    }
    queue<int>qu;
    unordered_set<int>us;
    for(int i=0;i<v;i++)
    {
        if(indegree[i] == 0)
        {
            qu.push(i);
            us.insert(i);
        }
    }

    while(qu.size()!=0)
    {
        int node=qu.front();
        cout<<node<<" ";
        qu.pop();
        for(auto neigh:graphs[node])
        {
            if(us.find(neigh) == us.end())
            {
                indegree[neigh]-=1;
                if(indegree[neigh] == 0)
                {
                    qu.push(neigh);
                    us.insert(neigh);
                }
            }
        }
    }

}
signed main()
{
    cin>>v;
    graphs.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        add_edge(a,b,false);
    }
    topo();
}
