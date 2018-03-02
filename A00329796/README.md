## Workshop-2

**Nombre:** Joan Sebastián García Delgado  
**Código:** A00329796

## Descripción
Crear un programa que involucre tres llamadas al sistema y explicar estas.

## Solución

Se ha creado un programa que crea un fichero con permisos de escritura y escritura (666), después obtendremos la hora del
sistema y la escribriremos en el fichero anteriormente creado. A su vez, abriremos el archivo, nos posicionaremos en la última posición
y escribiremos "Hola mundo", cerramos el archivo, y por último, lo volvemos a abrir para leer lo que habíamos escrito.

Las llamadas al sistema que se involucran en este programa son:

**creat(nombre_fichero,permisos):** Crea un nuevo fichero

• Sintaxis:  
#include <fcntl.h>  
int creat (nombre, mode_t permisos);  
const char *nombre; // Nombre a asignar al fichero, ejemplo: "Friki.txt"  
mode_t permisos; // Permisos con el cual se va a crear el fichero, ejemplo: 666 o 777 o 544
• Si existe el fichero :  
– No modifica los permisos.  
– Si tiene permiso de escritura borra el contenido.  
– Sino tiene permisos de escritura da un error.  
• Sino existe:  
– Lo crea y añade permisos de escritura.  
• Devuelve un entero:  
– Si no hay error: entre 0 y 19 (el descriptor del fichero). Devolverá el más bajo que este libre (no asociado).  
– Si hay error: un número negativo  


**gettimeofday():** Obtiene la fecha actual del sistema

• Sintaxis:  
#include <sys/time.h>  
int gettimeofday(struct timeval *tv, struct timezone *tz); // El primer parametro hace referencia a una estructura en la cual se representará el tiempo y el segundo en como se representará la zona  
• Devuelve un entero:  
– Si no hay error: 0  
– Si hay error: un número negativo (-1)  

**write(nombre_fichero,dato,n_dato):** Permite escribir en un fichero

• Sintaxis: #include <unistd.h>  
size_t write(desc_fich,dato,n_bytes); //El primer parametro hace referencia al nombre del fichero en el que se va a escribir, el segundo a lo que se va a escribir y el tercero al tamaño de caracteres del dato  
int desc_fich;  
const void *dato;  
size_t n_bytes;  
• Devuelve:  
– El número de caracteres que ha podido escribir (n_escritos).  
– Un valor negativo si ha ocurrido un error en la llamada.  

**open(nombre_fichero,modo, permisos):** Permite abrir un fichero  

• Sintaxis: #include <fcntl.h>  
int open(nombre, modo, permisos);  
const char *nombre;  
int modo, permisos; • Devuelve:  
• -1 si se produce un error  
• El número de descriptor asociado al fichero abierto (el más bajo libre en la tabla de descriptores).  
• Modos:  
O_RDONLY (0) El fichero se abre para lectura. El puntero en byte 0.  
O_WRONLY (1) El fichero se abre para escritura. Puntero en byte 0.  
O_RDWR (2) El fichero se abre en modo lectura/escritura  
O_CREAT Sino existe el fichero se crea.  
O_TRUNC Si existe se borra la información que contiene.  
O_EXCL Con O_CREAT la llamada falla si el fichero existe.  
O_APPEND El puntero del fichero apunta al final del mismo.  

**read(nombre_fichero,dato, bytes):** Permite leer las lineas de un archivo  

• Sintaxis: #include <unistd.h>  
size_t read(fd, dato, bytes);  
int fd;  
const void *dato;  
size_t bytes;  
• Hay que abrir previamente el fichero.  
• El puntero del fichero quedará indicando el siguiente byte a  
leer. Tras una operación se avanza el puntero.  
• Devuelve:  
• El número de carácter leído (puede ser menor que bytes si se ha alcanzado el final del fichero).  
• -1 si ha ocurrido un error en la llamada.  

**lseek(nombre_fichero,offset,whence):** Permite mover el puntero de lectura o escritura del archivo  

Sintaxis: #include <unistd.h>  
off_t lseek ( FileDescriptor, Offset, Whence)  
int FileDescriptor, Whence;  
off_t Offset;  
• Posiciona el puntero de un fichero abierto cuyo descriptor sea FileDescriptor.  
• FileDescriptor especifica el descriptor de un fichero abierto con la llamada open.  
• Offset especifica el valor en bytes que se desplazará el puntero. Un valor negativo mueve en dirección inversa. El valor de offset está limitado por OFF_MAX.  
• Whence especifica cómo interpretar Offset para mover el puntero del fichero especificado por FileDescriptor. Será uno de los siguientes valores que están definidos en el fichero /usr/include/unistd.h:  
• SEEK_SET (ó 0) Mueve el puntero a la posición indicada por Offset.  
• SEEK_CUR (ó 1) El Offset se usa como desplazamiento relativo desde la posición actual del puntero. La posición final del puntero será (actual + Offset).  
• SEEK_END (ó 2) El Offset se usa como desplazamiento relativo desde el final del fichero. La posición final del puntero será (final de fichero + Offset).  
• Devuelve:  
• Devuelve la localización final del puntero en bytes medida desde el inicio del fichero.  
• Devuelve -1 en caso de error. .  
• Errores: 
• Si FileDescriptor no corresponde a un fichero abierto.  
• Si FileDescriptor corresponde a una tubería abierta.  
• Si el offset sobrepasa el límite permitido definido en OFF_MAX  

------------------------------------------------------------------------

El archivo del programa se llama syscall1.c y se encuentra en esta carpeta  
El fichero el cual el programa crea, abre, lee y escribe se llama tiempo.txt y está en esta carpeta

------------------------------------------------------------------------

# Referencias
http://www3.uji.es/~redondo/so/Capitulo1_IS11_llamadas.pdf
http://wiki.inf.utfsm.cl/index.php?title=Llamadas_al_Sistema_en_Linux
http://www.tutorialspoint.com/unix_system_calls/settimeofday.htm
