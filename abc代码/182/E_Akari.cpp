#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1510;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<int>h[N];
vector<int>l[N];
bool st[N][N];
int a[N][N];
void solve()
{
    int H,W,n,m;
    cin>>H>>W>>n>>m;


    for(int i=1;i<=H;i++){
        h[i].push_back(0);
        h[i].push_back(W+1);
    }

    for(int i=1;i<=W;i++){
        l[i].push_back(0);
        l[i].push_back(H+1);
    }

    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        h[x].push_back(y);
        l[y].push_back(x);
        a[x][y]=1;
        st[x][y]=true;
    }

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        st[x][y]=true;
        h[x].push_back(y);
        l[y].push_back(x);
    }

    for(int i=1;i<=H;i++)
    {
        sort(h[i].begin(),h[i].end());
    }

    for(int i=1;i<=W;i++)
    {
        sort(l[i].begin(),l[i].end());
    }

    //for(auto t:h[1])cout<<t<<" ";cout<<endl;

    // for(int i=1;i<=H;i++)
    // {
    //     for(int j=1;j<=W;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans = 0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(a[i][j])ans++;
            if(st[i][j])continue;

            bool cg = false;

            auto t = upper_bound(h[i].begin(),h[i].end(),j)-h[i].begin();
           // cout<<h[i][t]<<endl;
            cg|=a[i][h[i][t]];
            t--;
            cg|=a[i][h[i][t]];
            

            t = upper_bound(l[j].begin(),l[j].end(),i)-l[j].begin();
            cg|=a[l[j][t]][j];
            t--;
            cg|=a[l[j][t]][j];

            //cout<<i<<" "<<j<<" "<<cg<<endl;

            if(cg)ans++;
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