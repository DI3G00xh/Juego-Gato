Nombre: Diego Adaos
Paralelo: c1
Rut: 21.535.504-7
Correo: diego.adaos01@alumnos.ucn.cl

comando de compilación: g++ gato.cpp -o gato.exe
comando de ejecución: gato.exe


Explicacion del alogritmo:

El algoritmo comienza pidiendo al usuario dos valores numericos para posicionar su jugada en el tablero,el tablero se llena de 0 al iniciar,
cuando el usuario ingresa una posicion se carga con un 1 y cuando la IA lo hace se carga con un 0, en cada ciclo se va verificando si ha 
ocurrido una victoria mediante la funcion verificarWin. En el turno de la IA se hace uso de la funcion mejorMovimiento para hacer su jugada, 
esta evalua los movimientos futuros mediante la ayuda de la funcion miniMax. Para terminar el bucle se pide al usuario ingresar valores que 
detienen el juego.

Explicacion funcion MinMax:

El algoritmo Minimax se utiliza para que la IA haga evaluciones donde cada jugador intenta maximizar su puntaje o minimizar el del oponente.

-Generar todos los movimientos posibles.
-Evaluar cada movimiento utilizando una función de evaluación (estados finales).
-Elegir el movimiento que maximiza el puntaje si es el turno del jugador Max, o el que minimiza el puntaje si es el turno del jugador Min.
-La poda alfa-beta optimiza el Minimax añadiendo dos parámetros:
    Alfa: el mejor valor encontrado hasta ahora para el jugador Max.
    Beta: el mejor valor encontrado hasta ahora para el jugador Min.
    *Si en algún punto beta ≤ alfa, se detiene la evaluación de esa rama porque no puede afectar la decisión final


Analisis de complejidad:

La complejidad de minMax es O(b^d)

    b : El número de movimientos posibles por turno 
    d : La profundidad máxima del árbol 
    Con poda alfa-beta:

La poda alfa-beta reduce el tiempo de ejecución promedio a O(b^d/2) al eliminar ramas innecesarias. Esto significa que se evalúan menos 
nodos que no son necesarios.