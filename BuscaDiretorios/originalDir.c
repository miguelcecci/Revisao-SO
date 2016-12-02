#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>


static void lookup(const char *arg)
{
    DIR *dirpont;
    struct dirent *dp;


    if ((dirpont = opendir("/")) == NULL) {
        perror("nao pode abrir '.'");
        return;
    }


    do {
        errno = 0;
        if ((dp = readdir(dirpont)) != NULL) {
            (void) printf("vai vendo: %s(%d)\n", dp->d_name, dp->d_type);
            printf("vai vendo: %s \n",dirpont);
            if (strcmp(dp->d_name, arg) != 0)
                continue;


            (void) printf("achou: %s(%d)\n", dp->d_name, dp->d_type);
            (void) closedir(dirpont);
                return;

        }
    } while (dp != NULL);


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
