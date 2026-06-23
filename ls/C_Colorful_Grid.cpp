#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    bool ky = true;
    int n,m,k;
    cin>>n>>m>>k;

    if(k<n+m-2)ky=false;
    if(k%2 != (n+m)%2){
        ky=false;
    }
    if(!ky)cout<<"NO\n";
    else {
        cout<<"YES\n";

        vector<vector<int>> H(n+10,vector<int>(m+10,0));// n m-1
        vector<vector<int>> L(n+10,vector<int>(m+10,0));// n-1 m

        bool ky = 0;
        for(int i=1;i<m;i++)H[1][i]=ky,ky^=1;
        for(int i=1;i<n;i++)L[i][m]=ky,ky^=1;

        H[2][1]=H[1][1];
        L[1][1]=L[1][2] = H[1][1]^1;

        H[n-1][m-1]= H[n][m-1] = L[n-1][m];
        L[n-1][m-1]=L[n-1][m]^1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<m;j++){
                if(H[i][j])cout<<"R ";
                else cout<<"B ";
            }
            cout<<endl;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=m;j++){
                if(L[i][j])cout<<"R ";
                else cout<<"B ";
            }
             cout<<endl;
        }

    }









}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}