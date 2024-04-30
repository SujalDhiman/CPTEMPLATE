#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<list<pair<int,int>>>graphs;
void add_edge(int u,int v,int wt)
{
	graphs[u].push_back({v,wt});
	graphs[v].push_back({u,wt});
}
void display()
{
	for(int i=0;i<graphs.size();i++)
	{
		cout<<i<<"->";
		for(auto neighbour:graphs[i])
		{
			cout<<"("<<neighbour.first<<" "<<neighbour.second<<")"<<" ";
		}
		cout<<endl;
	}
}
signed main()
{
	int v1;
	cin>>v1;
	int src;
	cin>>src;
	graphs.resize(v1+1,list<pair<int,int>>());
	int e;
	cin>>e;
	int n=e;
	while(e--)
	{
		int u;
		cin>>u;
		int v;
		cin>>v;
		int wt;
		cin>>wt;
		add_edge(u,v,wt);
	}
	cout<<src<<endl;
	unordered_map<int,int>umap;
	for(int i=0;i<=v1;i++)
		umap[i]=INT_MAX;
	
	umap[src]=0;

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,src});
	unordered_set<int>visited;
	while(pq.size()>0)
	{
		auto ele=pq.top();
		if(visited.find(ele.second)!=visited.end())
		{
			pq.pop();
			continue;
		}
		pq.pop();
		int distFromSource=ele.first;
		visited.insert(ele.second);
		for(auto neighbour:graphs[ele.second])
		{
			if(visited.find(neighbour.first) == visited.end() && distFromSource+neighbour.second<umap[neighbour.first])
			{
				umap[neighbour.first]=distFromSource+neighbour.second;
				pq.push({distFromSource+neighbour.second,neighbour.first});
			}
		}
	}
	for(auto ele:umap)
	{
		cout<<ele.first<<" "<<ele.second<<endl;
	}
}

