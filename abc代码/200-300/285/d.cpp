#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<cstring>
using namespace std;

unordered_map<string,int>mp;

const int N=4e5+10;
int h[N],ne[N],e[N],idx;

int rd[N];

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int cnt=0;

bool tppx()
{
    int num=0;
    queue<int>q;
    for(int i=1;i<=cnt;i++)
    {
       // cout<<rd[i]<<endl;

        if(rd[i]==0){
        
            q.push(i);

        }
    }


    while(q.size())
    {
        auto t = q.front();q.pop();
        num++;

        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            rd[j]--;

            if(rd[j]==0)q.push(j);
        }

    }
 //   cout<<num<<endl;

    return num==cnt;
}









int main()
{

    int n;cin>>n;


   memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        if(!mp[a]){
            cnt++;
            mp[a]=cnt;
        }
        if(!mp[b]){
            cnt++;
            mp[b]=cnt;
        }
        add(mp[a],mp[b]);
       // cout<<mp[a]<<" "<<mp[b]<<endl;
        rd[mp[b]]++;
    }

   if(tppx())cout<<"Yes";
   else cout<<"No";

    



}