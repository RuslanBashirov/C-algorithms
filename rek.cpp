#include <iostream>

using namespace std;

void Req(int start, int end);

int main(){
  
  Req(1, 10);//show nums from 1 to 10;
  cout << ' ';
}

void Req(int start, int end){
   cout << start << ' ';
   if (start==end) return;
   Req(start+1, end);
}