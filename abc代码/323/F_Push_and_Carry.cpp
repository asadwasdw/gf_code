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

int n,m,sx,sy,tx,ty;

int ans = 0;
//x1 = - (y - center_y) + center_x
//y1 = (x - center_x)  + center_y
PII a,b,c;

PII xz(PII t){
    PII res;
    res.first = -t.second ;
    res.second = t.first ;
    return res;
}

int js(PII a,PII b)
{
    return abs(a.first - b.first) +  abs(a.second - b.second);
}


void print(PII t)
{
    cout<<t.first<<" "<<t.second<<endl;
}

void op1()
{



    PII t1 = {0,-1};
    PII t2 = {-1,0};
    int ans1 = js(a,t1);
    int ans2 = js(a,t2);

    if(a.first == b.first)ans2+=2;
    if(a.second == b.second)ans1+=2;


    int mn = min({ans1,ans2});

    if(mn == ans1){
        ans+=ans1+(c.second);
        b = {0,c.second};
        a = {0,c.second-1};
    }
    else {
        ans+=ans2+(c.first);
        b = {c.first,0};
        a = {c.first-1,0};
    }
}

void op2()
{



    if(b.second==c.second){
        PII t = {b.first-1,b.second};
        ans+=js(t,a)+js(b,c);
        if(a.second==b.second&&a.first>b.first)ans+=2;
    }
    else {
        PII t = {b.first,b.second-1};
        ans+=js(t,a)+js(b,c);
        if(a.first == b.first&&a.second>b.second)ans+=2;
    }

}


void solve()
{
    
    cin>>n>>m>>sx>>sy>>tx>>ty;

    n -= sx;
    m -= sy;
    tx-=sx;
    ty -= sy;
    sx = sy = 0;
    a ={n,m};
    b ={0,0};
    c = {tx,ty};
    
    while(!(c.second>=0&&c.first>=0)){

        a = xz(a);
        c = xz(c);
    }

    if(b.first!=c.first&&b.second!=c.second)op1();
   // cout<<ans<<endl;
    op2();

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