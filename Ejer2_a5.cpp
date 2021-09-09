#include <iostream>
#include <list>
using namespace std;

void junta(list<int> &L, int c){
	list<int>LB;
	int a=0,b=0;
	list<int>::iterator it=L.begin();
	while(!L.empty()){
		a=*it+a;
		b++;
		if(c==b){
			LB.push_back(a);
			b=0;
			a=0;
		}
		it=L.erase(it);
	}
	if(a!=0){
		LB.push_back(a);
		a=0;
	}
	L=LB;
}


int main() {
	
	list<int> L{8,9,2,4,1,7,5,8,3,9};
	int c;
	cin>>c;
	
	junta(L,c);
	
	cout<<"[";
	for( auto it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<"  ";
	}
	cout<<"]";
	return 0;
}

