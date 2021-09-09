#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> S;
	int a;
	
	for(int i=0;i<10;i++) { 
		S.push(i);
	}	
	

	a=S.top();
	S.pop();
	S.pop();
	S.push(5);
	S.push(a);
	
	int b=S.size();
	
	for(int i=0;i<b;i++) { 
		a=S.top();
		cout<<a<<"  ";
		S.pop();
	}	
	return 0;
}

