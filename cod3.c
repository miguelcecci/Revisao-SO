#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h> //biblioteca da funçao waitpid

int main(void){
  int status;
  while(1){
    //execl( "/bin/ls","ls",0 ); // leia_comandos( comando, parametros );
    if(fork() != 0){
      //pai
      waitpid( -1, &status, 0); //espera o processo filho terminar
    }else{
      //filho
      execve( "/bin/ls","ls", 0);
    }
  }
}
///////////////////------ATENÇÃO, EM OBRAS--------////////////////////////
