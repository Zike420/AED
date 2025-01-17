#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace std;
typedef map<int,list<int>> graph;
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Schvabauer Matías
int DNI=43235111;

bool es_completo(graph &G){
  int cant=0,cant2=0;
  bool validacion;
  
  for( map<int,list<int>>::iterator it=G.begin(); it!=G.end(); ++it ) { 
    ++cant;
  }

  for( map<int,list<int>>::iterator it=G.begin(); it!=G.end(); ++it ) { 
    validacion=true;
    for( list<int>::iterator it2=it->second.begin(); it2!=it->second.end(); ++it2 ) { 
      ++cant2;
    }
    if(cant-1!=cant2){
      validacion=false;
      break;
    }
    cant2=0;
  }
  
  return validacion;
  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(es_completo,vrbs);
  
  return 0;
}
