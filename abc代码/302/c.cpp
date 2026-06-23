#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N = 15;
int n,m;

string s[N];

bool st[N];

int qpl[N];


int pd(string a,string b)
{
    int ans=0;

    for(int i=0;i<m;i++)
    {
        if(a[i]!=b[i])ans++;
    }
    return ans;
}



bool dfs(int num)
{
    if(num==n+1)
    {
        for(int i=1;i<n;i++)
        {
            int t = pd(s[qpl[i]],s[qpl[i+1]]);
            if(t!=1)return false;
        }

        return true;
    }


    for(int i=1;i<=n;i++)
    {
        if(st[i])continue;

        st[i]=true;
        qpl[num]=i;
        bool t  = dfs(num+1);
        if(t)return true;
        st[i]=false;
    }
    return false;
}



void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    

    bool ky = dfs(1);

    if(ky)cout<<"Yes";
    else cout<<"No";
}

int main()
{
    //int t;cin>>t;while(t--)
    solve();
}