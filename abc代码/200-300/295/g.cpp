#include<iostream>
#include<algorithm>

using namespace std;

const int N=2e5+10;

int f[N];
int father[N];

int find(int x)
{
    if(x!=f[x])return f[x]=find(f[x]);
    return f[x];
}


int main()
{

    int n;
    cin>>n;
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
         scanf("%d",&father[i]);
         f[i]=i;
    }

    int Q;
    cin>>Q;
    while(Q--)
    {
        int t;
        scanf("%d",&t);

        //cout<<Q<<" "<<t<<endl;

        if(t==2)
        {
            int x;
            cin>>x;
            cout<<find(x)<<endl;
        }
        else 
        {
            int l,r;
           scanf("%d%d",&l,&r);

            int T=l;
          
            while(T>r)
            {
                if(f[T] == T)
                {
                    f[T]=father[T];
                    T=father[T];
                }
                else 
                {  
                    T=find(T);
                }
            }
        }
    }

    return 0;
}