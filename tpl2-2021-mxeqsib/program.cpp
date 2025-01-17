#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace std;

// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Schvabauer Matías
int DNI=43235111;

void Nodos(tree<int> &T, tree<int>::iterator n, map<int,int> count, int &max, int l){
  int valor=0;
  if(n==T.begin()){
    n=n.lchild(); 
  }
  
  while(n!=T.end()){
    
    auto c=n.lchild();
    
    count.insert(pair<int,int>(l,*n));
    map<int,int>::iterator itaux2=count.end();
    for( map<int,int>::iterator it=itaux2; it!=count.begin(); --it ) { 
      map<int,int>::iterator itaux=--it;
      ++it;
      for( map<int,int>::iterator it2=itaux; it2!=count.begin(); --it2 ) { 
        if(it2==count.begin()){
          
        }else{
          if(it->second==it2->second){
            ++valor;
          }
        }
      }
      if(valor>max){
        max=valor;
      }
    }
    Nodos(T,c,count,max,l);
    ++l;
    ++n;
  }
  
}
  
  
int maxeqsiblings(tree<int> &T) {
  int max=0,l=0;
  map<int,int> count;
  Nodos(T,T.begin(),count,max,l);
  
  return max;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(maxeqsiblings,vrbs);
  return 0;
}
