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
int a[N];
int b[N];
vector<int>c;


void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i],c.push_back(a[i]),c.push_back(a[i]+1);
    for(int j=1;j<=m;j++)cin>>b[j],c.push_back(b[j]),c.push_back(b[j]+1);


    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    sort(c.begin(),c.end());

    int i=0;
    int j=0;

    for(auto t:c)
    {
        while(i+1<=n&&a[i+1]<=t)i++;
        while(j+1<=m&&b[j+1]<t)j++;
   
        //cout<<i<<" "<<j<<" "<<t<<" "<<x<<endl;
    
        if(i>=m-j){
            cout<<t<<endl;
            return;
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