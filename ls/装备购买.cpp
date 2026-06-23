#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
// #define int long long
//vector<vector<int>>edg(N);

int w[N];
long double a[510][510];

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }

    for(int i=1;i<=n;i++)cin>>w[i];

    int k = 0;
    int ans = 0;
    for(int i=1;i<=m;i++){
        int now=0;
        for(int j=k+1;j<=n;j++)
            if (fabs(a[j][i])>eps && (now==0 || w[j]<w[now]))
                now=j;
            
        if (now==0)
            continue;
        ans+=w[now];
        k++;
        for(int j=1;j<=m;j++)
            swap(a[now][j],a[k][j]);
        swap(w[now],w[k]);
    
        for(int j=1;j<=n;j++){
            if(j==k)continue;
            if(fabs(a[j][i])<eps)continue;
            long double t = a[j][i] / a[k][i];
            for(int z=i;z<=m;z++) {
                a[j][z] -= t * a[k][z];
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";cout<<endl;
    // }cout<<endl;



    cout<<k<<" "<<ans<<endl;


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