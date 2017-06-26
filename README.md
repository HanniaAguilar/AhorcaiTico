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
utilizando interfaz gráfica, el cual consiste básicamente en un ahorcado
tradicional. El juego se llama Ahorcado Tico.
 
### ¿Cómo jugar Ahorcado Tico?
El objetivo de este juego es descubrir una
palabra adivinando las letras que la componen. A cada ronda, los jugadores
escogen simultáneamente una letra que crean que pueda formar parte de la
palabra. Si la palabra contiene la letra escogida, se mostrará en qué posición
(ones) está. En el caso de que la letra no exista en la palabra, se dibujara
una parte del cuerpo del muñeco del jugador. Cuando estén dibujadas las 8
partes del cuerpo del muñeco, el jugador se quedará fuera de la partida.
Existen muchas versiones de este juego, sin embargo nuestro objetivo es hacer
un juego utilizando qt, que permite a un usuario jugar una partida con la
computadora, siendo la computadora la generadora de palabras, por cada palabra
el jugador tendrá 8 intentos para adivinar la palabra, si lo logra el jugador
acumulara 10 pts, por el contrario, se le mostrará la palabra correcta y este
no acumulara puntos. Además cada partida consta de 5 palabras, el juego termina
hasta que el jugador presione, el botón de rendirse o hasta que terminen las 5
palabras.
Para obtener más información sobre el juego tradicional de ahorcado se puede consultar en………………………..LINK………………………
 
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
 


