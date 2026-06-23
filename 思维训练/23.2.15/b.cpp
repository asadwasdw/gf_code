#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;

const int N=1e5+10;
int n,q;
set<int>h,l;
unordered_map<int,int>numh,numl;

void init()
{
    for(int i=1;i<=n;i++){
        h.insert(i);
        l.insert(i);
    }

}

bool check(set<int>&s,int a,int b){
    if(a>b)
    {
        swap(a,b);
    }

    set<int>::iterator it=s.lower_bound(a);

 //   for(auto t:s)cout<<t<<" ";
  //  cout<<endl;

  if(it==s.end())return true;

    if(*it<=b){
        return false;
    }
    
    return true;
}


int main()
{
    cin>>n>>q;
    init();

    while(q--)
    {
        int t;
        cin>>t;
        if(t==1){
            int x,y;
            scanf("%d%d",&x,&y);

            if(numh[x]++ == 0){
                h.erase(x);
            }

            if(numl[y]++ == 0){
                l.erase(y);
            }
        }
        else if(t==2){
            int x,y;
            scanf("%d%d",&x,&y);

            if(--numh[x]==0){
                h.insert(x);
            }
            if(--numl[y]==0){
                l.insert(y);
            }
        }
        else{
            int x1,y1,x2,y2;
           scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(check(h,x1,x2)||check(l,y1,y2)){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }
    }

}
