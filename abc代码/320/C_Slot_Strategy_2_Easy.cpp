#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


int st[10];
int b[4][3100];
int sb[4][3010];

void solve()
{
    int m;
    cin>>m;
    for(int i=1;i<=3;i++)
    {
        string s;cin>>s;
        s=s+s+s;
        //cout<<s<<endl;
        for(int j=0;j<3*m;j++){
            int t=s[j]-'0';
            b[i][j]=t;
            st[t]|=(1<<i);
        }
    }

    int ans =INF;

    for(int i=0;i<m*3;i++)
    {
        for(int j=0;j<m*3;j++)
        {
            for(int k=0;k<m*3;k++)
            {
                if(i!=k&&i!=j&&j!=k)
                {
                    if(b[1][i]==b[2][j]&&b[2][j]==b[3][k])
                    {
                        ans=min({ans,max({i,j,k})});
                    }
                }
            }
        }
    }

    if(ans>INF/2)ans=-1;
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