#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int N=4e5+10;
int n,m;
int h[N],e[N],ne[N],idx;
int ind[N];
vector<int>ans;
int a[N];

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}


bool tppx()
{
    int cnt=0;
    queue<int>q;

    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0){
            q.push(i);
            cnt++;
            ans.push_back(i);
        }
    }
    if(cnt>=2)return false;

    while(q.size())
    {
        cnt=0;
        int t=q.front();q.pop();

        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            ind[j]--;
            if(ind[j]==0){
                cnt++;
                q.push(j);
                 ans.push_back(j);
            }
        }

        if(cnt>=2)return false;
    }

    
    if(ans.size()!=n)return false;

    return true;



}



int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);

    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        add(a,b);
        ind[b]++;
    }


    

    
    if(tppx()){
        cout<<"Yes"<<endl;

        int num=1;
        for(auto t:ans){
            a[t]=num++;
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";

    }
    else cout<<"No";


    

}