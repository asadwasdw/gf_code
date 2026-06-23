#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N=2e5+10;

int l[N],r[N];


int main()
{
    memset(l,-1,sizeof l);
    memset(r,-1,sizeof r);

    int n,m;
    cin>>n>>m;

    while(m--)
    {
        int op,a,b;
        cin>>op>>a;

        if(op==1)
        {
            cin>>b;
            r[a]=b;
            l[b]=a;
        }
        else if(op==2)
        {
            cin>>b;
            r[a]=-1;
            l[b]=-1;
        }
        else 
        {
            queue<int>ans;
            while(l[a]!=-1){
                a=l[a];
            }
            //a=l[a];


            while(a!=-1){
                ans.push(a);
                a=r[a];
            }
          cout<<ans.size()<<" ";
          while(ans.size())
          {
            cout<<ans.front()<<" ";
            ans.pop();
          }
          cout<<endl;
        }


    }





}

