#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

int main(){

/* Crearemos un fichero con permisos de escritura y lectura, después almacenaremos la hora en este fichero, nos posicionaremos en la última posición y escribiremos un hola mundo */

int fichero = creat("Tiempo",0666);

struct timeval valorTiempo;
struct tm* ptm;
char cadena_tiempo[40];

gettimeofday(&valorTiempo, NULL);
ptm = localtime(&valorTiempo.tv_sec);

strftime(cadena_tiempo, sizeof(cadena_tiempo), "%d/%m/%Y %H:%M:%S", ptm);

printf("%s\n",cadena_tiempo);
write(fichero,cadena_tiempo,41);

int abierto = open(fichero,0);

int posicionDato = lseek(fichero,41,0);

write(fichero,"hola mundo", posicionDato);

close(fichero);

fichero=open(fichero,O_RDONLY);
int dato,leidos;
while((leidos=read(fichero,&dato,sizeof(int)))>0){
printf("esto hay %d\n",dato);

}
close(fichero);
exit(0);

}
