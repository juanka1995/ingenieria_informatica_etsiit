#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream f1("vector.bin", ios::binary|ios::in);
  if(!f1) {
    cerr << "...." << endl;
    return 1;
  }

  int n;
  int *vector;

  f1.read(reinterpret_cast<char*>(&n), sizeof(int));

  vector = new int[n];

  f1.read(reinterpret_cast<char*>(vector), sizeof(int)*n);

  for (int i = 0; i < n; i++) {
    cout << vector[i] << endl;
  }

  delete[] vector;

  f1.close();


  return 0;
}
