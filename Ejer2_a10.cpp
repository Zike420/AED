#include <iostream>
#include <list>
using namespace std;

list<string> josephus(list<string>& nombres, int n){
	list<string> Sequedan;
	list<string>::iterator itB= nombres.begin();
	int a=1;
	
	while(!nombres.empty()){
		if(a==n){
			
			Sequedan.push_back(*itB);
			itB=nombres.erase(itB);
			a=0;
			itB--;
		}
		if(++itB==nombres.end()){
			itB=nombres.begin();
		}
		a++;
	}
	return Sequedan;
}


int main() {
	
	list<string> Nombres{"A","B","C","D","E","F","G","H"};/*{"Damian","Lucas","Fred","Oscar","Carlos","Juan","Ramon"};*/
	
	int a;
	a=3;
	cout<<a<<endl;
	
	Nombres=josephus(Nombres, a);
	
	cout<<"Se quedaron: "<<endl;
	for( auto it=Nombres.begin(); it!=Nombres.end(); ++it ) { 
		cout<<*it<< endl;
	}
	
	
	return 0;
}

