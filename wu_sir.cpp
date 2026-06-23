//2 2,3 4,4 8
#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
typedef pair<int,int> PII;
#define endl '\n'
const int N=10010,INF=0x3f3f3f3f;
const int mod= 998244353;
const double eps=1e-12;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
vector<int> add(vector<int>a,vector<int>b){
    vector<int>c;
    int t=0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<min(a.size(),b.size());i++){
        t=t+a[i]+b[i];
        c.push_back(t%10);
        t/=10;
    }
    for(int i=min(a.size(),b.size());i<max(a.size(),b.size());i++){
        if(a.size()>b.size())t=t+a[i];
        else t=t+b[i];
        c.push_back(t%10);
        t/=10;
    }
    if(t)c.push_back(t);
    reverse(c.begin(),c.end());
    return c;
}
vector<int> ch(vector<int>a){
    vector<int>c;
    reverse(a.begin(),a.end());
    int t=0;
    for(int i=0;i<a.size();i++){
        t=2*a[i]+t;
        c.push_back(t%10);
        t/=10;
    }
    if(t)c.push_back(t);
    reverse(c.begin(),c.end());
    return c;
}
vector<int> mi(vector<int>a,vector<int>b){
    if(a.size()>b.size())return b;
    else if(a.size()<b.size())return a;
    else {
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]>b[i])return b;
            else return a;
        }
    }
    return a;
}
vector<int>d[N],f[N];
int last = 0;
void slove(){
    int n;cin>>n;
    for(int i=0;i<f[n].size();i++){
        cout<<f[n][i];
    }
    cout<<endl;
}
void init(){
    d[0]={1};
    f[1]={1};
    for(int i=1;i<10000;i++){
        d[i]=ch(d[i-1]);
    }
    int p=0,q=2;
    for(int i=2;i<10000;i++){
        	f[i]=add(f[i-1],d[q-1]);
        	p++;
        	if(p>=q)p=0,q++;
    }
}
signed main()
{
    int T=1;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    init();
    while(T--){
        slove();
    }
    return 0;
}