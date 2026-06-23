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
int n,m;





ll qmi(ll a,ll b,ll c)
{
    ll res = 1;
    while(b)
    {
        if(b&1)res=res*a%c;
        b>>=1;
        a=a*a%c;
    }
    return res;

}

int ly2;



ll ask(ll a,ll b)
{
        int num;
        if(b%2==1)num=(b+1)%mod*ly2%mod;
        else num= b*ly2%mod;
        int a1 = 1;
        int an = b;
        if(b%2==0)an--;
        int h;

        if(a%2==1)h=(a+1)%mod*ly2%mod;
        else h=a%mod*ly2%mod;
      //  cout<<h<<endl;

        int b1 = (a1+an)%mod*num%mod*ly2%mod;
        int bn = b1%mod+(h-1)*2%mod*m%mod*num%mod;
        int ans1= (b1+bn)%mod*h%mod*ly2%mod;
       // cout<<h<<endl;
       // cout<<a1<<" "<<an<<endl;
       // cout<<b1<<" "<<bn<<endl;


       num = b-num;
       a1 = m+2;
       an = a1+(num-1)*2%mod;
       
       h = a-h;
       b1=(a1+an)*num%mod*ly2%mod;
       bn=b1+(h-1)*2%mod*m%mod*num%mod;
       int ans2 =(b1+bn)*h%mod*ly2%mod;
   
       return (ans1+ans2)%mod;

}



void solve()
{
    ly2=qmi(2,mod-2,mod);
    cin>>n>>m;


    int q;
    cin>>q;
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>x2>>y1>>y2;
        int t1=ask(x2,y2);
        int t2=ask(x1-1,y2);
        int t3=ask(x2,y1-1);
        int t4=ask(x1-1,y1-1);
        t1%=mod;
        t2%=mod;
        t3%=mod;
        t4%=mod;
       // cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
        cout<<((t1-(t2+t3)%mod+mod)+t4)%mod<<endl;
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