#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

vector<int>s;


bool cmp(int a,int b)
{
    return a>b;
}

void solve()
{
    int n;cin>>n;

    int res= 0;

    for(int i=1;i<=n;i++)
    {
        char t;
        cin>>t;
       // cout<<t<<endl;
        if(t=='1')res++;
        else {
            s.push_back(res);
            res=0;
        }
    }
 

    //cout<<res<<endl;

    s.push_back(res);
    s.push_back(0);

    sort(s.begin(),s.end(),cmp);

    cout<<s[0]+s[1]<<endl;




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