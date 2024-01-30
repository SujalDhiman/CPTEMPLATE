#include<bits/stdc++.h>
using namespace std;
void dfs(int currentNode,int parent,vector<vector<int>>& edges,vector<int>& firstParent)
{
    if(parent!=-1)
        firstParent[currentNode]=parent;
    for(int neighbour:edges[currentNode])
    {
        if(neighbour!=parent)
        {
            dfs(neighbour,currentNode,edges,firstParent);
        }
    }
}
int kthparent(int x,int k,vector<vector<int>>parents)
{
    for(int i=0;i<=log2(k);i++)
    {
        if(k&(1<<i))
        {
            x=parents[i][x];
            if(x == -1)
                break;
        }
    }
    return x;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>edges(n,vector<int>());
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<vector<int>>parents(log2(n)+1,vector<int>(n,-1));

    dfs(0,-1,edges,parents[0]);

    for(int k=1;k<=log2(n);k++)
    {
        for(int i=0;i<n;i++)
        {
            int intermediate=parents[k-1][i];
            if(intermediate!=-1)
            parents[k][i]=parents[k-1][intermediate];
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        int k;
        cin>>k;
        cout<<kthparent(x,k,parents)<<endl;
    }

}
