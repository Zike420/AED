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
// Nombre: Matías Schvabauer
int DNI=43235111;

void set_classify(vector<set<int>> &VS,set<int> &S0,int &superset,int &subset,int &disjoint, int &equal,int &other) {
  superset=0; subset=0; disjoint=0; equal=0; other=0;
  for(size_t i=0;i<VS.size();i++) { 
    set<int> C;
    set_intersection(S0,VS[i],C);
    if(C.empty()){
      ++disjoint;
    }
  }
  for(size_t i=0;i<VS.size();i++) { 
    set<int> B;
    set<int> C;
    set_difference(VS[i],S0,B);
    set_difference(S0,VS[i],C);
    if(B.empty() and C.empty()){
      ++equal;
    }
  }
  for(size_t i=0;i<VS.size();i++) { 
    set<int> B;
    set<int> C;
    set_difference(VS[i],S0,C);
    set_difference(S0,VS[i],B);
    if(C.empty()){
      if(!B.empty()){
        ++subset;
      }
    }
  }
  for(size_t i=0;i<VS.size();i++) { 
    set<int> B;
    set<int> C;
    set_difference(VS[i],S0,B);
    set_difference(S0,VS[i],C);
    if(C.empty()){
      if(!B.empty()){
        ++superset;
      }
    }
  }
  for(size_t i=0;i<VS.size();i++) { 
    set<int> A;
    set<int> B;
    set<int> C;
    set_intersection(S0,VS[i],A);
    set_difference(VS[i],S0,B);
    set_difference(S0,VS[i],C);
    if(!A.empty() and !B.empty() and !C.empty()){
      ++other;
    }
  }
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(set_classify,vrbs);
  return 0;
}
