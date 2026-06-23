#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[5][5];
bool ST[5][5];
int ans = 0;

bool check(int x,int y)
{
    bool res = false;
    if(ST[x][1]&&ST[x][2]&&ST[x][3]){
        if(y==1)
        {
            if(a[x][2]==a[x][3]){
                res =true;
            }
        }   
        if(y==2)
        {
            if(a[x][3]==a[x][1]){
                res =true;
            }
        } 
        if(y==3)
        {
            if(a[x][2]==a[x][1]){
                res =true;
            }
        } 
    }

    if(ST[1][y]&&ST[2][y]&&ST[3][y]){
        if(x==1)
        {
            if(a[2][y]==a[3][y]){
                res =true;
            }
        }   
        if(x==2)
        {
            if(a[3][y]==a[1][y]){
                res =true;
            }
        } 
        if(x==3)
        {
            if(a[1][y]==a[2][y]){
                res =true;
            }
        } 
    }

    if(x==y)
    {
        if(ST[1][1]&&ST[2][2]&&ST[3][3]){
            if(x==1)
            {
                if(a[2][2]==a[3][3]){
                    res =true;
                }
            }   
            if(x==2)
            {
                if(a[3][3]==a[1][1]){
                    res =true;
                }
            } 
            if(x==3)
            {
                if(a[1][1]==a[2][2]){
                    res =true;
                }
            } 
        }
    }


    if(x+y==4)
    {
        if(ST[1][3]&&ST[2][2]&&ST[3][1]){
            if(x==1)
            {
                if(a[2][2]==a[3][1]){
                    res =true;
                }
            }   
            if(x==2)
            {
                if(a[1][3]==a[3][1]){
                    res =true;
                }
            } 
            if(x==3)
            {
                if(a[1][3]==a[2][2]){
                    res =true;
                }
            } 
        }
    }
    return res;
}
int res = 0;



void dfs(int x,bool st)
{
    if(x==9){
        if(st)ans++;
        res++;
        return;
    }

    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(ST[i][j])continue;
            ST[i][j]=true;
            st|=check(i,j);
            dfs(x+1,st);
            ST[i][j]=false;
        }
    }
}



void solve()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)cin>>a[i][j];
    }
    dfs(0,false);
    cout<<(1-1.0*ans/res)<<endl;
  // cout<<res<<" "<<ans<<endl;






}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cout << setprecision(15) << fixed;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}