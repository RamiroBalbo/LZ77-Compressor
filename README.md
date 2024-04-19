# algoritmo LZ77
#### Cualquier recomendación se agradece, ya sea de texto teórico, como consejos para implementar en el código.
## V 1.0 28/3/2024
  Me he encontrado con la duda de saber como funcionan los compresores y descompresores de archivos, asi que me puse a investigar. Encontré diferentes algoritmos pero el que mas me llamo la atención en un principio fue el LZ77. El codigo cuenta con las bases del algoritmo, es decir mas o menos tiene los mismos elementos y la idea está. Una de las principales diferencias es que, lee el archivo de entrada (arch_in) de adelante para tras; mientras que el original recorre de atras para adelante. EL codigo está 100% hecho por mi ,es decir, no busque en ningunn lado, ni tampoco encontre mucho, de como es el código original, yo creo que no se asemeja ni un poco al final y todavía tiene fallas y está incompleto.
  
### ¿Qué hace en concreto el programa y como funciona?

  Primero voy a hablar de como testearlos, es tan simple como ir desde una terminal a la dirección donde guardaste el archivo y escribir './main', obvio tenes que tener el compilador y C/C++ descargado en tu PC, si querés cambiar el texto y tamaño d elos buffer; lo siento hermano pero es manopla, abris el main.cpp y el archivo de entrada y modificás esas dos cosas.
  El programa se divide en dos partes compresion y descompresión, la primera parte toma un archivo de entrada (archi_in), el cual lee y comprime en un archivo de salida (archi_out) al mismo tiempo y **sin pérdida** de información, después en la segunda parte el algoritmo se encarga de descomprimir los datos del archivo de salida, y mostrarlos en consola. Si lo que te mostró la salida del programa en la temrinal, es lo mismo que el texto que ingresaste, entonces YUPii!! funciona el código.
  El programa cuenta con un montón de variables las vuales simplemente se encargan de iterar y recolectar informacíon estas variables son 'int i, j, d;', también tiene variables auxiliares como 'Nodo<char> *aux = window;', la cual recorre la ventana sin alterarla. 
  Ahora las importantes vendrían a ser:
- **Window**: Esta es una lista enlazada la cual va recorriendo el archivo para que se comparen los datos del Search Buffer(sb) con el Lock-ahead Buffer(lb). Para desplazar esta lista utilizo un for el cual se desplaza cierta cantidad de veces segun el length.
- **sb**: Es el search buufer el cual contiene los caracteres procesados.
- **lb**: Es el Lock-ahead Buffer que contiene los caracteres a procesar.
- **length**: Es la máxima longitud de coincidencia entre el Lock-ahead Buffer y el Search Buffer.
- **offset**: Con respecto al inicio del Search Buffer, es el primer caracter de coincidencia que tiene el Search Buffer(sb) con el Lock-ahead Buffer(lb).
- **ltr_fin**: Almacena la última letra después de lo comprimido.
- **cp**: Es el Coding Position, es decir, es donde se encuentra el primer caracter sin procesar.
- **indice**: Tiene la misma funcionalidad que el cp, se podría eliminar.

### Fallas
  Primero y principal solo comprime archivos de texto los cuales no tengan ni espacios, ni caracteres especiales, eh testeado muchas veces el programa, en un principio debería andar bien pero no se sorprendan si a la hora de descomprimir no les devuelve lo mismo. La eficiencia varía según cuanta redundancia tenga el texto, y dependiendo el tamaño de los buffer, en el archivo de entrada e puesto una cantidad de "hola" muy grande pera poder demostrar que el código en un principio cumple, si te fijas el archivo de salida, que vendría a ser el comprimido, pesa 10 bytes menos que el de entrada; por lo que el código funciona si encontras los tamaños y el texto correcto, ahora hay que mejorar en un monton de aspectos el rendimiento, la capacidad del programa para interpretar distintos caracteres y archivos. En está version disculpen si no es muy entendible el código ya se, es lo primero que quiero arreglar. Después de descomprimir me olvido de eliminar los espacios de memoria ocupado innecesariamente también.
  Bueno el proyecto digamos que es largo, porque en un futuro planeo implementar otros algoritmos y hacer esto me llevo aproximadamente una semana, y le faltan muchas actualizaciones; pero bueno entusiasmado y contento de buscar algo que me entretenga y poder aprender mas de este hermoso lenguaje que es C/C++. Este programa que estoy realizando es solo a modo de aprendizaje y gusto, simplemente en un principio sirve para testear y descubrir un algoritmo semejante al LZ77. 


**Biliografía principal:** 
https://blog.coderspirit.xyz/blog/2023/06/04/exploring-the-lz77-algorithm/
