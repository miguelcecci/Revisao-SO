#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
//simular temrinal

int main(void){
  char lc[81];
  char *argv[20];
  int pid, i, status;

  while(1){ //mantem o programa rodando em loop
    printf("Prompt >");
    gets(lc); //guarda input em lc ( "warning: the `gets' function is dangerous and should not be used." )
    //fgets(lc, sizeof(lc), stdin); //funçao alternativa à função gets() -> porem quando usada no lugar do gets gera erro no execv

    if(!strcmp(lc,"")){ //se lc for igual a "" (vazio)
      continue; // ignora todo o bloco de codigo abaixo e volta ao inicio da iteraçao
    }

    argv[0] = strtok(lc, " "); //corta a string antes do espaço e guarda em argv[0]
    if(!strcmp( argv[0], "exit")){ //caso argv[0]=="exit"
      exit(0);  //termina a execuçao do programa
    }

    i=1; //começa o loop em 1
    while(i < 20 && (argv[i]=strtok(NULL, " "))){ //esse loop atribui valor nulo ao argv exeto ao argv[0] obs talvez esse loop possa ser substituido por um memset
      i++;
    }

    if((pid = fork())== -1){ //cria o fork e caso aconteça erro, o valor retornado será -1
      printf("erro no fork");
      exit( 1 ); //termina a execuçao do programa
    }

    if(pid == 0){ //caso pid == 0 temos um processo filho
      if(execvp(argv[0], argv)){ //retorna -1 caso ocorra erro
        printf("Erro no execv \n"); //
        exit(1);
      }
    }
    wait(&status);// espera fim do processo filho para dar procedencia ao programa
  }
}
////////falta remover warnings /////

// consulta para o comando ou stringcompare strcmp(): https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm
// porque a funçao gets() nao deve ser usada: http://stackoverflow.com/questions/1694036/why-is-the-gets-function-so-dangerous-that-it-should-not-be-used
// consulta execvp: https://linux.die.net/man/3/execvp
