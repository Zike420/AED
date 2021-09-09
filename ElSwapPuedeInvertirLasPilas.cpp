#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> S;
	stack<int> aux,aux1;
	int a;
	
	for(int i=0;i<10;i++) { 
		S.push(i);
	}
	
	swap(S,aux);
	
	S.push(20);
	
	int b=aux.size();
	
	for(int i=0;i<b;i++) { 
		a=aux.top();
		aux.pop();
		aux1.push(a);
	}
	
	b=aux1.size();
	
	for(int i=0;i<b;i++) { 
		a=aux1.top();
		aux1.pop();
		S.push(a);
	}
	
	b=S.size();
	
	for(int i=0;i<b;i++) { 
		a=S.top();
		cout<<a<<"  ";
		S.pop();
	}	
	return 0;
}

