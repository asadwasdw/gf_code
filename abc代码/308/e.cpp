#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int a[N];
string s;

int m[10];
int e[10][10];
int x[10][10];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>s;
    s=" "+s;
    //cout<<s<<endl;

    int res=0;

    for(int i=1;i<=n;i++)
    {
        if(s[i]=='M')
        {
            m[a[i]]++;
        }
        else if(s[i]=='E')
        {
            for(int k=0;k<3;k++)
            {
                if(m[k])
                {
                    e[k][a[i]]+=m[k];
                   // cout<<m[k]<<" "<<a[i]<<endl;
                }
            }
        }
        else 
        {
            for(int k=0;k<3;k++)
            {
                for(int j=0;j<3;j++)
                {
                    if(e[k][j]==0)continue;
                    int cnt[6]={0,0,0,0,0,0};
                    cnt[k]++;
                    cnt[j]++;
                    cnt[a[i]]++;
                    int ans=0;
                    while(cnt[ans])ans++;
                  // cout<<ans<<endl;
                    res+=ans*e[k][j];
                }
            }
        }
    }
    cout<<res<<endl;









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