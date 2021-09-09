#include <iostream>
#include <list>
using namespace std;

void reemplaza(list<int> &L, list<int>& SEQ,list<int> &REEMP){
	list<int>::iterator itB1=SEQ.begin();
	list<int>::iterator aux1;
	int aux2=0;
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		if(*itB1==*it){
			aux1=it;
			for( list<int>::iterator it1=SEQ.begin(); it1!=SEQ.end(); ++it1 ) { 
				if(*aux1==*it1){
					aux1++;
					aux2=0;
				}else{
					aux2=1;
					break;
				}
			}
			if(aux2==0){
				for( list<int>::iterator it1=SEQ.begin(); it1!=SEQ.end(); ++it1 ) {
					it=L.erase(it);
				}
				L.insert(it,REEMP.begin(),REEMP.end());
			}
		}
	}
}

int main() {

	list<int> L{1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
	list<int> SEQ{4,5,1};
	list<int> REEMP{9,7,3};
	
	reemplaza(L,SEQ,REEMP);
	
	cout<<"[";
	for( auto it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<"  ";
	}
	cout<<"]";
	return 0;
}

