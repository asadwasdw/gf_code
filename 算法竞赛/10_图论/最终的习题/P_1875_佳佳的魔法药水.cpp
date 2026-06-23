#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int num[N];
int w[N];
int f[N][N];
int st[N];
int ans[N];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)num[i]=1;

    int a,b,c;
    while(cin>>a>>b>>c){
        a++,b++,c++;
        f[a][b]=f[b][a]=c;
    }

    

    for(int i=1;i<n;i++){
        c=0;
        int mx = INFll;
        for(int j=1;j<=n;j++){
            if(!st[j] && w[j]<mx) {
                mx=w[j];
                c=j;
            }
        }
        // cout<<c<<endl;
        st[c]=1;
    
        for(int j=1;j<=n;j++){

            int t = f[c][j];
            if(!st[j])continue;
            if(!t)continue;

            if(w[c]+w[j] == w[t]) {
                num[t] += num[c]*num[j];
            }
            else if(w[c]+w[j] < w[t]){
                num[t] = num[c]*num[j]; w[t] = w[c]+w[j];
            } 
        }
    }
    cout<<w[1]<<" "<<num[1]<<endl;
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