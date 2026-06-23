#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define int long long
//vector<vector<int>>edg(N);
int n,m,k;
int edg[20][20];
int ans = INFll;

bool st[20];



void dfs(int num,int w){
    if(num == n){
        ans = min(ans,w%k);
        return ;
    }

    for(int i=1;i<=n;i++){
        if(st[i])continue;

        st[i] = true;
        int fh = 0;

        if(num==0){
            dfs(num+1,w);
        }
        else {
            for(int j=1;j<=n;j++){
                if(!st[j])continue;
                if(i==j)continue;
                if(edg[j][i]==INFll)continue;

                dfs(num+1,w+edg[j][i]);
                
            }

        }

        st[i] =false;


    }

}

void solve()
{
    cin>>n>>m>>k;
    memset(edg,0x3f,sizeof edg);
    for(int i=1;i<=m;i++){
        int l,r,w;
        cin>>l>>r>>w;
        edg[l][r]=edg[r][l] = min(edg[l][r],w);
    }

    dfs(0,0);
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