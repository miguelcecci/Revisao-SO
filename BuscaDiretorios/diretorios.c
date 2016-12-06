#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
char* path[]={NULL, NULL, NULL, NULL};

static void lookup(const char *arg)
{
    DIR *dirpont;
    struct dirent *dp;
    char *buffer;
    int counter = 0;
    int aux;
    char aux2[1024];

    memset(aux2, 0, 1024);

    if ((dirpont = opendir("/")) == NULL) {
        perror("nao pode abrir '/'");
        return;
    }

    do {
        errno = 0;
        if ((dp = readdir(dirpont)) != NULL){
            if (strcmp(dp->d_name, arg) != 0){
              if(dp->d_type == 4 && strcmp(dp->d_name, "..") != 0){
                path[counter]="/";
                path[counter+1]=dp->d_name;
                counter=counter+2;
                for(int j=0; j<counter; j++){
                  strcat (aux2, path[j]);
                }

                aux = chdir(aux2);//esse programa ta uma porra

                if(aux == -1){
                  printf("ERRO AO TENTAR ABRIR DIRETORIO\n");
                  printf("olha esta bosta -> %s\n", aux2);
                }

              }
              if(dp == NULL){
                path[counter]=NULL;
                path[counter+1]=NULL;
                counter=counter-2;
                aux = chdir("..");
              }
              (void) printf("vaivendo: %s(%d)\n", dp->d_name, dp->d_type);
              continue;
            }

            (void) printf("achou: %s(%d)\n", dp->d_name, dp->d_type);
            (void) closedir(dirpont);
                return;
        }
    } while (dp != NULL && counter != 0 );


    if (errno != 0)
        perror("Erro lendo o diretorio");
    else
        (void) printf("Falha ao procurar: %s\n", arg);
    (void) closedir(dirpont);
    return;
}


int main(int argc, char *argv[])
{
    int i;

    if( argc < 2 ) {
       printf( "USO: %s nome_arquivo ...\n\n", argv[ 0 ] );
       return( -1 );
    }

    for (i = 1; i < argc; i++)
        lookup(argv[i]);
    return (0);
}
