#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+10,vector<int>(m+10,0));


 
    for(int i=1;i<=m;i++)
    {
        if(n>=m)
            a[1][i]=m-i;
        else a[1][i]=i-1;
    }

    if(n>=m&&m%2)swap(a[1][m/2],a[1][m/2+1]);
    for(int i=2;i<=min(n,m);i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=(i+j-2)%m;
        }
    }
    for(int i=m+1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            a[i][j]=a[i-m][j];
        }
    }



    vector<int>T(m+10);
    int res = 0;
    for(int i= 1;i<=m;i++){
        vector<int>t(n+10);
        for(int j=1;j<=n;j++){
            if(a[j][i]>n+1)continue;
            t[a[j][i]]++;
        }
        int ans = 0;
        while(t[ans])ans++;
        T[ans]++;
        //cout<<ans<<endl;
    }
    while(T[res])res++;
    cout<<res<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}