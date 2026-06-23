#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[20][20];
int ans = 0,A=0;
bool st[16];
int n;

void dfs(int u,int res,int cnt){

    if(cnt==n){
        //cout<<res<<endl;
        A = max(res,A);
        //if(res==75)cout<<res<<endl;
        ans = max(res,ans);
        
        return;
    }

    if(st[u]){
        dfs(u+1,res,cnt);
        return ;
    }

    st[u]=true;
   //cout<<u<<endl;
    for(int i=u+1;i<=n;i++){
        if(st[i])continue;

        st[i]=true;
        int w = res + a[u][i];

        dfs(u+1,w,cnt+2);
        st[i]=false;
    }
    st[u]=false;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++){
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
    }

    if(n%2==1)
    {
        st[1]=true;
        dfs(2,0,1);
        st[1]=false;

        for(int i=2;i<=n ;i++){
            st[i]=true;
            dfs(1,0,1);
            st[i]=false;
        }
    }
    else {
        dfs(1,0,0);
    }
    cout<<A<<endl;
    cout<<ans<<endl;

   // for(int i=1;i<=n;i++)cout<<i<<" "<<st[i]<<endl;




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