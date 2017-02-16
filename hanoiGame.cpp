#include <iostream>

using namespace std;

const int maxLen = 5;
const int maxLevel = 3;

class Plast {
public:
  int len;
  Plast() {len = 0;}
  Plast(int a) {len = a;}
};

class Stolb {
public:
  int tNumber;
  Plast level[maxLevel];
  Stolb(int x) {tNumber = x;}
  Stolb(int x, Plast p1, Plast p2, Plast p3) { tNumber = x; level[0] = p1; level[1] = p2; level[2] = p3;}

  static bool isValid(Stolb obj) {
    for (int i = 0; i <= 1; i++) {
      if (obj.level[i+1].len >= obj.level[i].len) continue;
      else return false;
    }
    return true;
  }

//проверяю чтобы обьект не имел длину пластины 0
  static bool isValid(Stolb obj, int o1) { 
    if (obj.level[o1].len) return true;
    else return false;
  }

  static int findShortest(Stolb obj) {
    int i;
    for (i = 0; i < maxLevel; i++) { if (obj.level[i].len) return i;} 
    return 3; //вернет 3 если башня пуста полностью
  }

  static void change(Stolb &obj1, Stolb &obj2) {
    int o1 = findShortest(obj1);
    int o2 = findShortest(obj2) - 1;
    if (isValid(obj1, o1) && (o2 >= 0)) { 
    Stolb temp = obj2;
    temp.level[o2].len = obj1.level[o1].len;

    if (isValid(temp)) {
    obj2.level[o2].len = obj1.level[o1].len;
    obj1.level[o1].len = 0;
    }
    else { 
      cout << "\ncannot carry plast \'"; 
      for (int i=0; i < obj1.level[o1].len; i++) cout << '-';
      cout << "\' to tower #" << obj2.tNumber << '\n'; 
    }
   }
   else cout << "\nthere are no any plasts in this tower(FROM) or tower(TO) is full\n";
  }

  void show() {
    cout << "TOWER #" << this->tNumber << '\n';
    for (int i = 0; i < (maxLen - this->level[0].len)/2; i++) cout << ' ';
    for (int i = 0; i < this->level[0].len; i++) cout << '-';
    for (int i = 0; i < (maxLen - this->level[0].len)/2; i++) cout << ' ';
    cout << '\n'<< "  |  "<< '\n' << "  |  " << '\n';
    for (int i = 0; i < (maxLen - this->level[1].len)/2; i++) cout << ' ';
    for (int i = 0; i < this->level[1].len; i++) cout << '-';
    for (int i = 0; i < (maxLen - this->level[1].len)/2; i++) cout << ' ';
    cout << '\n'<< "  |  "<< '\n' << "  |  " << '\n';
    for (int i = 0; i < (maxLen - this->level[2].len)/2; i++) cout << ' ';
    for (int i = 0; i < this->level[2].len; i++) cout << '-';
    for (int i = 0; i < (maxLen - this->level[2].len)/2; i++) cout << ' ';
    cout << '\n';
  }
};


int main() {

  Plast p1(1), p2(3), p3(5);
  Stolb s1(1, p1, p2, p3), s2(2), s3(3);
  Stolb::change(s1, s2);
  Stolb::change(s1, s3);
  Stolb::change(s2, s3);
  Stolb::change(s1, s2);
  Stolb::change(s3, s1);
  Stolb::change(s3, s2);
  Stolb::change(s1, s2);
  s1.show();
  s2.show();
  s3.show();
  //int o1 = Stolb::findShortest(s1);
  //cout << Stolb::isValid(s1, o1);
  cout << '\n';
  return 0;
}