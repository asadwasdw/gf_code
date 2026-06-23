#include<iostream>
#include<algorithm>
#define int long long
typedef long long ll;

using namespace std;


int exgcd(int a,int b,int &x,int &y)
{
    
    if(b==0)
    {
        x=1;
        y=0;
       return a;
    }
    
    int d=exgcd(b,a%b,y ,x);
    y-=a/b*x;
    return d;
}


void solve()
{
    ll x,y,a,b,n;
    ll l,r;
    cin>>a>>b>>n>>l>>r;

    ll d =exgcd(a,b,x,y);
    //cout<<d<<endl;
    int t = (x*(n/d)%(b/d)+(b/d))%(b/d);


    int t1 = l/(b/d);
    //cout<<(b/d)<<endl;


    if(t<l)t+=t1*(b/d);
    if(t<l)t+=(b/d);



    if(t<=r&&n%d==0)cout<<"YES";
    else cout<<"NO";
    cout<<"\n"; 
}


signed main()
{
   int t;cin>>t;while(t--)
    solve();
}