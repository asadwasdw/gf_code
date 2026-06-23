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
string a;
int b;
int n;

map<char,int>st;
int ans = 0;

int st2[10];

void dfs(int x) {
    // cout<<a<<endl;
    if(x == n) {
        
        int A = atoi(a.c_str());
        if(A%8 || A>b || (a[0]=='0' &&n!=1)){

        }
        else ans++;
        return;
    }
    if(a[x]='9' && a[x]<='0') {
        dfs(x+1);
    }
    else if(a[x]=='_') {
        for(int i=0;i<=9;i++){
            a[x]=(char)(i+'0');
            dfs(x+1);
            a[x]='_';
        }
    }
    else {
        for(auto &t:st) {
            if(a[x] == t.first) {
                if(t.second!=-1) {
                    a[x] = (char)(t.second+'0');
                    dfs(x+1);
                    a[x] = t.first;
                }
                else {
                    for(int i=0;i<=9;i++){
                        if(st2[i])continue;
                        st2[i]=1;
                        t.second=i;
                        a[x]=(char)(i+'0');

                        dfs(x+1);

                        a[x]=t.first;
                        t.second=-1;
                        st2[i]=0;
                    }
                }
            }
        }
    }
}


void solve()
{
    st['a']=-1;
    st['b']=-1;
    st['c']=-1;
    st['d']=-1;
    ans=0;
    cin>>n;
    cin>>a>>b;
    dfs(0);
    cout<<ans<<"\n";









}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}