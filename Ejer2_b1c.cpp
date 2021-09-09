#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> S;
	int a;
	
	for(int i=0;i<10;i++) { 
		S.push(i);
	}	
	
	cout<<"Escribir"<<endl;
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++) { 
		S.pop();
	}
	S.pop();
	S.push(20);
	
	int b=S.size();
	
	for(int i=0;i<b;i++) { 
		a=S.top();
		cout<<a<<"  ";
		S.pop();
	}	
	return 0;
}

