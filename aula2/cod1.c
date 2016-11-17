#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
  int pfd[2]; //variaveis do filedescriptor
  pipe(pfd); //cria um pipe na variavel pfd

  switch (fork()) {
    case -1: exit(1); break; //erro, termina a execuçao do programa

    case 0: close(0); //o processo filho ira executar essa parte do programa
    dup(pfd[0]);//cria um pfd[3]
    close(pfd[1]); //fecha o filedescriptor
    close(pfd[0]);
    execl("/usr/bin/wc","wc",NULL);
    break; //termina a execuçao
  }
  switch (fork()) {
    case -1: exit(1); break; //erro, termina a execuçao do programa

    //o processo filho ira executar essa parte do programa
    case 0: close(1);  //
    dup(pfd[1]);
    close(pfd[0]);
    close(pfd[1]);
    execl("/bin/ls","ls","-la",NULL);
    break;
  }
  return 0;
}
