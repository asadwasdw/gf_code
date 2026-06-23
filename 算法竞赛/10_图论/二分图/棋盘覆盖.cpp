#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int n,k;
int st[N][N];
bool st2[N][N];
PII match[N][N];


bool find(int x,int y){
    for(int k=0;k<4;k++){
        int X = x+dx[k];
        int Y = y+dy[k];


        if(X<1||X>n||Y<1||Y>n)continue;
        if(st[X][Y])continue;
        if(st2[X][Y])continue;
        st2[X][Y]=true;

        if(match[X][Y].first==0||find(match[X][Y].first,match[X][Y].second)){
            match[X][Y]={x,y};
            return true;
        }
    }

    return false;
}



void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        st[a][b]=1;
    }
    int res = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            if(st[i][j])continue;
            if((i+j)%2)continue;

            memset(st2,0,sizeof st2);
            if(find(i,j))res++;
        }
    }
    cout<<res<<endl;







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