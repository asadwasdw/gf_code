#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
typedef long double db;
typedef pair<int,db>PII;
vector<vector<PII>>edg(N);
const db PI = acos(-1);
int n,m;

int get(int x,int y) 
{
    if(x==0)return 0;
    return x*2*m + y;
}

void add(int x1,int y1,int x2,int y2,double len) {

    edg[get(x1,y1)].push_back({get(x2,y2),len});
    edg[get(x2,y2)].push_back({get(x1,y1),len});
}


void solve()
{

    
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*m;j++){
            if(j==1)(add(i,j,i,2*m,PI*i/m));
            else add(i,j,i,j-1,PI*i/m);

            add(i,j,i-1,j,1);
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