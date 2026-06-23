#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


#define int long long

int qmi(int a,int b)
{
    int res=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}


void solve()
{
    string s;
    cin>>s;
    int n=s.size();

    int ans=0;

    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        ans+=qmi(26,n-i)*(s[i]-'A'+1);
    }

    cout<<ans<<endl;



}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}