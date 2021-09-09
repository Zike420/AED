#include <iostream>
#include <list>
using namespace std;

void ascendente1(list<int> &L, list<list<int>> &LL){
	list<int> aux;
	list<int>::iterator it=L.begin();
	list<int>::iterator itB=L.begin();
	itB++;
	while(it!=L.end()){
		if(*it>*itB){
			aux.push_back(*it);
			LL.push_back(aux);
			aux.clear();
		}else{
			aux.push_back(*it);
		}
		it++;
		itB++;
	}
	LL.push_back(aux);
}

int main() {
	
	list <int> L{8,9,1,3,2,4,6,7};
	list <list<int>> LL;
	
	ascendente1(L, LL);
	list<list<int>>::iterator itt=LL.begin();
	list<int> aux=*itt;
	for( auto it=aux.begin(); it!=aux.end(); ++it ) { 
		cout<< *it << endl;
	}	
	
	return 0;
}

