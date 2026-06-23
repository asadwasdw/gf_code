#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int f[N];

int find(int x)
{
    if(f[x]!=x)f[x]=find(f[x]);
    return f[x];
}
int d[N];


void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        d[b]++;
        int fa=find(a);
        int fb=find(b);
        if(fa==fb)continue;
        f[fa]=fb;
    }

  
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(find(i)==i)cnt++;
    }
    if(cnt>=2){
        cout<<"-1";
        return;
    }
    int ans = 0;

    for(int i=1;i<=n;i++){
        if(d[i]==0)
        {
            if(ans==0)ans=i;
            else {
                cout<<"-1";
                return ;
            } 
        }
    }
    cout<<ans<<endl;









}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}