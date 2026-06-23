#include<bits/stdc++.h>
#define int long long
#define PI 3.1415926
using namespace std;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
int qpow(int a,int k,int p){int res = 1;while(k){if(k&1)res = res*a%p;a = a*a%p;k>>=1;}return res;}
int C(int a,int b,int p){if(b>a)return 0;int res = 1;for(int i=1,j=a;i<=b;i++,j--){res = res*j%p;res = res*qpow(i,p-2,p)%p;}return res;}

//优先对列
//priority_queue <int,vector<int>,less<int> > q;//递减
priority_queue <PII,vector<PII>,greater<PII> > q;//递增
const int N=1e5+10;
PII A[N],B[N];

void solve()
{
    priority_queue<PII,vector<PII>,greater<PII>>a;
    priority_queue<PII,vector<PII>,greater<PII>>b;
    a.push({0,0});
    b.push({0,0});

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        A[i]={x,y};
    }

    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        B[i]={x,y};
    }

    for(int i=1;i<=n;i++)
    {
        PII ta=a.top();
        a.pop();
        a.push(A[i]);

        while(a.size()&&a.top().first<=ta.second+1)
        {
             ta.second=max(a.top().second,ta.second);
             a.pop();
        }
        a.push(ta);


        PII tb=b.top();
        //cout<<tb.first<<tb.second<<endl;
        b.pop();
        b.push(B[i]);

       while(b.size()&&b.top().first<=tb.second+1)
        {
           
             tb.second=max(b.top().second,tb.second);
             b.pop();
        }
        b.push(tb);
        // cout<<tb.first<<tb.second<<endl;

       //cout<<ta.second<<" "<<tb.second<<endl;

        if(ta.second>tb.second)cout<<"sa_win!";
        else if(ta.second<tb.second)cout<<"ya_win!";
        else cout<<"win_win!";

        
        cout<<endl;

        cout<<abs(ta.second-tb.second)<<endl;
    }






}

signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
   // int t;cin>>t;while(t--)
    solve();
}