#include <iostream>

using namespace std;


template <class Type> void qs(Type *arr, int left, int right);

int main(){
  
 
    double arrDouble[5] = {2.14, 1.22, 9.88, 0.1, 5.24};  
  cout << "Исходный массив: ";
  for (int i = 0; i<5; i++) cout << arrDouble[i] << ' ';
  
  qs(arrDouble, 0, 4);
  cout << "\nОтсортированный массив: ";
  for (int i = 0; i<5; i++) cout << arrDouble[i] << ' ';
  
  cout << '\n';
  return 0;
}

template <class Type> void qs(Type *arr, int left, int right){
  Type x;
  x = arr[(left+right)/2];
  int i = left; 
  int j = right;
  
  do{
  while ((arr[i] < x) && (i < right)) i++;
  while ((arr[j] > x) && (i > left)) j--;
  
  if (i<=j){
    Type temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
 } while (i<=j);
  
 if (left < j) qs(arr, left, j);
 if (i < right) qs(arr, i, right);
 
}