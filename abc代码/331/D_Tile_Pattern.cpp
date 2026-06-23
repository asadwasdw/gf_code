#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[1010][1010];
int n,q;

int get(int x,int y) {

    int numx = x/n;
    int numy = y/n;
    int num = numx*numy;
    int res = num*a[n][n];

    x=x%n;
    y=y%n;

    res += numx*a[n][y];
    res += numy*a[x][n];
    res += a[x][y];
    return res;
}

void solve()
{

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            char t;
            cin>>t;
            if(t=='B')a[i][j]++;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }



    while(q--) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1++;
        x2++;
        y1++;
        y2++;

        cout<<get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1)<<endl;
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