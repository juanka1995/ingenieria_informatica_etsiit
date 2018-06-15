#include <iostream>
#include <vector>

using namespace std;

// Modifica el primer vector eliminando los elementos del
// segundo que ya estan en el primero
void borrarElemVector(vector<int> &v1, const vector<int> v2) {
  vector<int>::iterator it;
  vector<int>::const_iterator itc;
  for (itc = v2.begin(); itc != v2.end(); ++itc) {
    for (it = v1.begin(); it != v1.end();) {
      if (*itc == *it)
        it = v1.erase(it);
      else
        ++it;
    }
  }
}

void mostrarVector(const vector<int> &v1){
  vector<int>::const_iterator it;
  for (it = v1.begin(); it != v1.end() ; ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<int> v1,v2;

  for (int i = 4; i < 10; i++) {
    v1.push_back(i);
    if (i > 5 && i < 9)
      v2.push_back(i);
  }

  cout << endl << "Vector 1: ";
  mostrarVector(v1);
  cout << endl << "Vector 2: ";
  mostrarVector(v2);

  borrarElemVector(v1,v2);

  cout << endl << "Vector 1 tras borrado: ";
  mostrarVector(v1);
  return 0;
}
