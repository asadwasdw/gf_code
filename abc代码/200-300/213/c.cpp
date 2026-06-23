#include<iostream>
#include<algorithm>

using namespace std;
typedef pair <int,int>PII;
typedef pair <int,PII>PIII;
const int N=1e5+10;
int h,w,n;
PIII wz[N];

bool cmp1(PIII a,PIII b){
    return a.second.second<b.second.second;
}

bool cmp2(PIII a,PIII b){
    return a.second.first<b.second.first;
}

bool cmp3(PIII a,PIII b){
    return a.first<b.first;
}



int main()
{
    cin>>h>>w>>n;
    
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b; 
        wz[i].first=i;
        wz[i].second={a,b};
    }

    sort(wz+1,wz+1+n,cmp1);
    int last=0;
    int t=0;
    for(int i=1;i<=n;i++)
    {
       if(wz[i].second.second!=last){
        t++;
        last=wz[i].second.second;
       }
         wz[i].second.second=t;
    }

    sort(wz+1,wz+1+n,cmp2);
    last=0;
    t=0;
    for(int i=1;i<=n;i++)
    {
       if(wz[i].second.first!=last){
        t++;
        last=wz[i].second.first;
       }
         wz[i].second.first=t;
       
    }
    sort(wz+1,wz+1+n,cmp3);

    for(int i=1;i<=n;i++)
    {
        cout<<wz[i].second.first<<" "<<wz[i].second.second<<endl;
    }

}