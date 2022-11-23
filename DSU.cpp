#include <bits/stdc++.h>
using namespace std;
vector <int> p;
void Init(int n){
	p.resize(n+1);
	for (int i=1; i<=n; i++){
		p[i]=i;
	}
}
int findSet(int x){
	if (x==p[x]) return x;
	return p[x]=findSet(p[x]);
}
void unionSet(int x,int y){
	x=findSet(x);
	y=findSet(y);
	if(x != y){
		p[y] = x;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int p;
	cin >> p;
	Init(p);
	while(p--){
		int x,y,z;
		cin >> x >> y >>z;
		if(z==1) unionSet(x,y);
		else {
			if(findSet(x)==findSet(y)) cout <<"1\n";
			else cout<< "0\n";
		}
	}
	return  0;
}
