#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include <fcntl.h>

int main(void){
  int pfd[2];//canais de entrada e saida do pipe
  char i[20];//buffer para guardar a leitura do pipe

  printf("antes: %d:%d\n", pfd[0], pfd[1]); //imprime os valores das variaveis antes do pipe ser criado
  pipe(pfd); // cria um pipe com canal de entrada em pfd[1], e um canal de saida ou leitura pfd[0]
  printf("depois: %d:%d\n", pfd[0], pfd[1]); //imprime os valores das variaveis após pipe ser criado

  write(pfd[1], "alo mundo", 10); // escreve no canal de entrada 10 bytes
  read(pfd[0], i, 5); //le 5 bytes do canal de saida, e grava no buffer
  printf("Resultado: %s\n", i); //imprime o valor gravado no video
  return 0;
}
//fonte para consulta funcoes read e write ftp://gd.tuwien.ac.at/languages/c/programming-bbrown/c_075.htm
//consulta pipe http://www.gnu.org/software/libc/manual/html_node/Creating-a-Pipe.html
// https://linux.die.net/man/2/pipe
