#include <iostream>

using namespace std;

void cipher(char *str, char *key);
void decipher(char *str, char *key);

int main() {
  
  char key[80];
  char str[80];
  cout << "\nВведите строку: ";
  cin >> str;
  cout << "Введите ключ шифрования: ";
  cin >> key;
  cipher(str, key);
  cout << "Зашифрованная строка: " << str;
  decipher(str, key);
  cout << "\nДешифрованная строка: " << str << '\n';
  
  cout << '\n';
  return 0;
  
}


void cipher(char *str, char *key) {
  
  int temp;
  int finish_key = 2;
  
  while (*str){
    for (int i = 0; i < finish_key; i++){
      if (*str & 128) temp = 1;
      *str = *str << 1;
      if (temp == 1) *str = *str | 1;
    }
    str++;
  }
}


void decipher(char *str, char *key) {
  
  int temp;
  int finish_key = 2;
  
  while (*str){
    for (int i = 0; i < finish_key; i++){
      if (*str & 1) temp = 1;
      *str = *str >> 1;
      if (temp == 1) *str = *str | 128;
      else *str = *str ^ 128;
    }
    str++;
  }
}