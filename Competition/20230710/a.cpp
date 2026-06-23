#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

///https://codeforces.com/gym/103389
int a[N];
int b[N];

void solve()
{
    int n;cin>>n;
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;

    for(int i=0;i<m;i++)cin>>b[i];

    bool ky1=false;
    bool ky2=false;
    for(int i=1;i+m-1<=n;i++)
    {
        if(i<=x)continue;
        for(int j=0;j<m;j++)
        {
            if(a[j+i]!=b[j])break;

            if(j==m-1)ky1=true;
        }
    }

    for(int i=n;i-m+1>=1;i--)
    {
        if(i>=x)continue;
        for(int j=0;j<m;j++)
        {
            if(a[i-j]!=b[j])break;
            if(j==m-1)ky2=true;
        }
    }

    if(ky1&&ky2)
    {
        cout<<"Unsure"<<endl;
    }
    else if(ky1){
        if(y>x){
            cout<<"Right"<<endl;
        }
        else cout<<"Wrong"<<endl;
    }
    else if(ky2)
    {
        if(y<x){
            cout<<"Right"<<endl;
        }
        else cout<<"Wrong"<<endl;
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