#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N],b[N],c[N];
unordered_map<int,bool> st;

void solve()
{
    int n,m,l;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i];
    cin>>l;
    for(int i=1;i<=l;i++) cin>>c[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k =1;k<=l;k++){
                __int128_t x = (__int128_t)a[i]+b[j]+c[k];
                if(x <= 3e8) {
                    // cout<<(int)x<<endl;
                    st[x] = true;
                }
            }
        }
    }

    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        if(st[x])cout<<"Yes\n";
        else cout<<"No\n";
    }







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}