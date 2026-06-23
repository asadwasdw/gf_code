#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int n,m;
int a[N];
int l1[N];
int l2[N];
int r[N];
int rl[N];
int st[N];
void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //cout<<i<<" "<<a[i]<<endl; 
    }

    l2[0]=(1<<30)-1;
    for(int i=1;i<=n;i++)
    {
        cin>>st[i];
        //l1[i]=l2[i]=a[i];
        if(st[i]==0){
            l1[i]=a[i]&l1[i-1];
            l2[i]=a[i]&l2[i-1];
        }
        else {
            l2[i]=a[i]|l2[i-1];
            l1[i]=a[i]|l1[i-1];
        }
    }

    //for(int i=0;i<=n;i++)cout<<l1[i]<<" "<<l2[i]<<endl;

    int cnt =0 ;

    for(int i=n;i;i--)
    {
        if(st[i]==0){
            cnt++;
            rl[cnt]=i;
            r[cnt]|=r[cnt-1]|a[i];
        }
        else r[cnt]|=a[i],rl[cnt]=i;
    }


    //for(int i=1;i<=n;i++)cout<<i<<" "<<r[i]<<" "<<rl[i]<<endl;
    rl[0]=n+1;

    while(m--){
        int x,y;
        cin>>x>>y;
        y=min(cnt,y);

        cout<<((x&l2[rl[y]-1])|l1[rl[y]-1]|r[y])<<endl;
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