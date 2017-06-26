# Programación II
## Proyecto #2: Juego de ahorcado con interfaz gráfica
Versión 1.0  27/06/2017     
        	
### Interfaz gráfica
La interfaz gráfica o GUI es un conjunto de
métodos o formas que hacen posible que el usuario interactúe con el sistema
utilizando gráficos e imágenes. Los gráficos pueden ser botones, ventanas,
entre otros, que representan las funciones del sistema. Las interfaces gráficas
pretenden crear un entorno visual sencillo que permita establecer la
comunicación con el computador o la máquina. Se pretende elaborar un juego
utilizando interfaz gráfica, el cual consiste básicamente en un [ahorcado tradicional.][blog] El juego se llama Ahorcado Tico.

[blog]:https://es.wikipedia.org/wiki/Ahorcado_(juego)
 
### ¿Cómo jugar Ahorcado Tico?
El objetivo de este juego es descubrir una
palabra adivinando las letras que la componen. A cada ronda, los jugadores
escogen simultáneamente una letra que crean que pueda formar parte de la
palabra. Si la palabra contiene la letra escogida, se mostrará en qué posición
(ones) está. En el caso de que la letra no exista en la palabra, se dibujara
una parte del cuerpo del muñeco del jugador. Cuando estén dibujadas las 8
partes del cuerpo del muñeco, el jugador se quedará fuera de la partida.
Existen muchas versiones de este juego, sin embargo nuestro objetivo es hacer
un juego utilizando [QT][web], que permite a un usuario jugar una partida con la
computadora, siendo la computadora la generadora de palabras, por cada palabra
el jugador tendrá 8 intentos para adivinar la palabra, si lo logra el jugador
acumulara 10 pts, por el contrario, se le mostrará la palabra correcta y este
no acumulara puntos. Además cada partida consta de 5 palabras, el juego termina
hasta que el jugador presione, el botón de rendirse o hasta que terminen las 5
palabras.

[web]: https://www.qt.io/es/
 
### Plus del juego
Se pretende agregar un “plus” a este juego,
haciendo que este sea multijugador en red, lo que implica que se pueden tener
un número de computadoras conectadas que puedan comunicarse entre sí, en este
caso se permitirán dos jugadores. Ahora se debe tomar en cuenta el  límite
de intentos para el usuario y la velocidad del oponentes, de manera que si el
otro usuario adivina primero la palabra, este gana y automáticamente el otro
pierde, en caso de que alguno de los jugadores agote su número de intentos, el
otro tendrá la oportunidad de seguir jugando hasta que se agoten los suyos o
hasta que adivine la palabra. Para que la partida sea justa, el juego que se
pretende crear lanzará la misma palabra a ambos jugadores y se podrá controlar
ambas partidas de manera que alguno gana o pierde el otro jugador podrá darse
cuenta de eso.
 
### Tropicalización del juego
El programa que controla el juego recibirá una
lista de palabras predeterminada, esta lista contiene palabras que son
costarriqueñismos, esto con el fin de crear un juego tropicalizado, las cuales
consisten en palabras o frases que han inventadas por los antepasados, generalmente
campesinos y que han sido heredades y acuñadas por la población. Algunos
ejemplos de estas palabras, con su respectivo significado son:
- **Jetón:** (adjetivo) Se refiera a alguien muy mentiroso. Ej: “Ese mae es un jetón”
- **Mae:** (sustantivo) Referente a una persona, por ejemplo “Ese mae” significa ese chico. Sin embargo es una muletilla que los ticos usan para todo y en cualquier parte de la oración ej: “Mae, qué aburrido”
- **Menudo:** (sustantivo) Una pequeña cantidad de dinero, que se adquiere como cambio en una compra mayor. Suele ser un conjunto de monedas. Ej: “Hoy tengo menudo para comprar café”
- **Pichel:** (sustantivo) Un recipiente de vidrio o plástico para guardar y servir bebidas frías y “fresco”

El juego lanzará al azar alguna de las palabras en la lista, el jugador tendrá la oportunidad de adivinar y una vez que adivine o que pierda se mostrará la solución con el respectivo significado de la palabra con el fin de que se conozca más este vocabulario.


### Descripción preliminar de la interfaz.
 
- **Inicio:** La pantalla inicial mostrará el nombre del juego (Ahorcado Tico), las opciones de juego (Multijugador o un solo jugador), un botón de salida y ayuda (explica cómo jugar el juego).  

![Inicio](http://i.imgur.com/0iHz2tS.png "Pantalla preliminar inicio")

- **Información:** Aparece una pantalla en la que se solicita el nombre del jugador y también continúan apareciendo la opción de regresar y ayuda.

![Informacion](http://i.imgur.com/mHHGJtl.png "Pantalla preliminar informacion")

- **Pantalla de juego:** Es donde se desarrollará el juego, en está aparece el dibujo respectivo de donde se armara el muñeco de ahorcado, el nombre del jugador o los nombres de ambos si es un multijugador, el puntaje, las líneas que indican el número de letras de la palabra a adivinar y un teclado. Cuando inicia el juego aparecerá una ventaja que marca el inicio, una vez que se comienza a jugar cada vez que el usuario elija una letra, esta se revisará y en caso de que sea correcta se elimina la línea y la coloca la letra en caso contrario una ventana indicará el error, en ambos casos la letra desaparece de las opciones del teclado. El puntaje aumentara según los aciertos y el muñeco se irá armando según los desaciertos, cuando solo quede un intento aparecerá una ventana que indique esto al usuario. Al final se mostrará la solución, el significado de la palabra, el puntaje obtenido y el estado (ganó o perdió). ![juego]

![Juego](http://i.imgur.com/wyhWg8C.png "Pantalla preliminar jugando")



