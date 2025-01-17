#define USECHRONO
#undef HAVE_MPI

typedef int (*mapfun_t)(int);

int f1(int x) { return x-3; }
int f2(int x) { return x-2; }
int f3(int x) { return (x>20? -1 : 2*x); }

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace std;

// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Matías Schvabauer
int DNI=43235111;

void btexpand(btree<int> &B,int root,mapfun_t f, btree<int>::iterator n) {
  
  auto lc = n.left();
  auto rc = n.right();
  
  if (f(*n)>=0) {
    lc=B.insert(lc,f(*n));
    btexpand(B,f(*n),f,lc);
  }
  if (f(*n+1)>=0){
    rc=B.insert(rc,f(*n+1));
    btexpand(B,f(*n+1),f,rc);
  }

}

void btexpand(btree<int> &B,int root,mapfun_t f) {
  
  if(root>=0){
    B.insert(B.begin(),root);
    btexpand(B,root,f,B.begin());
  }
  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(btexpand,vrbs);
  return 0;
}
