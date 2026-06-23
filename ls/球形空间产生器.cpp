#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

long double a[20][20],b[10],c[20][20];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n+1;i++) {
        for(int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j] = 2*(a[i][j] - a[i+1][j]);
            b[i]+=a[i][j]*a[i][j] - a[i+1][j]*a[i+1][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(fabs(c[j][i])>1e-8){
                for(int k =1;k<=n;k++)swap(c[i][k],c[j][k]);
                swap(b[i],b[j]);
            }
        }

        for(int j=1;j<=n;j++){
            if(i==j)continue;
            double rate = c[j][i] / c[i][i];
            for(int k = i;k<=n;k++)c[j][k] -= c[i][k] * rate;
            b[j]-=b[i]*rate;
        }
    }


    for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++)cout<<c[i][j]<<" ";
        // cout<<b[i]<<"\n";
        // cout<<b[i]/c[i][i]<<" ";
    
        printf("%.3Lf ",b[i]/c[i][i]);
    }   
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