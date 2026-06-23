#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2100;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;
const int P =13331;

ull h[N][N];
ull l[N][N];
ull p[N];
ull t[N];
char a[2010][2010];
int ne[N];

ull kmp(int n)
{

    //for(int i=1;i<=n;i++)cout<<t[i]<<" ";cout<<endl;

    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&t[i]!=t[j+1])j=ne[j];

        if(t[i]==t[j+1])j++;

        ne[i]=j;
    }

    return n- ne[n];
}


ull get1(int x1,int y1,int x2,int y2){

   int i=0;
    for(;y1<=y2;y1++){
        t[++i] = l[y1][x2]-l[y1][x1-1]*p[x2-x1+1];
    }
    return kmp(i);
} 


ull get2(int x1,int y1,int x2,int y2){
    int i=0;
    for(;x1<=x2; x1++){
        t[++i] = h[x1][y2]-h[x1][y1-1]*p[y2-y1+1];
    }
    return kmp(i);
} 




void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            char t;
            cin>>t;
            a[i][j]=t;
        }
    }
    


    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        for(int j=1;j<=n;j++){    
            h[i][j]=h[i][j-1]*P+a[i][j]-'a';
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            l[i][j]=l[i][j-1]*P+a[j][i]-'a';
        }
    }


    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)cout<<l[i][j]<<" ";
    //         cout<<endl;
    // }
   // m=1;
    
    while(m--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<get1(x1,y1,x2,y2)*get2(x1,y1,x2,y2)<<endl;
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