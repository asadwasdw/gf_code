#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

const int N=1e6+10;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

const ll P1 =17;
const ll P2 =37;
const ll mod1=1e9+7;
const ll mod2=1e9+9;

typedef pair<ll,ll>PII;
string s[N];
int f[N];
int a[N];

int n;
PII gethash(string t,int py)
{
    ll h1 = 0;
    ll h2 = 0;

    for(int i = 1;i<=n;i++)
    {
        int ans = 0;
        for(int k=0;k<5;k++){
            if(t[k]==s[i][k+py])ans++;
        }
        h1 = (h1*P1%mod1 + ans)%mod1;
        h2 = (h2*P2%mod2 + ans)%mod2;
    }
    return {h1,h2};
}
map<PII,int>mp;


void solve()
{
    cin>>n;
    mp.clear();
    for(int i =1;i<=n;i++)cin>>s[i]>>f[i],f[i]/=10;

        for(char j =  'A';j<='D';j++)
        for(char j1 = 'A';j1<='D';j1++)
        for(char j2 = 'A';j2<='D';j2++)
        for(char j3 = 'A';j3<='D';j3++)
        for(char j4 = 'A';j4 <= 'D';j4++){

            string t ;
            t += j;
            t += j1;
            t += j2;
            t += j3;
            t += j4;

            auto res = gethash(t,0);
            mp[res] ++;
        }

        int ans = 0;

        ll ans1 = 0;
        ll ans2 = 0;

        for(int i=1;i<=n;i++){
            ans1 = ((ans1*P1%mod1)+f[i])%mod1;
            ans2 = ((ans2*P2%mod2)+f[i])%mod2;
        }
    

     for(char j =  'A';j<='D';j++)
        for(char j1 = 'A';j1<='D';j1++)
        for(char j2 = 'A';j2<='D';j2++)
        for(char j3 = 'A';j3<='D';j3++)
        for(char j4 = 'A';j4 <= 'D';j4++){

            string t ;
            t += j;
            t += j1;
            t += j2;
            t += j3;
            t += j4;

            auto res = gethash(t,5);
            ll h1 = res.first;
            ll h2 = res.second;

            h1 = ((ans1 - h1)%mod1+mod1)%mod1;
            h2 = ((ans2 - h2)%mod2+mod2)%mod2;
            ans += mp[{h1,h2}];

        }
        cout<<ans<<endl;
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