#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
#define int long long
int s[N];
int ans = 0;

void get_ys(int n)
{
    ans = 0;
    int a[200000];
    int z=0;
    for(int i=1;i<=n/i;i++)
    {
        //cout<<n<<" "<<i<<endl;
        if(n%i==0)
        {
            a[z++]=i;
            if(i!=n/i)
            {
                a[z++]=n/i;
            }
        }
    }
    sort(a,a+z);
    for(int k=0;k<z;k++)
    {
        int i =a[k];
        int mx = 0;
        int mn = INFll;
        for(int j=1;j<=n;j+=i) {
            mn = min(mn,s[j+i-1]-s[j-1]);
            mx = max(mx,s[j+i-1]-s[j-1]);
        }
        ans=max(mx-mn,ans);
       // cout<<i<<" "<<mx-mn<<endl;
    }
    cout<<ans<<endl;
}


void solve()
{

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    
    for(int i=1;i<=n;i++)s[i]+=s[i-1];
    get_ys(n);
    





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