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

  bool EsPrimo(int numero){
    for(int i=2;i<numero;i++) {  
      if(modulo(numero,i)==0){
        return false;
      }
    }
    if(numero>1 || numero==2){
      return true;
    }
    return false;
  }
  
  void ordenar(stack<int> &P, int &numero){
    int x;
    if(P.empty() || numero>P.top()){
      P.push(numero);
    }else{
      x=P.top();
      P.pop();
      ordenar(P,numero);
      P.push(x);
    }
  }

  void primos(list<int> &L,stack<int> &P){
    for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
      int numero=*it;
      if(EsPrimo(numero)){
        if(P.empty()){
          P.push(numero);
        }else{
          ordenar(P,numero);
        }
      }
    }
  }

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  ev.eval<1>(primos,vrbs);

  return 0;
}
