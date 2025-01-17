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

int cuenta_vueltas(list<int> &L,stack<int> &P){
  int SumTP=0, SumTL=0, vueltas=0;
  while(!P.empty()){
    SumTP=P.top()+SumTP;
    P.pop();
  }
  
  while(!L.empty()){
    if(SumTL>0){
      ++vueltas;
    }
    for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
      SumTL=*it+SumTL;
    }
    if(SumTL>SumTP){
      L.clear();
    }
  }
  
  return vueltas;

}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  ev.eval<1>(cuenta_vueltas,vrbs);

  return 0;
}
