#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=100+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
char c[N][N];
int op[N],a[N];
void solve()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>c[i][j];
        }
    }

    int p,q;
    cin>>p>>q;

    for(int i=1;i<=q;i++) {
        cin>>op[i]>>a[i];
    }

    while(p--) {   
        for(int j=1;j<=q;j++) {
            if(op[j]==1) {
                int t = c[a[j]][m];
                for(int i=m;i>=2;i--){
                    c[a[j]][i]=c[a[j]][i-1];
                }
                c[a[j]][1]=t;
            }
            else {
                int t = c[n][a[j]];
                for(int i=n;i>=2;i--){
                    c[i][a[j]]=c[i-1][a[j]];
                }
                c[1][a[j]]=t;
            }
        }

        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=m;j++)cout<<c[i][j];cout<<endl;
        // }
    }

    cout<<c[x][y]<<endl;








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