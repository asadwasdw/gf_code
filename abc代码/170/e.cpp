#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
const int N=2e5+10;
int m[N];
multiset<int>mx,kg[N];
int f[N];
int w[N];


void update(int u)
{
    if(kg[u].size()==0)m[u]=1e9+10;
    else m[u]=(*kg[u].rbegin());
}

int main()
{
    int n,Q;
    cin>>n>>Q;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        w[i]=a;
        f[i]=b;
        kg[b].insert(a);
    }

    for(int i=1;i<N;i++)
    {
        update(i);
        mx.insert(m[i]);
    }

    while(Q--)
    {
        int a,b;
        cin>>a>>b;
        int fa=f[a];
        kg[fa].erase(kg[fa].find(w[a]));
        kg[b].insert(w[a]);

        mx.erase(mx.find(m[fa]));
        mx.erase(mx.find(m[b]));

        update(fa);
        update(b);

         mx.insert(m[fa]);
         mx.insert(m[b]);
         f[a]=b;

         cout<<(*mx.begin())<<endl;
    }



}