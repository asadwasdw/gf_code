#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=55;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n,m;
int a[55][55];
bool st[N][N];
int row[N][N],rcnt;
int col[N][N],ccnt;

int g[N*N][N*N];
bool st2[N*N];
int match[N*N];



bool find(int x)
{
    for(int i=1;i<=ccnt;i++){
        if(!g[x][i])continue;
        if(st2[i])continue;
        st2[i]=true;

        if(match[i]==0||find(match[i])){
            match[i]=x;
            return true;
        }
    }
    return false;
}




void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            char t;cin>>t;
            if(t=='*')a[i][j]=true;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(a[i][j]&&!st[i][j]){
                ++rcnt;
                int x=i;
                int y=j;
                while(a[x][y]&&!st[x][y]){
                    row[x][y]=rcnt;
                    st[x][y]=true;
                    y++;
                }
            }
        }
    }

    memset(st,0,sizeof st);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(a[i][j]&&!st[i][j]){
                ++ccnt;
                int x=i;
                int y=j;
               // cout<<ccnt<<endl;
                while(a[x][y]&&!st[x][y]){
                    col[x][y]=ccnt;
                    st[x][y]=true;
                    //cout<<x<<" "<<y<<endl;
                    x++;
                }
            }
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)cout<<row[i][j]<<" ";
    //     cout<<endl;
    // }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)cout<<col[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            g[row[i][j]][col[i][j]]=1;
        }
    }
    // for(int i=1;i<=rcnt;i++)
    // {
    //     for(int j=1;j<=ccnt;j++)cout<<g[i][j]<<" ";
    //     cout<<endl;
    // }



    int ans = 0;

    for(int i=1;i<=rcnt;i++)
    {
        memset(st2,0,sizeof st2);
        if(find(i))ans++;
    }

    // for(int i=1;i<=ccnt;i++){
    //     cout<<i<<" "<<match[i]<<endl;
    // }
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