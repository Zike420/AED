#include <iostream>
#include <stack>
using namespace std;


int main() {
	stack<int> S;
	
	for(int i=0;i<10;i++) { 
		S.push(i);
	}	

	for(int i=0;i<2;i++) { 
		S.pop();
	}
	
	S.push(5);
	
	int b=S.size();
	int a;
	
	for(int i=0;i<b;i++) { 
		a=S.top();
		cout<<a<<"  ";
		S.pop();
	}	
	return 0;
}

