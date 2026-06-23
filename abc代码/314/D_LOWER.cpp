#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
string s;

struct op{
    int t,x;
    char c;
}p[N];

char bh3(char t)
{
    if(t>='a')return  (char)(t-'a'+'A');
    return t;
}

char bh2(char t)
{
    if(t<='Z')return  (char)(t-'A'+'a');
    return t;
}

void solve()
{
    int n;
    cin>>n;
    cin>>s;
    s=" "+s;
    int q;
    cin>>q;
    int last = 0; 
    for(int i=1;i<=q;i++){
        cin>>p[i].t>>p[i].x>>p[i].c;
        if(p[i].t>1)last= i;
    }

    for(int i=1;i<=q;i++){
        if(i==last){
            if(p[i].t==2){
                for(int i=1;i<=n;i++){
                    s[i]=bh2(s[i]);
                }
            }
            else {
                for(int i=1;i<=n;i++){
                    s[i]=bh3(s[i]);
                }
            }
        }
        else if(p[i].t==1){
            s[p[i].x]=p[i].c;
        }
    }

    for(int i=1;i<=n;i++)cout<<s[i];


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