#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string t;
        cin>>t;
        vector<vector<int>>dp;
        dp.clear();
        dp.resize(1003,vector<int>(1003,0));

        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=t.length();j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int i=s.length();
        int j=t.length();
        string s1="";
        while(i>0 && j>0)
        {
            if(s[i-1] == t[j-1])
            {
                s1+=s[i-1];
                i-=1;
                j-=1;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i-=1;
            }
            else
            {
                j-=1;
            }
        }
        reverse(s1.begin(),s1.end());
        cout<<s1<<endl;
    }
}
