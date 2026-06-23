#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int a[N],b[N],c[N];
int st[N];
void solve()
{

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)b[i]=c[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];

        swap(b[a[i]],b[a[i]+1]);
    }

    for(int i=1;i<=n;i++)
    {
        st[b[i]]=i;
    }


    for(int i=1;i<=m;i++)
    {

        if(c[a[i]]==1){
            cout<<st[c[a[i]+1]]<<endl;;
        }
        else if(c[a[i]+1]==1){
            cout<<st[c[a[i]]]<<endl;
        }
        else cout<<st[1]<<endl;
        swap(c[a[i]],c[a[i]+1]);
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