#include <iostream>
#include <list>
using namespace std;

//Ejercicio de compactar

void compacta(list<int> &L,list<int> &S){
	
	list<int>::iterator itA=S.begin();
	list<int>::iterator itB=L.begin();
	int valor=0;
	
	while(itA!=S.end()){
		if(*itA>=0){
			for(int i=0;i<*itA;i++){ 
				valor=*itB+valor;
				itB=L.erase(itB);
				if(itB==L.end()){break;}
			}
			L.insert(itB,valor);
			valor=0;
			if(itB==L.end()){return;}
		}
		itA++;
	}
}

int main() {
	
	list<int> L{1,1,1,1,1,1,1};
	list<int> S{2,2,2,2};
	
	compacta(L, S);
	
	cout<<"[";
	for( auto it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<", ";
	}
	cout<<"]"<<endl;
	
	cout<<"[";
	for( auto it=S.begin(); it!=S.end(); ++it ) { 
		cout<<*it<<", ";
	}
	cout<<"]"<<endl;
	
	return 0;
}

