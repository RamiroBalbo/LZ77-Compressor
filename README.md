# LZ77 Algorithm
###Cualquier recomendación se agradece, ya sea de texto teoŕico, como consejos para implementar en el código.
## V 1.0
  Me eh encontrado con la duda de saber como funcionar un compresor y descompresor de archivos, asi que me puse a investigar. Encontré diferentes algoritmos pero el que mas me llamo la atención en un principio fue el LZ77. El codigo cuenta con las bases de del algoritmo, es decir tiene mas o menos los mismos elementos y la idea esta. Una de las principales diferencias es que lee el archivo de entrada (arch_in), de adelante para tras; mientras que el original recorre de atras para adelante. EL codigo está 100% hecho por mi ,es decir, no busque ningunn lado ni tampoco encontre mucho, de como es el código original, yo creo que no se asemeja ni un poco al final y todavía tiene fallas y está incompleto.
  
  Primero y principal solo comprime archivos de texto los cuales no tengan ni espacios, ni caracteres especiales, eh testeado muchas veces el programa, en un principio debería andar bien pero no se sorprendan si a la hora de descomprimir no les devuelve lo mismo. La eficiencia varía según cuanta redundancia tenga el texto, y dependiendo el tamaño de los buffer, en el archivo de entrada e puesto una cantidad de "hola" muy grande pera poder demostrar que el código en un principio cumple, si te fijas el archivo de salida, que vendría a ser el comprimido, pesa 10 bytes menos que el de entrada; por lo que el código funciona si encontras los tamaños y el texto correcto, ahora hay que mejorar en un monton de aspectos el rendimiento, la capacidad del programa para interpretar distintos caracteres y archivos. En está version disculpen si no es muy entendible el código ya se, es lo primero que quiero arreglar.
  
  Bueno el proyecto digamos que es largo, porque en un futuro planeo implementar otros algoritmos y hacer esto me llevo aproximadamente una semana, y le faltan muchas actualizaciones; pero bueno entusiasmado y contento de buscar algo que me entretenga y poder aprender mas de este hermoso lenguaje que es C/C++.

Biliografía principal: 
https://blog.coderspirit.xyz/blog/2023/06/04/exploring-the-lz77-algorithm/
