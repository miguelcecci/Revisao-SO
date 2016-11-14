#include <stdio.h>
#include <unistd.h> //esse cabeçario é responsavel pela funçao 'fork()'

int main(void){
  int ID = -9999;
  printf("antes: %d\n", ID);
  ID = fork(); //a partir daqui dois processos serao criados e ambos executarão as linhas restantes do codigo
  printf("depois: %d\n", ID); //como um fork foi criado esse print irá gerar duas saídas
}
/*
SAIDA:

"antes: -9999"  // aqui temos o valor que foi atribuido ao ID
"depois: 5660"  // aqui é impresso o valor do processo pai, ele pode ser qualquer valor diferente de 0
"depois: 0" //aqui é o valor do processo filho, seu valor sempre sera igual a zero
*/
