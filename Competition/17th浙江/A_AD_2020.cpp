#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int f[10000][13][35];
int f2[10000][13][35];

int isyn(int x){
    if((x%4==0 &&x%100!=0 ) || x%400==0)return 1;
    return 0;
}

int p[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

string js(int x){
    string s;
    if(x<10)s+="0";
    return s+to_string(x);
}

void solve()
{
    // cout<<isyn(2100)<<endl;
    // for(int i=1;i<=12;i++)cout<<p[0][i]<<" ";cout<<endl;
    // for(int i=1;i<=12;i++)cout<<p[1][i]<<" ";cout<<endl;

    int t = 0;
    for(int i=2000;i<=9999;i++) {
        for(int j=1;j<=12;j++) {

            for(int k=1;k<=p[isyn(i)][j];k++){

                string s = to_string(i)+js(j)+js(k);
                int num = 0;
                for(int i=0;i<6;i++){
                    if(s.substr(i,3)=="202")num=1;
                }
                t+=num;
                f[i][j][k]=t;
                f2[i][j][k]=num;
                // cout<<i<<" "<<j<<" "<<k<<endl;
                // cout<<s<<endl;
            }
        }
    }

    int n;
    cin>>n;
    while(n--){
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        // cout<<x1<<" "<<y1<<" "<<z1<<endl;
        cout<<f[x2][y2][z2]-f[x1][y1][z1]+f2[x1][y1][z1]<<endl;
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