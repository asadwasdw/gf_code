#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=220+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int a[N][N];
int mxi=0,mni=0x3f3f3f3f,mxj=0,mnj=0x3f3f3f3f;

bool jc()
{
    for(int i=mni;i<=mxi;i++)
    {
        for(int j=mnj;j<=mxj;j++)
        {
            if(a[i][j]==0)return false;
        }
    }
    return true;
}



void solve()
{

    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x,b;cin>>x>>b;
        x+=100,b+=100;
        a[x][b]=1;
    }

     if(a[100][100]==0){
        cout<<"-1"<<endl;
        return ;

    }
    

    for(int i=0;i<=220;i++)
    {
        for(int j=0;j<=220;j++)
        {
            if(a[i][j]==1)
            {
                mni=min(i,mni);
                mxi=max(i,mxi);
                mnj=min(j,mnj);
                mxj=max(j,mxj);
            }
        }
    }

    if(jc())
    cout<<mxi-mni+mxj-mnj<<endl;
    else cout<<"-1"<<endl;

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