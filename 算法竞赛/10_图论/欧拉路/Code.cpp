#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;



stack <int>st_edge;
stack <char>st_ans;
int num[N];
int m;

void no_dfs(int v)
{
    int edge;
    while(num[v]<10){
        edge=10*v+num[v];
        num[v]++;
        //cout<<v<<" "<<edge<<endl;
        st_edge.push(edge);
        v=edge%m;
    }
}

bool solve()
{
    int n,edge=0;
    cin>>n;
    if(n==0)return false;
    m=1;

    for(int i=1;i<=n-1;i++)m*=10;
    for(int i=0;i<m;i++)num[i]=0;

    no_dfs(0);
    while(st_edge.size()){
        edge = st_edge.top();st_edge.pop();
        st_ans.push((char)(edge%10+'0'));
        no_dfs(edge/10);
    }

    for(int i=1;i<n;i++)cout<<"0";
    while(st_ans.size()){
        cout<<st_ans.top();st_ans.pop();
    }
    cout<<endl;

    return true;
}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    while(1)
    {
        if(!solve())break;
    }
}