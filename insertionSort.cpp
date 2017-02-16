#include <iostream>

using namespace std;

void insSort(int *p);
      
int main(){

  int init[] = {7, 1, 1, 9, 8, 4, 5, 0, 17, 88, 24, 28, 24, 29, 24, 91, 15, 0};
  
  cout << "\nНачальный массив:\t";
  for (int i = 0; i < 18; i++) cout << init[i] << ' ';
  
  insSort(init);
  
  cout << "\nОтсортированный массив: ";
  for (int i = 0; i < 18; i++) cout << init[i] << ' ';
  
  cout << "\n\n";
  return 0;
}



void insSort(int *p) {
  
    for (int j = 1; j < 18; j++) {
      int i, temp;
      i = j - 1;
      temp = p[j];
      
      while (i>=0 && p[i] > temp) {	
	p[i+1] = p[i];
	i--;
      }
      p[i+1] = temp;
    }
}
      
      
