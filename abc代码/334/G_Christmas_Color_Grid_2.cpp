#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int n,m;
char a[1010][1010];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool st[N];
int low[N],num[N],cnt;
int iscut[N];
bool isgd[N];
vector<int>ans;

void dfs(int u,int fa)
{
    ++cnt;
    low[u]=num[u]=cnt;
    int child = 0;
    int cnt2 = 0;
    for(auto t:edg[u]){
        if(num[t]==0){
            child++;
            dfs(t,u);
            low[u]=min(low[u],low[t]);
            if(low[t]>=num[u]){
                cnt2++;
            }
        }
        else if(t!=fa)
            low[u]=min(low[u],num[t]);
    }

    if(fa==0){
        iscut[u]=child-1;
    }
    else {
        iscut[u]=cnt2;
    }
}

int js(int a,int b)
{
    return (a-1)*(m)+b;
}

int qmi(int a,int b,int c){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % c;
        b>>=1;
        a= a * a %c;
    }
    return res;
}


void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(a[i][j]!='#') continue;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(a[x][y]=='#')edg[js(i,j)].push_back(js(x,y));
            }
        }
    }
    int sum1=0, sum2 = 0;;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#'){

                sum1++;
                if(num[js(i,j)]==0) dfs(js(i,j),0),sum2++;
            }
        }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(a[i][j]=='.')continue;
            ans+=sum2+iscut[js(i,j)];
        }
    }

    cout<<ans%mod * qmi(sum1,mod-2,mod)%mod<<endl;
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