#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>

using namespace std;

unordered_map<int,set<int>>edg;


int main()
{

    int n,m;cin>>n>>m;

    //cout<<n<<m <<endl;

    int ans=n;

    while(m--)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            int a,b;
            cin>>a>>b;

            if(edg[a].size()==0)ans--;
            if(edg[b].size()==0)ans--;

            edg[a].insert(b);
            edg[b].insert(a);
            
        }
        else 
        {
            int x;
            cin>>x;

            if(edg[x].size())ans++;

            for(auto t:edg[x])
            {
                edg[t].erase(x);
                if(edg[t].size()==0)ans++;
            }
            edg[x].clear();

          

        }


        cout<<ans<<endl;

    }

}