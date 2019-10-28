#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
vector<int> adj[N];
int clr[N];
bool vis[N];

int dfs(int x){int i;
for(i=0;i<adj[x].size();i++){
	if(vis[adj[x][i]]==false){
	vis[adj[x][i]]=true;
	clr[adj[x][i]]=!clr[x];
	if(!dfs(adj[x][i]))
		return false;
	}
	else if(clr[adj[x][i]] == clr[x]){
	return false;}
}
return true;	}
	

	


int main(){
int n,m,i,j,x,y,c=0;
cin>>n>>m;
for(i=0;i<m;i++){
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);}
vis[0]=1;
clr[0]=1;
c=dfs(0);
cout<<c<<" "<<endl;
for(i=0;i<n;i++)
cout<<clr[i]<<" ";	}







