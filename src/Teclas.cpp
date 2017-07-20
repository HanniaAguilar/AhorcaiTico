#include "Teclas.h"

Teclas::Teclas(Diccionario* diccionario) //Inicializar miembros
    :teclasDiccionario (diccionario)
{
}

void Teclas::agregarTeclado() //Agregar todos los ID en el svg
{
    v_teclado.append("letraQ");
    v_teclado.append("letraw");
    v_teclado.append("letraE");
    v_teclado.append("letraR");
    v_teclado.append("letraT");
    v_teclado.append("letraY");
    v_teclado.append("letraU");
    v_teclado.append("letraI");
    v_teclado.append("letraO");
    v_teclado.append("letraP");
    v_teclado.append("letraA");
    v_teclado.append("letraS");
    v_teclado.append("letraD");
    v_teclado.append("letraF");
    v_teclado.append("letraG");
    v_teclado.append("letraH");
    v_teclado.append("letraJ");
    v_teclado.append("letraK");
    v_teclado.append("letraL");
    v_teclado.append("letraEnye");
    v_teclado.append("letraZ");
    v_teclado.append("letraX");
    v_teclado.append("letraC");
    v_teclado.append("letraV");
    v_teclado.append("letraB");
    v_teclado.append("letraN");
    v_teclado.append("letraM");
}

void Teclas::cargarTeclado(QSvgRenderer *svgRenderer, QGraphicsScene *escena)
{
    ObjetoProp* temporal; // objeto temporal para cargar las teclas

    QString alfabeto= "QWERTYUIOPASDFGHJKLÑZXCVBNM";
    int ejeX=360,ejeY=295; // manejar posiciones

    // ciclo que recorre el vector con los ID de cada objeto
    // Y crea un ObjetoProp a partir de ellos.
    for(int indice=0;indice < v_teclado.size();++indice){
            // controlar las posiciones de las teclas
            if(ejeX<=800){
                ejeX+=45;
            }else{
               if(ejeX==810)
                    ejeX=405+1;
               else
                    ejeX=405+65;
                ejeY+=50;
            }

            // asignando propiedades a las teclas
            temporal= new ObjetoProp(v_teclado[indice],teclasDiccionario);
            temporal->setSharedRenderer(svgRenderer);
            temporal->setChar(alfabeto[indice]); //Asignar un char a la tecla para identificar cual presionan
            temporal->setZValue(1);
            escena->addItem(temporal);//Agregar a la escena
            temporal->setPos(ejeX,ejeY);
            temporal->setOpacity(1);
            v_objetosProp.append(temporal); //Agregar al vector            
        }
}

void Teclas::restablecerTeclado() //Colocar todo el teclado de nuevo
{
    for(int indice=0; indice<v_objetosProp.size();++indice){ //Volver a mostrar todo el teclado
        v_objetosProp[indice]->setOpacity(1);
    }
}

Teclas::~Teclas()
{

}
