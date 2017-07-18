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



### Plus del juego
Se pretende agregar un “plus” a este juego, que le permite al usuario acceder 
a una pista o a la definicion de la palabra a encontrar, sin embargo, esto resta
dos vidas a su juego, la intencion de este plus es que los jugadores aprendan 
sobre los principales costarriqueñismos jugando.



### Descripción preliminar de la interfaz.
 
- **Inicio:** La pantalla inicial mostrará el nombre del juego (Ahorcado Tico), las opciones de juego (Multijugador o un solo jugador), un botón de salida y ayuda (explica cómo jugar el juego).  

![Inicio](http://i.imgur.com/vIBnuB6.jpg "Pantalla principal juego")


- **Pantalla de juego:** Es donde se desarrollará el juego, en está aparece el dibujo respectivo de donde se armara el muñeco de ahorcado, el nombre del jugador o los nombres de ambos si es un multijugador, el puntaje, las líneas que indican el número de letras de la palabra a adivinar y un teclado. Cuando inicia el juego aparecerá una ventaja que marca el inicio, una vez que se comienza a jugar cada vez que el usuario elija una letra, esta se revisará y en caso de que sea correcta se elimina la línea y la coloca la letra en caso contrario una ventana indicará el error, en ambos casos la letra desaparece de las opciones del teclado. El puntaje aumentara según los aciertos y el muñeco se irá armando según los desaciertos, cuando solo quede un intento aparecerá una ventana que indique esto al usuario. Al final se mostrará la solución, el significado de la palabra, el puntaje obtenido y el estado (ganó o perdió).


![Imgur](http://i.imgur.com/jr6SezK.jpg "Pantalla preliminar jugando")

- **FIn del juego:** Se mostrará una pantalla, con la cantidad de puntos de cada jugador, y con dos botones, uno para salir y el otro para jugar de nuevo.

**Cuando gana el jugador se muestra lo siguiente:**

![gana](http://i.imgur.com/bFaF9Mv.jpg "Pantalla preliminar de gane")

**Cuando pierde el jugador se muestra lo siguiente:**

![pierde](http://i.imgur.com/5lkyXEW.jpg "Pantalla preliminar cuando pierde")

### [Inkscape][sitio]
Se utilizara este editor de gráficos vectoriales, permite crear y editar las imagenes, diagramas u otros necesarios para el diseño de la interfaz. El diseño de estos por medio de gráficos vectoriales hace posible ampliar el tamaño de una imagen sin sufrir la pérdida de calidad como sucede en las imagenes convecionales, además permite manipular las imagenes, mover, encojer, estirar de forma sencilla lo que facilita el diseño de las ventanas para el juego que se pretende diseñar. 

[sitio]: https://inkscape.org/es/


