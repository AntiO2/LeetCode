//
// Created by Anti on 2024-01-14.
//

#include <limits.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
void high_and_low (const char *strnum, char *result)
{
  // print your answer to result
  bool flag = true;
  int min = INT_MAX, max = INT_MIN;
  char* i = (char *) strnum;
  while(*i!=0) {
    char c = *i;
    if(c=='-') {
      flag = false;
      i++;
      c = *i;
    } else {
      flag = true;
    }
    int now = 0;
    while(c!=' '&&c!='\0') {
      now = now*10 + c-'0';
      i++;
      c = *i;
    }
    if(!flag) {
      now = -now;
    }
    if(now>max) {
      max = now;
    }
    if(now < min) {
      min = now;
    }
    if(c=='\0') {
      break ;
    }
    i++;
  }
  sprintf(result, "%d %d",max,min);
}

int main() {
  char* result = malloc(sizeof("42 -9"));
  memset(result,0,sizeof("42 -9"));
  high_and_low("8 3 -5 42 -1 0 0 -9 4 7 4 -4",result);
  printf("%s",result);
}