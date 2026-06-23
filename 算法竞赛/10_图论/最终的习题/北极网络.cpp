#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-4;

vector<vector<int>>edg(N);

struct node{
    int x,y;
}d[N];
 int s,p;
double js(node a,node b)
{
    double x = abs(a.x-b.x);
    double y = abs(a.y-b.y);
   // cout<<x<<" "<<y<<endl;
    return sqrt(x*x+y*y);
}
int f[510];

int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}

bool check(double mid)
{
    for(int i=1;i<=p;i++)f[i]=i;

    for(int i=1;i<=p;i++)
    {
        for(int j=i+1;j<=p;j++)
        {
            int fi=find(i);
            int fj=find(j);
           // if(fi==fj)continue;

            double t = js(d[i],d[j]);
            //cout<<i<< " "<<j<<" "<<t<<endl;

            if(t>mid)continue;
            f[fi]=fj;
        }
    }
    
    int res = 0;
    for(int i=1;i<=p;i++){
        if(find(i)==i)res++;
    }
    //cout<<res<<endl;
    return res<=s;
    

}




void solve()
{
   
    cin>>s>>p;
    for(int i=1;i<=p;i++){
        cin>>d[i].x>>d[i].y;
    }

    double l=0,r= 2e5;

   // check(200);
    while(r-l>=eps){
          double mid = (r+l)/2;
        //cout << l<<" "<<mid<<" "<<r<<endl;
        if(check(mid))r = mid;
        else l = mid;
    }
    printf("%.2lf\n",l);
    







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