#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=6e3+150;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int a[N][N];

int t1[N][N];
int t2[N][N];
int t3[N][N];
int t4[N][N];

int lowbit(int x){
	return x&-x;
}

void add(int x,int y,int v)
{
    for(int i=x;i<N;i+=lowbit(i))
        for(int j=y;j<N;j+=lowbit(j))
        {
            t1[i][j]+=v;
            t2[i][j]+=v*x;
            t3[i][j]+=v*y;
            t4[i][j]+=v*x*y;
        }
}
void real_add(int x1,int y1,int x2,int y2,int v)
{
    add(x1,y1,v);
    add(x1,y2+1,-v);
    add(x2+1,y1,-v);
    add(x2+1,y2+1,v);
}
int ask(int x, int y)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
            res+=(x+1)*(y+1)*t1[i][j]-(y+1)*t2[i][j]-(x+1)*t3[i][j]+t4[i][j];
    return res;
}
int real_ask(int x1,int y1,int x2,int y2)
{
    return ask(x2,y2)-ask(x2,y1-1)-ask(x1-1,y2)+ask(x1-1,y1-1);
}



PII js(int x,int y) {
    PII res = {3005,1};
    x --, y --;
    res.first += x;
    res.second += x;
    res.first -= y;
    res.second += y;
    return res;
}

void print(PII a) {
    cout << a.first << " " << a.second << endl;
}


void update(PII A, PII B) {
    int x1 = A.first, x2=B.first, y1 = A.second, y2 = B.second;

    x1 = max(1,x1);
    x2 = max(1,x2);

    y1 = max(1,y1);
    y2 = max(1,y2);
    
    x1 = min(x1,N - 2);
    x2 = min(x2,N - 2);
    y1 = min(y1,N - 2);
    y2 = min(y2,N - 2);




    // cout << x1 << " " <<y1 << " " << x2 << " " << y2 << endl;

    // a[x1][y1] += 1;
    // a[x1][y2 + 1] -= 1;
    // a[x2 + 1][y1] -= 1;
    // a[x2 + 1][y2 + 1] += 1;

    real_add(x1,y1,x2,y2,1);
}



void solve()
{
    int n,m;
    cin >> n >> m;
    while(m --) {
        int x,y,R;
        cin >> x >> y >> R;
        PII a = js(x - R, y);
        PII b = js(x + R, y);
        // print(a);
        // print(b);
        update(a,b);
    }


    // for(int i = 0 ;i <= 10; i ++) {
    //     for(int j = 0; j <= 10; j ++) {
    //         cout << a[i][j] <<" \n"[j == 10];
    //     }
    // }


    for(int i = 1; i < N; i ++) {
        for(int j = 1; j < N; j ++) {
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1]; 
        }
    }


    // for(int i = 0 ;i <= 10; i ++) {
    //     for(int j = 0; j <= 10; j ++) {
    //         cout << a[i][j] <<" \n"[j == 10];
    //     }
    // }
    int ans = 0;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            PII t = js(i, j);
            // cout << i << " " << j << " "; print(t);
            // cout << a[t.first][t.second] % 2 << " \n"[j == n]; 
            ans += a[t.first][t.second] % 2;
        }
    }
    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}