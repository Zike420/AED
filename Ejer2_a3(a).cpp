#include <iostream>
#include <list>
using namespace std;

void concatenar(list<int>& L1,list<int>& L2){
	for( list<int>::iterator it=L2.begin(); it!=L2.end(); ++it ) { 
		L1.insert(L1.end(),*it);
	}
}


int main() {
	
	list<int> L1{4,5,1,2,3};
	list<int> L2{7,10,33,20};
	
	concatenar(L1,L2);
	
	cout<<"[";
	for( auto it=L1.begin(); it!=L1.end(); ++it ) { 
		cout<<*it<<"  ";
	}
	cout<<"]";
	return 0;
}

