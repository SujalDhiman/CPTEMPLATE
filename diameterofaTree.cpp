#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>trees;
void dfs(int currentNode,int parent,vector<int> &distX)
{
    if(parent == -1)
    {
        distX[currentNode]=0;
    }
    else
    {
        distX[currentNode]=1+distX[parent];
    }
    for(int neighbour : trees[currentNode])
    {
        if(neighbour != parent)
        {
            dfs(neighbour,currentNode,distX);
        }
    }
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
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    trees=edges;
    vector<int>distX(n,0);
    dfs(0,-1,distX);
    int pos=0;
    int value=0;
    for(int i=1;i<n;i++)
    {
        if(distX[i]>value)
        {
            value=distX[i];
            pos=i;
        }
    }
    vector<int>distY(n,0);
    dfs(pos+1,-1,distY);
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<distY[i]<<endl;
    }
    pos=0;
    value=0;
    for(int i=1;i<n;i++)
    {
        if(distY[i]>value)
        {
            value=distY[i];
            pos=i;
        }
    }
    cout<<pos+1<<" "<<distY[pos]<<endl;
}


/*
17
1 2
2 9
2 10
9 11
9 16
9 15
1 3
3 4
3 5
4 12
4 13
5 14
1 6
6 17
17 7
17 8

*/
