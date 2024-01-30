#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>p;
void dfs(int currentNode,int parent,vector<vector<int>>& edges,vector<int>& firstParent,vector<int>& level,int counter)
{
    level[currentNode]=counter;
    if(parent!=-1)
        firstParent[currentNode]=parent;
    for(int neighbour:edges[currentNode])
    {
        if(neighbour!=parent)
        {
            dfs(neighbour,currentNode,edges,firstParent,level,counter+1);
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
int binarySearchLCS(int commonLevel,int n1,int n2)
{
    int high=commonLevel-0;
    int low=0;
    while(low<=high)
    {
        int mid=high+(low-high)/2;
        if(kthparent(n1,mid,p) == kthparent(n2,mid,p))
        {
            high=mid-1;
        }
        else if(kthparent(n1,mid,p)!=kthparent(n2,mid,p))
        {
            low=mid+1;
        }
    }
    return low;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>edges(n,vector<int>());
    vector<int>level(n,0);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<vector<int>>parents(log2(n)+1,vector<int>(n,-1));

    dfs(0,-1,edges,parents[0],level,0);

    for(int k=1;k<=log2(n);k++)
    {
        for(int i=0;i<n;i++)
        {
            int intermediate=parents[k-1][i];
            if(intermediate!=-1)
            parents[k][i]=parents[k-1][intermediate];
        }
    }

    p=parents;
    int t;
    cin>>t;
    while(t--)
    {
    int node1,node2;
    cin>>node1>>node2;

    int parent=0;
    int n1=0;
    int n2=0;
    int lvl=0;
    bool Case=false;
    int LCS=-1;
    if(level[node1]>level[node2])
    {
        parent=abs(level[node2]-level[node1]);
        n1=node1;
        n2=node2;
        lvl=level[node2];
        if(parents[0][node1] == node2)
        {
            Case=true;
            LCS=node2;
        }
    }
    else if(level[node1]<level[node2])
    {
        parent=abs(level[node1]-level[node2]);
        n1=node2;
        n2=node1;
        lvl=level[node1];
        if(parents[0][node2] == node1)
        {
            Case=true;
            LCS=node1;
        }
    }
    else
    {
        parent=level[node1]-level[node2];
        n1=node1;
        n2=node2;
        lvl=level[node1];
    }
    if(!Case)
    {
    if(parent == 0)
    {
        cout<<kthparent(n1,binarySearchLCS(lvl,n1,n2),p)<<endl;
    }
    else
    {
        int newNode=kthparent(n1,parent,parents);
        cout<<kthparent(newNode,binarySearchLCS(lvl,newNode,n2),p)<<endl;

    }
    }
    else
    {
        cout<<LCS<<endl;
    }
    }
}
