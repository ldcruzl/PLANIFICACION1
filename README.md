
# Práctica: Planificación de Procesos (I) - Sistemas Operativos

## Información del curso

- **Curso:** Sistemas Operativos
- **Docente:** Ing. Hugo Manuel Barraza Vizcarra
- **Jefe de práctica:** Ing. Jimmy Muñoz Miranda
- **Tema:** Planificación a corto plazo - FCFS (Primero en llegar, primero en servirse)

## Objetivos

- Comprender el funcionamiento de la planificación a corto plazo en un sistema uniprocesador.
- Implementar en C++ el algoritmo de planificación FCFS.
- Calcular los tiempos de comienzo, finalización, espera, estancia y estancia normalizado de los procesos.
- Representar gráficamente la secuencia de ejecución mediante diagramas de Gantt.
- Analizar el comportamiento de FCFS ante diferentes tiempos de llegada y de servicio.

## Contenido

- `fcfs.cpp`: simulador del algoritmo FCFS con tabla de resultados y promedios.
- Informe breve con la resolución manual, capturas, diagrama de Gantt del escenario 2 y análisis de resultados.

## Compilación y ejecución

    g++ -std=c++17 -Wall -Wextra fcfs.cpp -o fcfs
    ./fcfs

## Entorno de desarrollo

- Sistema operativo: Ubuntu (máquina virtual)
- Lenguaje: C++17
- Compilador: g++
- Editor: nano / VS Code

## Autor

Luis David Cruz Llica