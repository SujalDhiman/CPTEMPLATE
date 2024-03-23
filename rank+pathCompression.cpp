#include<bits/stdc++.h>
#define pp pair<int,int>
#define int long long
using namespace std;
vector<int>par;
int find(int x)
{
    if(par[x] == x) return x;
    return par[x]=find(par[x]);
}
signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            par.push_back(ele);
        }
        vector<int>rank(n,1);
        int t;
        cin>>t;
        while(t--)
        {
            int a,b;
            cin>>a>>b;
            int x=par[a];
            int y=par[b];
            if(rank[a]<=rank[b])
            {
                par[a]=y;
                rank[b]+=1;
            }
            else
            {
                par[b]=x;
                rank[a]+=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<par[i]<<" "<<rank[i]<<endl;
        }
}
