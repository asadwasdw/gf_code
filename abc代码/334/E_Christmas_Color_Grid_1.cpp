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

int n,m;
char a[1010][1010];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool st[N];
int low[N],num[N],cnt;
bool iscut[N];
bool gd[N];
vector<int>ans;

void dfs(int u,int root)
{
    ++cnt;
    low[u]=num[u]=cnt;
    int child = 0;

    for(auto t:edg[u]){
        if(num[t]==0){
            child++;
            dfs(t,root);
            low[u]=min(low[u],low[t]);
            if(low[t]>=num[u]&&u!=root){
                iscut[u]=true;
            }
        }
        else
            low[u]=min(low[u],num[t]);
    }

    if(u==root&&child>=2){
        iscut[u]=true;
    }
}

int js(int a,int b)
{
    return a*(n-1)+b;
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