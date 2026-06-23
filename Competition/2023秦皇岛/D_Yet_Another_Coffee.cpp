#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
#define endl '\n'
#define int long long
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void solve()
{

    int n,m;cin>> n >> m;
    vector<int>a(n);vector<PII>b(m);
    for(int i=0;i<n;i++)cin>> a[i];
    for(int i=0;i<m;i++)cin>> b[i].first >> b[i].second;
    sort(b.begin(),b.end());
    int mi=INF,id=0,now=0;
    for(int i=0;i<n;i++){
        if(a[i]<mi){
            mi = a[i];
            id = i;
        }
        while(now<m&&i==b[now].first-1){
            a[id]-=b[now].second;
            mi = a[id];
            now++;
        }
    }
    sort(a.begin(),a.end());
    int t = 0;
    for(int i=0;i<n;i++){
        t+=a[i];cout<<t<<" ";
    }cout<<endl;



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