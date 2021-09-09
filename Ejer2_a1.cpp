#include <iostream>
#include <list>
using namespace std;

void BasicSort(list<int>& L){
	list<int> L2;
	list<int>::iterator itB;
	
	while(!L.empty()){
		
		int Minimo=9999999;
		
		for( auto itC=L.begin(); itC!=L.end(); ++itC ) { 
			if(Minimo>=*itC){
				Minimo=*itC;
				itB=itC;
			}
		}
		
		L2.push_back(Minimo);
		L.erase(itB);
	}
	
	L=L2;
}


int main() {
	
	list<int> L{2,4,1,5,8,0};
	
	BasicSort(L);
	
	for( auto it=L.begin(); it!=L.end(); ++it ) { 
		cout<<*it<<endl;
	}
	
	
	return 0;
}

