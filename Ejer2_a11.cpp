#include <iostream>
#include <list>
#include <string>
using namespace std;

bool is_palindromo(char* S){
	string ss=S, sss=S;
	string::iterator itA= ss.begin();
	string::iterator itB= --ss.end();
	string::iterator itC= ++ss.begin();
	
	while(itC!=itB && itA!=itB){
		
		swap(*itA,*itB);
		
		itB--;
		itA++;
		itC++;
	}
	if(itC==itB){
		swap(*itA,*itB);
	}
	for( string::iterator it=ss.begin(); it!=ss.end(); ++it ) { 
		if(*it==' '){
			ss.erase(it);
		}
	}
	for( string::iterator it=sss.begin(); it!=sss.end(); ++it ) { 
		if(*it==32){
			sss.erase(it);
		}
	}
	
	
	return sss.compare(ss);
}

	int main() {
		
		char str1[] = "anita lava la tina";
		
		int a=is_palindromo(str1);
		
		if(a==0){
			cout<< "Es un palindromo" <<endl;
		}else{
			cout<< "No es un palindromo" <<endl;
		}
		
		return 0;
	}
	
