#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N = 100;
int n,m;

typedef pair<int,int> PII;

PII a[N];
PII b[N];
PII c[N];

bool st[N];

int qpl[N];

bool cmp(PII a,PII b)
{
    if(a.first!=b.first)
    {
        return a.first<b.first;
    }
    return a.second<b.second;
}


bool dfs(int num)
{
    if(num==n+1)
    {

        for(int i=1;i<=m;i++)
        {
            int A=qpl[b[i].first];
            int B=qpl[b[i].second];

            if(A>B)swap(A,B);
            c[i]={A,B};
        }

        sort(c,c+m+1,cmp);

        for(int i=1;i<=m;i++)
        {
            if(c[i]!=a[i])
            {
                return false;
            }
        }

        // for(int i=1;i<=n;i++)cout<<qpl[i]<<" ";cout<<endl;

        // for(int i=1;i<=m;i++)
        // {
        //     cout<<c[i].first<<" "<<c[i].second<<" "<<a[i].first<<" "<<c[i].second<<endl;
        // }



        return true;
    }


    for(int i=1;i<=n;i++)
    {
        if(st[i])continue;

        st[i]=true;
        qpl[num]=i;
        bool t  = dfs(num+1);
        if(t)return true;
        st[i]=false;
    }
    return false;
}



void solve()
{

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int A,B;
        cin>>A>>B;
        if(A>B)swap(A,B);
        a[i]={A,B};
    }
    sort(a,a+m+1,cmp);

    for(int i=1;i<=m;i++){
        int A,B;
        cin>>A>>B;
        if(A>B)swap(A,B);
        b[i]={A,B};
    }

    bool ky = dfs(1);

    if(ky)cout<<"Yes";
    else cout<<"No";
}

int main()
{
    //int t;cin>>t;while(t--)
    solve();
}