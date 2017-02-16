#include <iostream>

using namespace std;

const int MaxSize = 100;

class Set {
  int len;
  int members[100];
  int find(int num);
public: 
  Set() { len = 0; }
  void show();
  bool isMember(int num);
  Set operator +(int num);
  Set operator -(int num);
  Set operator +(Set obj);
  Set operator -(Set obj);
  Set operator &(Set obj);
  bool operator <(Set obj);
  bool operator >(Set obj);
};

void Set::show() {
  for (int i = 0; i<len; i++) cout << members[i] << ' ';
}

int Set::find(int num) {
  int i;
  for (i=0; i<len; i++) 
    if (members[i] == num) return i;
    return -1;
}

bool Set::isMember(int num) {
  if (find(num) != -1) return true;
  return false;
}

Set Set::operator +(int num) {
  Set newset = *this;
  if (len == MaxSize) { cout << "Множество полное\n"; return *this;}
  if (isMember(num)) { cout << "Член" << num << "уже есть в множестве\n"; return *this;}
  newset.members[newset.len] = num;
  newset.len++;
  return newset;
}

Set Set::operator -(int num) {
  Set newset;
  int index = find(num);
  for (int i = 0; i < len; i++) 
  if (i != index) newset = newset + members[i];
  return newset;
  }

//Обьединение множеств  - сумма элементов всех множеств с исключением дубликатов
Set Set::operator +(Set obj) {
  Set newset = *this;
  for (int i = 0; i< obj.len; i++)
    if (!isMember(obj.members[i])) newset = newset + obj.members[i];
    return newset;
}

//Разность множеств - множество, содержащее те элементы из первого множества,
//которых нет во втором множестве
Set Set::operator -(Set obj) {
  Set newset = *this;
  for (int i = 0; i < obj.len; i++) 
    if (isMember(obj.members[i])) newset = newset - obj.members[i];
    return newset;
  }
  
Set Set::operator &(Set obj) {
    Set newset;
    for (int i = 0; i < len; i++)
      if (obj.isMember(members[i])) newset = newset + members[i];
      return newset;
}

bool Set::operator <(Set obj) {
  if (len > obj.len) return false;
  for (int i = 0; i < len; i++) 
    if (!obj.isMember(members[i])) return false;
    return true;
}

bool Set::operator >(Set obj) {
  if (len < obj.len) return false;
  for (int i = 0; i < obj.len; i++) 
    if (!isMember(obj.members[i])) return false;
    return true;
}
  
int main() {
  
  Set a, b;
  a = a + 4 + 10 + 12 + 15 + 7 + 16 + 2;
  b = b + 4 + 10 + 12 + 16 + 7 + 2;
  
  cout << "\nМножество А: ";
  a.show();
  cout << '\n';
  
  cout << "Множество B: ";
  b.show();
  cout << '\n';
  
  cout << "Вычитаем из множества А существующий элемент \"15\": ";
  a = a - 15;
  a.show();
  cout << '\n';
  
  cout << "Вычитаем из множества А несуществующий элемент \"300\": ";
  a = a - 300;
  a.show();
  cout << '\n';
  
  cout << "Обьединяем множества А и B: ";
  Set c = a + b;
  c.show();
  cout << '\n';
  
  cout << "Разность множеств А и B: ";
  Set q = a - b;
  q.show();
  cout << '\n';
  
  cout << "Является ли множество А подмножеством B: ";
  cout << (a < b);	
  cout << '\n';
  
   cout << "Является ли множество А супермножеством B: ";
  cout << (a > b);	
  cout << '\n';
  
  cout << "Пересечение множеств А и В: ";
  Set x = a & b;
  x.show();
  cout << '\n';
  
  cout << '\n';
  return 0;
}