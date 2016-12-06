#include <stdio.h>
#include <string.h>
char* path[]={"these ","these ","these ","these ","these "};
int main ()
{
  char aux2[100];
  for(int j=0; j<=6; j++){
    strcat (aux2, path[j]);
  }
  puts (aux2);
  return 0;
}
