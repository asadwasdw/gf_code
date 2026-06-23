#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#define int long long
using namespace std;

const int N=5e5+20;

struct Node
{
    int w;
    int sum;
    int num;
    int f;
   vector<int> son;
}tr[N];


Node build(int u)
{
    tr[u].num=1;
    
    for(auto T:tr[u].son)
    {
        Node t = build(T);
        tr[u].sum+=t.sum;
        tr[u].num+=t.num;
    }

    //tr[u].avg=tr[u].sum/tr[u].num;

    return tr[u];
}


Node modifydown(int u,int x)
{
    tr[u].w+=x;
    tr[u].sum=tr[u].w;

    for(auto T:tr[u].son)
    {
        Node t = modifydown(T,x);
        tr[u].sum+=t.sum;
    }

  // tr[u].avg=tr[u].sum/tr[u].num;
    return tr[u];
}

void modifyup(int u,int x)
{
   
    tr[u].sum+=x;

   //tr[u].avg=tr[u].sum/tr[u].num;

    if(u!=0)
    {
        modifyup(tr[u].f,x);
    }
}



signed main()
{
    int n,m;
   scanf("%lld%lld",&n,&m);

    for(int i=1;i<n;i++)
    {
       int p,w;
       cin>>p>>w;
      tr[p].son.push_back(i);
      tr[i].w=tr[i].sum=w;
      //tr[i].avg=w;
      tr[i].f=p;
    
    }

    build(0);

   //cout<<tr[0].sum<<endl;

    while(m--)
    {
        char c[2];
        int x,z;
       int y;
       // cin>>c>>x>>y>>z;
         scanf("%s%lld%lld%lld",&c,&x,&y,&z);
         

        if(c[0]=='S')
        {
            if(tr[x].w<y)
            {
                tr[x].w+=z;
                modifyup(x,z);
            }
        }
        else 
        {

             if(tr[x].sum<y*tr[x].num)
             {
                modifydown(x,z);
                if(x!=0)
                modifyup(tr[x].f,tr[x].num*z);
             }

        }

        // cout<<tr[0].sum<<endl;
         
    }

   /// cout<<tr[6].num<<endl;
 
 


    for(int i=0;i<n;i++)
    {    
       printf("%lld\n",tr[i].w);
    }

}