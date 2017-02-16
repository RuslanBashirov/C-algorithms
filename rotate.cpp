#include <iostream>

using namespace std;

short int lrotate(short int val, int i);
short int rrotate(short int val, int i);
void showBinary(short int val);

int main(){
  
  short int val = 24845;
  int i = 2;
  cout << "initial: "; 
  showBinary(val); 
  cout << '\n';
  cout << "после циклического сдвига влево: ";
  showBinary(lrotate(val, i));
  cout << "\nпосле циклического сдвига вправо: ";
  showBinary(rrotate(val, i));
  
  cout << '\n';
return 0;
}

short int lrotate(short int val, int i){
  int t;
  for (int j = 0; j < i; j++){ 
  if (val & 32768) t = 1;
  else t = 0;
  val = val << 1;
  if (t == 1) val = val | 1;
  }
  return val;
}

short int rrotate(short int val, int i){
  int t;
  for (int j = 0; j < i; j++){ 
  if (val & 1) t = 1;
  else t = 0;
  val = val >> 1;
  if (t == 1) val = val | 32768;
  else val = val ^ 32768;
  }
  return val;
  
}


void showBinary(short int val){
  for (int t = 32768; t >= 1; t /= 2){
    if (val & t) cout << 1;
    else cout << 0;
  }
}
  
  