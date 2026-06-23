#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n,m;
char a[1010][1010];
char b[1010][1010];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }

    int sum1 = 0;
    int sum2 = 0;

    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
            if(a[i][j] != b[i][j])sum1++;
            else sum2++;
        }
    
    if(sum1<=n*m/2) {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
        return;
    }


    if(sum2<=n*m/2) {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                if(a[i][j]=='X')cout<<".";
                else cout<<"X";
            }
            cout<<endl;
        }

        return;
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