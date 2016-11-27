#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char  *argv[]){

	pid_t pid; //na verdade nao se trata do id do processo
	int mypipefd[2];
	int ret;
	char buf[20];

	ret = pipe(mypipefd);

	if(ret == -1){ //caso o valor retornado e atribuido a variavel "ret" seja -1 indica um erro
		perror("pipe");
		exit(1); //termina a execucao
	}

	pid = fork();//caso o retorno do fork() seja '0' estamos tratando um processo filho, caso contrario, um baita paizao

	if(pid == 0){//processo filho
		printf("filho\n");
		write(mypipefd[1], "oi cambada", 20); //esse 20 se trata do numero de caracteres da mensagem escrita

	}else{//processo pai de familia
		printf("Era essa peca que voce queria?\n");
		read(mypipefd[0], buf, 15);
		printf("buf: %s\n", buf);
	}
}
