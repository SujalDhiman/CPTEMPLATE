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
    display_graph();
}