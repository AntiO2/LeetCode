//
// Created by Anti on 2024-01-11.
//
#include <stdio.h>
int addMinimum(char * word){
  char* curr = word;

  int except = 0;
  int ans = 0;
  while(*curr!='\0') {
    int now = *curr - 'a';
    if(now!=except) {
      ans+=(now + 3 - except)%3;
      except = (now+1) % 3;
    } else {
      except = (except+1) %3;
    }
    ++curr;
  }
  if(except!=0) {
    ans+=(3-except);
  }
  return ans;
}

int main() {
  char* word="aaa";
  printf("%d", addMinimum(word));
}