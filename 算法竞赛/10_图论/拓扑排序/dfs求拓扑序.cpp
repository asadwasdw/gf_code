#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 30;
int n,a[N],d[N][N];
int topo[N],v[N],ind[N];


void dfs(int u,int cnt)
{
    topo[cnt]=u;
    if(cnt==n-1){
        for(int i=0;i<n;i++)cout<<char(topo[i]+'a');
        cout<<endl;
        return;
    }

    v[u]=1;

    for(int i=0;i<n;i++){
        if(!v[a[i]]&&d[u][a[i]]){
            ind[a[i]]--;
        }
    }

     for(int i=0;i<n;i++){
        if(!ind[a[i]]&&!v[a[i]]){
            dfs(a[i],cnt+1);
        }
    }

     for(int i=0;i<n;i++){
        if(!v[a[i]]&&d[u][a[i]]){
            ind[a[i]]++;
        }
    }
    v[u]=0;
}


int main()
{

    char s[200];
    int len;

    while(gets(s)!=NULL){
        memset(d,0,sizeof d);
        memset(v,0,sizeof v);
        memset(ind ,0,sizeof ind);

        len=strlen(s);
        n=0;

        for(int i=0;i<len;i++){
            if(s[i]<='z'&&s[i]>='a')
            a[n++]=s[i]-'a';
        }

        sort(a,a+n);
        
        gets(s);
        len=strlen(s);
        int first=1;
        for(int i=0;i<len;i++)
        {
            int st,ed;
            if(first&&s[i]<='z'&&s[i]>='a'){
                st=s[i]-'a';
                first=0;
                continue;
            }

          if(!first&&s[i]<='z'&&s[i]>='a'){
            ed=s[i]-'a';
            first=1;
            ind[ed]++;
            d[st][ed]=1;
            continue;
          }
        }

        for(int i=0;i<n;i++){
            if(!ind[a[i]]){
                dfs(a[i],0);
            }
        }


        cout<<endl;

    }

    return 0;
}