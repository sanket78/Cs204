#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


 lli n;
 unordered_map<lli,lli> parent;
 unordered_map<lli,lli> Rank;

void makeset(){
    for(lli i=0;i<n;i++){
        parent[i]=i;
    }
}

lli find(lli i){                            // find by path-compression
    if(parent[i]!=i){
        parent[i]=find(parent[i]);
    }
    return parent[i];
}


void Union(lli i,lli j){                    //union by rank
    lli irep=find(i),irank,jrank;
    lli jrep=find(j);
    if(irep==jrep){
        return;
    }else{
         irank = Rank[irep];
         jrank = Rank[jrep];
        if(irank>jrank){
            parent[jrep]=irep;
        }else if(jrank>irank){
            parent[irep]=jrep;
        }else{
            parent[jrep]=irep;
            Rank[irep]++;
        }
    }
}


int main() {
   
    cin >> n;
   
    makeset();                   //initializing each number as a set i.e. making all as representatives
    lli u;
    cin >>u;                     // number of unions
    while(u--){
        lli a,b;
        cin >>a>>b;
        Union(a,b);              //union by rank
    }
    lli q;
    cin >>q;                     // No. of Queries
    while(q--){
        lli e,r;
        cin >>e>>r;
        if(find(e)==find(r)){    // if representatives same then same group
            cout << "YES\n";
        }else{
            cout <<"NO\n";
        }
    }


	return 0;
}