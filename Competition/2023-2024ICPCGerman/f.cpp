#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;



int a[N];
int b[N][5];
int n,w;



void solve()
{
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>w){
            cout<<"impossible"<<endl;
            return ;
        }
    }

    int h = w;

    for(int i=1;i<=n;i++)
    {
        int now= h-a[i];

        if(now<0){
            cout<<"impossible"<<endl;
            return ;
        }
        if(now%2){
            h--;
            h=max(0,h);
        }
        else {
            h++;
            h=min(h,w);
        }
    }


    if(h==w){
        cout<<"possible"<<endl;
    }
    else 
    {
        cout<<"impossible"<<endl;
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