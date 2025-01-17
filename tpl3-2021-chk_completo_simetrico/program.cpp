#define USECHRONO
#undef HAVE_MPI

typedef int (*mapfun_t)(int);

int f1(int x) { return x+1; }
int f2(int x) { return x-1; }
int f3(int x) { return 2*x; }
int f4(int x) { return x; }

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed ;
using namespace std;

// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Matías Schvabauer
int DNI=43235111;

void chk_completo_simetrico(btree<int> &T, btree<int>::iterator n, bool &chk) {
  
  if(n==T.end()){
    return;
  }
  
  auto lc = n.left();
  auto rc = n.right();

  if(lc==T.end() and rc!=T.end() or lc!=T.end() and rc==T.end()){
    chk=false;
  }
  if(lc!=T.end() and rc!=T.end()){
    if(*lc!=*rc){
      chk=false;
    }
  }
  
  if(lc!=T.end()){
    chk_completo_simetrico(T,lc,chk);
  }
  
  if(rc!=T.end()){
    chk_completo_simetrico(T,rc,chk);
  }
 
}


bool chk_completo_simetrico(btree<int> &T) {
  bool chk=true;
  
  chk_completo_simetrico(T,T.begin(),chk);
  
  if(!chk){
    return false;
  }
  
  return true;
}
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(chk_completo_simetrico,vrbs);
  //ev.evalr<1>(chk_completo_simetrico,123,vrbs);
  return 0;
}
