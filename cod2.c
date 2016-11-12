#include<stdio.h>
#include<unistd.h>

int main(void){
  execl("/bin/ls", "ls", NULL); //funçao chama um comando que pode ser executado no terminal, o caminho do programa é o primeiro argumento, o segundo argumento é o nome do arquivo, o terceiro argumento sao os argumentos do programa.
}
// fucina com comandos executados no terminal, como por exemplo: execl("/bin/date", "date", NULL);
// fonte para consulta sobre o comando execl http://www.mkssoftware.com/docs/man3/execl.3.asp
