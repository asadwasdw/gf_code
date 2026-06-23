#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+10;
ll a[N],ans[N];
int n,q;
ll len;


int num[N];

struct g
{
    int id,l,r;

}query[N];

int get(int x)
{
    return x/len;
}

bool cmp(g a, g b)
{
    int i=get(a.l);
    int j=get(b.l);
    if(i!=j)return i<j;
    return a.r<b.r;
}

ll js(ll x)
{
    if(x<3)return 0;
    return x*(x-1)*(x-2)/6;
}

void add(int x,ll& res)
{
    res-=js(num[x]);
    num[x]++;
    res+=js(num[x]);
}

void del(int x,ll& res)
{
    res-=js(num[x]);
    num[x]--;
    res+=js(num[x]);
}



int main()
{
    ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
    cin>>n>>q;
    len=max(1ll,(ll)sqrt(n*n/q));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        query[i]={i,l,r};
    }

    sort(query+1,query+q+1,cmp);
    ll res=0;

    for(int k=1,i=1,j=0;k<=q;k++)
    {
        int id=query[k].id;
        int l=query[k].l;
        int r=query[k].r;


        while(i<l)del(a[i++],res);
        while(i>l)add(a[--i],res);
        while(j<r)add(a[++j],res);
        while(j>r)del(a[j--],res);
        
        ans[id]=res;

    }

    for(int i=1;i<=q;i++)cout<<ans[i]<<endl;


}