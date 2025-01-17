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

void balanced_sublist(list<char>& L,list<char>& BL){
  int aveces=0,bveces=0,amayor=0,bmayor=0;
  while(!L.empty()){
    
    for( list<char>::iterator it=L.begin(); it!=L.end(); ++it ) { 
      if('a'==*it){
        ++aveces;
      }else{
        ++bveces;
      }
    }
    if(aveces==bveces){
      if(aveces>amayor && bveces>bmayor){
        BL=L;
        amayor=aveces;
        bmayor=bveces;
      }
    }
    aveces=0;
    bveces=0;
    
    L.pop_front();
  }
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  ev.eval<1>(balanced_sublist,vrbs);
  return 0;
}
