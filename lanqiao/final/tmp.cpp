#include<bits/stdc++.h>

using namespace std;
const int N=2e6+5;
int dir[4][2]={0,1,1,0,0,-1,-1,0},cnt=0;

map<pair<int,int>, int>vis;
struct node{
	int x,y,w;
}e[N];
typedef long long ll;
ll res=4;
void init()
{
	e[cnt].x=0;
	e[cnt].y=0;
	e[cnt].w=1;
	cnt++;
	e[cnt].x=2020;
	e[cnt].y=11;
	e[cnt].w=1;
	cnt++;
	e[cnt].x=11;
	e[cnt].y=14;
	e[cnt].w=1;
	cnt++;
	e[cnt].x=2000;
	e[cnt].y=2000;
	e[cnt].w=1;
	cnt++;
}
void count()
{
	//cout<<cnt<<'\n';
	for(int i=0;i<cnt;i++){
		if(e[i].w==1){
			res++;
			cout<<e[i].x<<' '<<e[i].y<<' '<<e[i].w<<'\n';
		}
	}
}
void bfs()
{
	int fen=0;
	queue<node>q1,q2;
	q1.push(e[0]);
	q1.push(e[1]);
	q1.push(e[2]);
	q1.push(e[3]);
	//vis[0][0]=1;vis[2020][11]=1;vis[11][14]=1;vis[2000][2000]=1;
//	cout<<q1.size()<<'\n';
//	node t=q1.front();
//	cout<<t.x<<' '<<t.y<<' '<<t.w<<'\n';
	while(1){
	    cout << fen << " " << res << endl;
		fen++;
		//cout<<fen<<'\n';
		if(fen%2==1){
			while(q1.size()){
				node h=q1.front();
				q1.pop();
				for(int i=0;i<4;i++){
					node tt;
					tt.x=h.x+dir[i][0];
					tt.y=h.y+dir[i][1];
					tt.w=1;
					if(!vis[make_pair(tt.x,tt.y)]){
						q2.push(tt);
						vis[make_pair(tt.x,tt.y)]=1;
						res++;
					}
				}
			}
			while(q1.size())q1.pop();
		}else{
			while(q2.size()){
				node h=q2.front();
				q2.pop();
				for(int i=0;i<4;i++){
					node tt;
					tt.x=h.x+dir[i][0];
					tt.y=h.y+dir[i][1];
					tt.w=1;
					if(!vis[make_pair(tt.x,tt.y)]){
						q1.push(tt);
						vis[make_pair(tt.x,tt.y)]=1;
						res++;
					}
				}
			}
			while(q2.size())q2.pop();
		}
		if(fen==2020)break;
		//cout<<q1.size()<<' '<<q2.size()<<'\n';
	}
//	int cnt=0;
//	while(q2.size()){
//		node t=q2.front();
//		q2.pop();
//		cnt++;
//	}
//	cout<<cnt<<'\n';
	cout<<res<<'\n';
}
int main()
{
	init();
	vis.insert({make_pair(0,0),1});
	vis.insert({make_pair(2020,11),1});
	vis.insert({make_pair(11,14),1});
	vis.insert({make_pair(2000,2000),1});
	bfs();
	
	//cout<<res<<'\n';
	return 0;
}
