
### Authors:
**Guillermo Esquivel Ortiz** - A01625621

**Jesus Castillo Cabello**  - A01382000

Date: 02/02/2024
____

### Descripción
La empresa "InternetMáximo" ha empezado operaciones en la ciudad. Actualmente con poco personal y dinero inicial, así que requiere tomar decisiones inteligentes que le permitan entrar pronto en competencia con las empresas ya instaladas.

## Problema 1. Cobertura máxima
Los ingenieros de la compañía han generado un mapa que muestra cada una de las colonias y las distancias máximas existente entre los centros geográficos de las mismas. Con el fin de poder empezar a competir, la empresa planea colocar fibra óptima para conectar todas las colonias. Sin embargo, el costo de interconectar todas las colonias entre sí es elevado, por lo que la empresa necesita determinar la forma de conectar todas las colonias con el menor número cantidad de fibra óptica posible.

## Problema 2. Publicidad y contratación
La empresa cuenta con poco personal así que la tareas de publicidad y contratación es manejada por un solo grupo de personas. La idea es recorrer cada una de las colonias, una solo vez cada una de ellas, y regresar al punto de inicio. A decir verdad, se desea que sea siempre la menor ruta posible.

## Problema 3. Máximo servicio que se puede ofrecer
Como se comentó antes, la empresa cuenta con pocos recursos, por lo que los equipos instalados son muy heterogéneos. Por lo mismo, las capacidades máximas (Mbps) en los diferentes enlaces son muy varias. La empresa desea determinar cuál es la transferencia máxima que se puede obtener entre dos colonias determinadas. Para ello ya se cuenta con un registro de las velocidades de transferencia máxima entre cada una de las colonias instaladas.

## Entrada
El programa recibe dos grafos: el primero no dirigido, el segundo dirigido. El primero lo usarás en los dos primeros problema, mientras que el segundo lo usarás para el tercer problema. Ambos grafos estarán en forma de matriz ponderada de adyacencias. La primera línea de entrada contiene un entero, n (7 <= n <= 15), indicando el número de vértices del grafo y dos enteros , start y end (0 <= start, end < n), vértices que se emplearan como inicio y fin para algunos problemas (para el primero y tercero).

A continuación, unas primeras n líneas. La i-esima línea contiene n números. El j-ésimo valor es la distancia, en kilómetros, entre el centro de la colonia i con el centro de la colonia j (10 <= m[i][j] <= 1000). En caso de no existir conexión, este valor será -1.

Las siguientes n líneas contienen las capacidad máximas de conexión. La i-esima línea contiene n números. El j-ésimo valor es la capacidad máxima, en Mbps, en el enlace que existe entre colonia i con la colonia j (10 <= m[i][j] <= 1000). En caso de no existir conexión, este valor será -1.

## Salida
En primer lugar, deberá desplegar la lista de arcos seleccionados para lograr la cobertura requerida. Los arcos aparecerán en orden descendente por costo. Cada arco deberá mostrarse como un par "(a, b)" donde a < b.

A continuación, se desplegará el costo y los vértices que integran la ruta requerida en el problema 2. Si el costo de la ruta es negativa, deberá desplegar el mensaje "There is no possible route.".

Por último, se desplegará la velocidad máxima de transferencia que se puede lograr entre los vértices start y end.