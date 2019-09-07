#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main()
{
    ll n,q;
    cin>>n>>q;

    ll queries[q][3];
    ll user_id[q];

    REP(i,0,q)
    {
        cin>>queries[i][0];

        if(queries[i][0]==1)
        {
            cin>>queries[i][1]>>queries[i][2];

            user_id[i]=queries[i][1];
        }
    }

    sort(user_id,user_id+q);

    ll user_value[q];
    REP(i,0,q) user_value[i]=0;

    ll max_user_id;
    ll flag_max_user_id=0;

    REP(i,0,q)
    {
        if(queries[i][0]==1)
        {
            ll x=lower_bound(user_id,user_id+q,queries[i][1])-user_id;
            
            user_value[x]+=queries[i][2];

            if(flag_max_user_id==0) 
            {
                flag_max_user_id=1;
                max_user_id=x;
            }
            else if(user_value[x]>user_value[max_user_id])
            {
                max_user_id=x;
            }
        }
        else
        {
            if(flag_max_user_id==0) cout<<"No data available."<<endl;
            else cout<<user_id[max_user_id]<<endl;
        }
    }

    return 0;
}