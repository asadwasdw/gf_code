#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

struct node
{
    __int128 l,r,w;

    inline bool operator > (const node &x) const {//小根堆，重载大于号，小的在前面
        return w>x.w;
    }
};
int n,k,m,a,b;



bool check(__int128 l,__int128 r)
{
    if (r - l >= m) return true;
    return l / m != r / m || l % m == 0;
}

 
void solve()
{
 
    cin>>n>>k>>m>>a>>b;

    priority_queue<node,vector<node>,greater<node>>q;
    while(q.size()){
        q.pop();
    }
    __int128 ans = INFll;
    if (k == 1) {
        if (n % m == 0) {
            cout << 0 << '\n';
        }else {
            cout << -1 << '\n';
        }
        return;
    }    

    if (n % m == 0) {
        cout << 0 << '\n';
        return;
    }

    __int128 t= 0;
    while(1)
    {
        q.push({n,n,t});
        n/=k;
        t+=b;
       // cout<<n<<endl;
        if(n%m==0)
        {
            ans=min(ans,t);
        }
        if(n==0)
        {
           q.push({n,n,t});
           //cout<<t<<endl;
            break;
        }
    }



    while(q.size())
    {
        node t = q.top();q.pop();
        __int128 l = t.l;
        __int128 r = t.r;
       
        __int128 w = t.w+a;

        __int128 tl = l*k;
       __int128 tr = r*k+k-1;

       
        if(check(tl,tr))
        {
             ans=min(w,ans);
             break;
        }
        else 
            q.push({tl,tr,w});
   
    }
    cout<<(ll)ans<<endl;
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