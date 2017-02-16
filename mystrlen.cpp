#include <iostream>

using namespace std;

int mystrlen(char *arr);

int main(){
  char arr[80];
  cin >> arr;

  cout << "Всего символов: " << mystrlen(arr);
  
  cout << '\n';
  
  return 0;
}

int mystrlen(char *arr){
  int i = 0;
  while (arr[i]) i++;
  return i;
}