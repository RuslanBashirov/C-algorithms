#include <iostream>

using namespace std;

class MyClass {
  int val;
  int copynumber;
public: 
  MyClass(int i) { 
    cout << "Внутри конструктора \n";
    val = i; copynumber = 0; 
  }
  MyClass(const MyClass &o) { 
    cout << "Внутри конструктора копии \n";
    val = 100; copynumber = o.copynumber + 1;
  }
  ~MyClass() { 
    if (!copynumber) cout << "Разрушение оригинала\n";
    else cout << "Разрушение копии № " << copynumber << '\n';
  }
  
  int getval() { return val;}
};

void display(MyClass o) { cout << o.getval() << '\n'; }

int main() {
  
  MyClass obj(5);
  cout << obj.getval() << '\n';
  display(obj);
  
  return 0;
}