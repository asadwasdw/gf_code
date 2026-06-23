#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


PII a[N];

bool cmp(PII a,PII b)
{
    return a.first<b.first;

}


void solve()
{

    int n;cin>>n;
    int k;cin>>k;
    int sum =0 ;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]={x,y};
        sum += y;
    }

    if(sum<=k){
        cout<<"1"<<endl;
        return ;
    }

    sort(a+1,a+n+1,cmp);

    for(int i=1;i<=n;i++)
    {
        sum-=a[i].second;
        if(sum<=k){
            cout<<a[i].first+1<<endl;
            return ;
        }
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