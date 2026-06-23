#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5000+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int n,m;
double t1,t2;
double v;
vector<vector<int>>edg(N);
bool st2[N];

PII pt[N];
PII mb[N];
int match[N];

double eps = 1e-8;

double hf(PII a,PII b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second))/v;
}


bool find(int j)
{
    for(auto i:edg[j]){
        if(st2[i])continue;
        st2[i]=true;
        if(match[i]==0||find(match[i]))
        {
            match[i]=j;
            return true;
        }
    }

    return false;
}


bool check(double tim)
{
    memset(match,0,sizeof match);
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        double t = 0;

        while(t<=tim){
            bool ky =false;
            t+=t1;
            for(int j=1;j<=m;j++)
            {
                //cout<<t<<" "<<j<<" "<<t+hf(pt[i],mb[j])<<endl;

                if(t+hf(pt[i],mb[j])<tim||fabs(t+hf(pt[i],mb[j])-tim)<=eps){
                    if(ky==false)
                    {
                        ky=true;
                        ++cnt;
                    }
                  //  cout<<j<<" "<<cnt<<endl;
                    edg[j].push_back(cnt);
                }
            }
            t+=t2;
        }
    }

    int ans = 0;

    for(int j=1;j<=m;j++)
    {
        memset(st2,0,sizeof st2);
        if(find(j))ans++;
    }

    for(int i=1;i<=m;i++)edg[i].clear();
    //cout<<ans<<endl;
    return ans>=m;

}





void solve()
{
    cin>>n>>m>>t1>>t2>>v;
    t1/=60;
    for(int i=1;i<=m;i++)cin>>mb[i].first>>mb[i].second;
    for(int i=1;i<=n;i++)cin>>pt[i].first>>pt[i].second;

    double l=0,r=1e5;

    while(fabs(r-l)>=eps)
    {
        double mid = (l+r)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    printf("%.6lf",l-(1e-7));


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