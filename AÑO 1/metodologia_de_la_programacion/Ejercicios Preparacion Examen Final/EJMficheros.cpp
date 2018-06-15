#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  ofstream f1("tupadre.txt");
  int array_num[5]={1,2,3,4,5};
  int nuevo_array[5];

  f1 << 4 << endl;
  for (int i = 0; i < 5; i++) {
    cout << array_num[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < 5; i++) {
    f1.write(reinterpret_cast<char*>(&array_num[i]),sizeof(int));
  }

  f1.close();

  ifstream f2("tupadre.txt");

  f2.ignore(2);
  for (int i = 0; i < 5; i++) {
    f2.read(reinterpret_cast<char*>(&nuevo_array[i]),sizeof(int));
  }

  for (int i = 0; i < 5; i++) {
    cout << nuevo_array[i] << " ";
  }
  cout << endl;

  f2.close();
  return 0;
}
