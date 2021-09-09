#include <iostream>
#include <list>
using namespace std;

void invert(list<int> &L){
	list<int>::iterator itA= L.begin();
	list<int>::iterator itB= --L.end();
	list<int>::iterator itC= ++L.begin();
	
	while(itC!=itB && itA!=itB){
		
		swap(*itA,*itB);
		
		itB--;
		itA++;
		itC++;
	}
	if(itC==itB){
		swap(*itA,*itB);
	}
	
}


int main() {
	
	list<int> Lista{1,2,3,4,5,6,7,8};
	
	invert(Lista);
	
	cout<<"[";
	for( auto it=Lista.begin(); it!=Lista.end(); ++it ) { 
		cout<<*it<<"  ";
	}
	cout<<"]";
	return 0;
}

