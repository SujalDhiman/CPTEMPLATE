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
	int src;
	cin>>src;
	cout<<src<<endl;
	display();
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	unordered_map<int,int>umap;
	unordered_set<int>us;
	for(int i=0;i<=v1;i++)
	{
		umap[i]=INT_MAX;
	}
	pq.push({0,src});
	int total_count=0;
	int res=0;
	while(total_count<n &&pq.size()>0)
	{
		auto ele=pq.top();
		if(us.find(ele.second)!=us.end())
		{
			pq.pop();
			continue;
		}
		pq.pop();
		us.insert(ele.second);
		res+=ele.first;
		total_count+=1;
		for(auto neighbour:graphs[ele.second])
		{
			if(us.find(neighbour.first)==us.end() && umap[neighbour.first]>ele.second)
			{
				umap[neighbour.first]=ele.second;
				pq.push({neighbour.second,neighbour.first});
			}
		}
	}
	cout<<res<<endl;
}
