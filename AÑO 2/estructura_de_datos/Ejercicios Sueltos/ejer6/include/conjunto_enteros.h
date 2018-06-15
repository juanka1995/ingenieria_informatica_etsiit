#include <set>
#include <iostream>

using namespace std;

#ifndef _CONJUNTOENTEROS_H_
#define	_CONJUNTOENTEROS_H_

class ConjuntoEnteros{
  private:
    set<int> conjunto;
  public:
    bool estaIncluido(const ConjuntoEnteros &c) const;
    void insertar(int x);
    friend ostream & operator<<(ostream& os, const ConjuntoEnteros &c);
};

#endif
