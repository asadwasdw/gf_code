#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=15;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N][N];
int b[N][N];

void solve()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>b[i][j];
        }
    }

    bool ans = false;
    for(int i = 0;i < (1<<n);i++){
        for(int j=0;j<(1<<m);j++){

            vector<int>X,Y;
            for(int k = 0;k<n;k++){
                if(((i>>k)&1)==0)X.push_back(k);
            }            
            for(int k = 0;k<m;k++){
                if(((j>>k)&1)==0)Y.push_back(k);
            }
            // for(auto k:X)cout<<k<<" ";cout<<endl;
            // for(auto k:Y)cout<<k<<" ";cout<<endl;

            if(X.size()!=x||Y.size()!=y)continue;

            bool ky =true;

            for(int u = 0;u<x;u++){
                for(int v = 0;v<y;v++){
                    if(a[X[u]][Y[v]]!=b[u][v]){
                        ky=false;
                    }
                }
            }
            if(ky)ans=true;

        }
    }

    if(ans)cout<<"Yes";
    else cout<<"No";










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