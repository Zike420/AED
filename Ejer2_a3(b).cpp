#include <iostream>
#include <list>
using namespace std;

void concatenar(list<list<int>>& LL, list<int>& L){
	for( auto it=LL.begin(); it!=LL.end(); ++it ) { 
		list<int> Laux=*it;
		L.insert(L.end(),Laux.begin(),Laux.end());
	}
}

int main() {
	
	list<list<int>> LL{{4,5,666},{1,2,3}};
	list<int>L;
	
	concatenar(LL,L);
	
	cout<<"[";
	for( auto it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<"  ";
	}
	cout<<"]";
	
	return 0;
}

