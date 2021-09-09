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
	
	int b=S.size();
	
	for(int i=0;i<b-1;i++) { 
		aux.push(S.top());
		S.pop();
	}
	S.pop();
	S.push(20);
	
	b=aux.size();
	for(int i=0;i<b;i++) { 
		S.push(aux.top());
		aux.pop();
	}
	
	b=S.size();
	
	for(int i=0;i<b;i++) { 
		a=S.top();
		cout<<a<<"  ";
		S.pop();
	}	
	return 0;
}

