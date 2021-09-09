#include <iostream>
#include <list>
using namespace std;


void SelectionSort(list<int>& L){
	
	list<int>::iterator itB=L.begin();
	
	for( auto it=L.begin(); it!=L.end(); ++it ) { 
		for( auto itC=L.begin(); itC!=L.end(); ++itC ) { 
			if(*itB<*itC){
				iter_swap(itC,itB);
			}
		}
		itB++;
	}
}


int main() {
	
	list<int> L{2,4,1,5,8,0};
	
	SelectionSort(L);
	
	for( auto it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<endl;
	}
	
	
	return 0;
}

