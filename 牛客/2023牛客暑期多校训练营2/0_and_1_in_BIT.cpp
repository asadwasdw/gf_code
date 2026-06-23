#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define rep(i,a,n) for(int i=a;i<=n;i++)

vector<vector<int>>edg(N);
 string s;
int lastans = 0;
int n;
int cntA[N],cntB[N];
int pre[N];
char x[60];
void solve()
{
    string rs;
    ll l,r;
    scanf("%lld%lld",&l,&r);
    cin>>rs;
    //cout<<l<<" "<<r<<" "<<rs<<endl;
    l=(lastans^l)%n+1;r=(lastans^r)%n+1;
    if(l>r)	swap(l,r);
    int res = 0;
    int k = rs.size();
    rep(i,0,k-1){
        res=2ll*res+(rs[i]-'0');
    }

    ll mod = (1ll<<(int)(rs.size()));
   // cout<<mod<<endl;
   int ans = 0;
    if((cntA[r]-cntA[l-1])%2){
        res = -res;
        ans=pre[r]+pre[l-1];
    }
    else ans = pre[r]-pre[l-1];
    //cout<<ans<<endl;
    ans=((res+ans)%mod+mod)%mod;


    for(int i=1;i<=k;i++)
    {
        cout<<(char)('0'+(bool)(ans&(1ll<<(k-i))));
    }cout<<endl;
    lastans = ans;
}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
   
    cin>>n>>t;
    cin>>s; 
    //cout<<n<<" "<<t<<endl;
    //cout<<s<<endl;
    s=" "+s;

    for(int i=1;i<=n;i++){
        if(s[i]=='A'){
            cntA[i]=cntA[i-1]+1;
            pre[i]= - pre[i-1]-1;
        }
        else {
            cntA[i]=cntA[i-1];
            pre[i]=pre[i-1]+1;
        }
    }
    //cout<<"0011\n111\n0101010110";

    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
       solve();
    }
}