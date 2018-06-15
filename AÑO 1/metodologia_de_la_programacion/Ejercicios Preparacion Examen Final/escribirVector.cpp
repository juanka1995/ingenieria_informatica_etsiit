#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  ofstream f1("vector.bin", ios::binary|ios::out);
  if(!f1) {
    cerr << "...." << endl;
    return 1;
  }

  int n;
  int *vector;

  cout << "Nº elementos: ";
  cin >> n;

  vector = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> vector[i];
  }

  f1.write(reinterpret_cast<char*>(&n), sizeof(int));
  f1.write(reinterpret_cast<char*>(vector), sizeof(int)*n);

  delete[] vector;

  f1.close();


  return 0;
}
