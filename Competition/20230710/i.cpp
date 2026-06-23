#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int n,m;
int x,y;
char a[55][55];
int st = 0;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
vector<PII>zai[10];
int v= 0;

void init()
{
    zai[1].push_back({-1,0});
    zai[1].push_back({0,1});

    zai[3].push_back({0,1});
    zai[3].push_back({1,0});

    zai[5].push_back({1,0});
    zai[5].push_back({0,-1});

    zai[7].push_back({-1,0});
    zai[7].push_back({0,-1});
}


bool pd()
{
    int cnt =0;

    for(auto t:zai[st]){
        if(a[x+t.first][y+t.second]=='#'){
            cnt++;
        }
    }
    if(cnt<2)return false;
    return true;
}


void yd()
{

    for(int i=1;i<=v;i++)
    {
        int X = x+dx[st];
        int Y = y+dy[st];

        if(a[X][Y]=='#' || pd()||X<1||X>n||Y<1||Y>m){
            cout<<"Crash! "<<x<<" "<<y<<endl;
            v=0;
            return;
        }

        x=X;
        y=Y;
    }

    cout<<x<<" "<<y<<endl;
}


void solve()
{
    init();
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;
            cin>>t;
            a[i][j]=t;

            if(t=='*'){
                x=i;
                y=j;
            }
        }
    }

    int m;
    cin>>m;

    while(m--)
    {
        char op ;
        cin>>op;

        if(op=='U')v++;
        if(op=='R')st=(st+1)%8;
        if(op=='L')st= (st-1+8)%8;
        if(op=='D')v=max(v-1,0);
        yd();
        //cout<<m<<" "<<op<<" "<<st<<" "<<x<<" "<<y<<" "<<v<<endl;
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