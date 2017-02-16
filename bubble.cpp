#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  
  int size = 10;
  int arr[10];
  int t;
  
  for (int i = 0; i < size; i++) arr[i] = rand() % 100 + 1;
  cout << "Начальный массив: ";
  for (int i = 0; i< size; i++) cout << arr[i] << ' ';
  
  for (int j = 1; j < size; j++)
    for (int k = size - 1; k >= j; k--){
      if (arr[k-1] > arr[k]) {
	t = arr[k];
	arr[k] = arr[k-1];
	arr[k-1] = t;
      }
    }
    
    cout << "\nОтсортированный массив: ";
    for (int i = 0 ; i < size; i++) cout << arr[i] << ' ';
    cout << '\n';
  return 0;
}