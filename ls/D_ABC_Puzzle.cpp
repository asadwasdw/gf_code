#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

char rm[6][6];
int n;string a,b;
bool check(int x,int y){
    int cnt = 0;
    unordered_map<char,int>mp;
    for(int i=1;i<=x;i++){
        mp[rm[i][y]]++;
        int t = mp[rm[i][y]];int k = rm[i][y]-'A';
        if(k<3&&t>1)return 0;
        if(k<3)cnt++;
        if(cnt==1&&k<3){
            if(rm[i][y]!=b[y])return 0;
        }
    }
    if(x==n&&(!mp['A']||!mp['B']||!mp['C']))return 0;
    cnt =0;mp.clear();
    for(int i=1;i<=y;i++){
        mp[rm[x][i]]++;
        int t = mp[rm[x][i]];int k = rm[x][i]-'A';
        if(k<3&&t>1)return 0;
        if(k<3)cnt++;
        if(cnt==1&&k<3){
            if(rm[x][i]!=a[x])return 0;
        }
    } 
    if(y==n&&(!mp['A']||!mp['B']||!mp['C']))return 0;
    return 1;

}
bool dfs(int x,int y){
    if(x==n+1){
        return 1;
    }
    for(char i='A';i<='D';i++){
        rm[x][y] = i;
        if(check(x,y)){
            if(y==n){if(dfs(x+1,1))return 1;}
            else{
                for(int j=y+1;j<=n;j++){if(dfs(x,j))return 1;}
            }
        }
    }
    return 0;
}
void solve()
{
    cin>> n;
    cin>> a >> b;a = " "+a;b = " "+b;

    bool ok = dfs(1,1);
    if(ok){cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(rm[i][j]<'D')cout<<rm[i][j];else cout<<'.';
            if(j==n)cout<<endl;
        }
    }else cout<<"No";






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