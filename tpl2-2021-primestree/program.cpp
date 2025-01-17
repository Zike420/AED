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


void decomp(int n,int &c1,int &c2){
  c1=sqrt(n);
  
  for(int i=c1;i>0;--i) { 
    if(n%i==0){
      c1=i;
      c2=n/c1;
      break;
    }
  }
  
  if(c1==1){
    c2=n;
  }
}

void primestree(tree<int> &T,int M, tree<int>::iterator nodo) {
  int c1,c2;
  
  decomp(M,c1,c2);

  if(c1==1){
    nodo=T.end();
  }else{
    tree<int>::iterator Hijo=nodo;
    Hijo=Hijo.lchild();
    
    Hijo=T.insert(Hijo,c1);
    primestree(T,c1,Hijo);
    ++Hijo;
    
    Hijo=T.insert(Hijo,c2);
    primestree(T,c2,Hijo);
  }
  
}

void primestree(tree<int> &T,int M) {
  T.insert(T.begin(),M);
  primestree(T,M,T.begin());
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0,seed=123;
  ev.eval<1>(primestree,vrbs);
  return 0;
}
