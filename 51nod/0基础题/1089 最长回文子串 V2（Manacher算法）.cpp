#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;

string s,t;
int n,m;
int l[N*3];

int main(){
  cin>>t;
  m=t.size();
  n=2*m+1;
  s.reserve(n+1);
  s[0]='@',s[1]='#',s[n]='%';
  for(int i=1;i<=m;i++)
  {
    s[i<<1]=t[i-1];
    s[i<<1|1]='#';
  }

  int ans=0,k=0,r=0;

  for(int i=1;i<=n;i++)
  {
     if(i<r)l[i]=min(r-i,l[k*2-i]);
     else l[i]=1;

     while(s[i-l[i]]==s[i+l[i]])l[i]++;

     if(l[i]+i>r){
        k=i;
        r=i+l[i];
     }
     ans=max(ans,l[i]-1);
  }
  cout<<ans<<endl;
}