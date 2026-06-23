#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

bool st[N];
int a[N];
int sum,cnt;
int n,m;

void dfs(int x)
{
    if(st[x]){
        return;
    }

    if(m==0)return;
    st[x]=true;
    m--;
    sum+=a[x];
    dfs(sum%n);
}
int s[N];
void dfs2(int x,int len)
{
    if(st[x]){
        return;
    }
    st[x]=true;
    cnt=len;
    s[len]=a[x]+s[len-1];
    sum+=a[x];
    dfs2(sum%n,len+1);
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dfs(0);
    //cout<<sum<<endl;
    int ans = sum;
    memset(st,0,sizeof st);
    dfs2(sum%n,1);
    ans+=m/cnt*s[cnt]+s[m%cnt];
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