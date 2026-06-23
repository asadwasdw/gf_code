#include<iostream>
#include<algorithm>

using namespace std;

const int N=4e5+10;
int cnt;
bool st[N];
int pri[N];

void init()
{
    st[1]=true;

    for(int i=2;i<N;i++)
    {
        if(!st[i]){
            pri[cnt++]=i;
        }

        for(int j=0;i*pri[j]<N;j++){
            st[pri[j]*i]=true;
            if(i%pri[j]==0)break;
        }
    }

}

char solve()
{

    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);


    int cnt = 0;
    if(a%2)cnt++;
    if(b%2)cnt++;
    if(c%2)cnt++;

    if(cnt==0){
        return 'R';
    }

    if(cnt==1||cnt==3){
        return 'P';
    }

    if(a%2==0)swap(a,c);
    if(b%2==0)swap(b,c);
    
    a+=c;
    b+=c;
    if(!st[a+b-2*c])return 'R';
    if(c==0)return'P';
   if(st[a]||st[b])return 'P';
    return 'R';
}


int main()
{
   init();
  //  for(int i=0;i<100;i++)cout<<pri[i]<<" ";
   int t;scanf("%d",&t);while(t--)
   printf("%c\n",solve());
}