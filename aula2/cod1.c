#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
  int pfd[2];
  pipe(pfd);

  switch (fork()) {
    case -1: exit(1); break;

    case 0: close(0);
    dup(pfd[0]);
    close(pfd[1]);
    close(pfd[0]);
    execl("/usr/bin/wc","wc",NULL);
    break;
  }
  switch (fork()) {
    case -1: exit(1); break;

    case 0: close(1);
    dup(pfd[1]);
    close(pfd[0]);
    close(pfd[1]);
    execl("/bin/ls","ls","-la",NULL);
    break;
  }
  return 0;
}
