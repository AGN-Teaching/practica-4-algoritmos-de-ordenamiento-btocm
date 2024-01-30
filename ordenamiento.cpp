#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <cmath>

#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"

using namespace std;
using namespace std::chrono;

duration<double> crear_arreglo(int *A, int TAM_ARREGLO, int RANGO_MAX) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < TAM_ARREGLO; i++)
    {
        int x = rand() % RANGO_MAX;
        A[i] = x;
    }
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_insertion_sort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    insertion_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_selection_sort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    selection_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_bubblesort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    bubblesort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_merge_sort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    merge_sort(A, 0, TAM_ARREGLO - 1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_quicksort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    quicksort(A, 0, TAM_ARREGLO - 1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

int *copiar_arreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}

// Función para imprimir una fila de resultados de tiempo en la tabla.
void imprimirTabla(int repeticion, double t_is, double t_ss, double t_bs, double t_ms, double t_qs) {
    // Si es la primera repetición, imprime los encabezados de la tabla.
    if (repeticion == 1) {
        std::cout << std::setw(6) << "#ejec" << std::setw(12) << "is_t" << std::setw(12) << "ss_t" << std::setw(12) << "bs_t" << std::setw(12) << "ms_t" << std::setw(12) << "qs_t" << std::endl;
    }

    // Función para imprimir en notación científica si el número es muy pequño.
    auto imprimirTiempo = [](double tiempo) {
        if (tiempo < 0.00009) {
            std::cout << std::setw(12) << std::scientific << std::setprecision(5) << tiempo;
        } else {
            std::cout << std::setw(12) << std::fixed << std::setprecision(5) << tiempo;
        }
    };

    // Imprime los resultados de la repetición actual.
    std::cout << std::setw(6) << repeticion << "\t";
    imprimirTiempo(t_is);
    imprimirTiempo(t_ss);
    imprimirTiempo(t_bs);
    imprimirTiempo(t_ms);
    imprimirTiempo(t_qs);
    std::cout << std::endl;
}

// Función para calcular el promedio de los tiempos.
double calcularPromedio(double tiempos[], int numRepeticiones) {
    double suma = 0.0;  // Inicializar la suma de tiempos.

    for (int i = 0; i < numRepeticiones; ++i) { // Calcular la suma de todos los tiempos en el arreglo.
        suma += tiempos[i];
    }
    return suma / numRepeticiones;  // Calcular el promedio dividiendo la suma total por el número de repeticione.
}

// Función para calcular la desviación estándar. 
double calcularDesviacionEstandar(double tiempos[], int numRepeticiones) {
    double sumatoria = 0.0;  // Inicializar variables para la sumatoria, el promedio.
    double t_promedio = 0.0;

    // Calcular la sumatoria de todos los tiempos en el arreglo.
    for (int i = 0; i < numRepeticiones; ++i) {
        sumatoria += tiempos[i];
    }

    // Calcular el promedio dividiendo la sumatoria total por el número de repeticiones.
    t_promedio = sumatoria / numRepeticiones;   

    // Inicializar la sumatoria de diferencias cuadráticas.
    double sumatoriaDifCuadratica = 0.0;    

    // Calcular la sumatoria de las diferencias cuadráticas entre cada tiempo y el promedio.
    for (int i = 0; i < numRepeticiones; ++i) {
        double dif = tiempos[i] - t_promedio;
        sumatoriaDifCuadratica += dif * dif;
    }

    // Calcular la varianza dividiendo la sumatoria de diferencias cuadráticas por el número de repeticiones.
    double varianza = sumatoriaDifCuadratica / numRepeticiones; 
    double desviacionEstandar = sqrt(varianza); // Calcular la desviación estándar tomando la raíz cuadrada de la varianza.

    return desviacionEstandar;  // Devolver la desviación estándar calculada.
}

// Función para realizar experimentos y comparar tiempos de ejecución de algoritmos de ordenamiento.
void experimentos(int tam) {
    // Definir el tamaño del arreglo, el rango máximo y el número de repeticiones.
    int TAM_ARREGLO = tam;
    int RANGO_MAX = 10 * TAM_ARREGLO;
    int REPETICIONES = 30;

    // Inicializar variables para los tiempos promedio de cada algoritmo.
    double t_prom_is = 0.0;
    double t_prom_ss = 0.0;
    double t_prom_bs = 0.0;
    double t_prom_ms = 0.0;
    double t_prom_qs = 0.0;

    // Inicializar arreglos para almacenar los tiempos de ejecución en cada repetición.
    double tiempos_is[REPETICIONES];
    double tiempos_ss[REPETICIONES];
    double tiempos_bs[REPETICIONES];
    double tiempos_ms[REPETICIONES];
    double tiempos_qs[REPETICIONES];

    // Inicializar la semilla del generador de números aleatorios con el tiempo actual.
    srand((unsigned) time(0));

    // Bucle para realizar REPETICIONES experimentos.
    for (int i = 0; i < REPETICIONES; i++) {

        // Inicializar variables para los tiempos de ejecución de cada algoritmo en la repetición actual.
        double t_is = 0.0;
        double t_ss = 0.0;
        double t_bs = 0.0;
        double t_ms = 0.0;
        double t_qs = 0.0;

        // Crear un nuevo arreglo aleatorio.
        int *A = new int[TAM_ARREGLO];
        duration<double> tiempo;

        // Llenar el arreglo con valores aleatorios.
        crear_arreglo(A, TAM_ARREGLO, RANGO_MAX);

        // Copiar el arreglo para cada algoritmo de ordenamiento.
        int *aux;
        aux = copiar_arreglo(A, TAM_ARREGLO);
        tiempo = ordenar_insertion_sort(aux, TAM_ARREGLO);
        t_is = tiempo.count();
        tiempos_is[i] = t_is;
        delete[] aux;

        aux = copiar_arreglo(A, TAM_ARREGLO);
        tiempo = ordenar_selection_sort(A, TAM_ARREGLO);
        t_ss = tiempo.count();
        tiempos_ss[i] = t_ss;
        delete[] aux;

        aux = copiar_arreglo(A, TAM_ARREGLO);
        tiempo = ordenar_bubblesort(aux, TAM_ARREGLO);
        t_bs = tiempo.count();
        tiempos_bs[i] = t_bs;
        delete[] aux;

        aux = copiar_arreglo(A, TAM_ARREGLO);
        tiempo = ordenar_merge_sort(A, TAM_ARREGLO);
        t_ms = tiempo.count();
        tiempos_ms[i] = t_ms;
        delete[] aux;

        aux = copiar_arreglo(A, TAM_ARREGLO);
        tiempo = ordenar_quicksort(A, TAM_ARREGLO);
        t_qs = tiempo.count();
        tiempos_qs[i] = t_qs;
        delete[] aux;

        // Imprimir los resultados de la repetición actual.
        imprimirTabla(i+1, t_is, t_ss, t_bs, t_ms, t_qs);

        // Liberar la memoria del arreglo.
        delete [] A;
    }
    
     // Cálculo de tiempo promedio.
    t_prom_is = calcularPromedio(tiempos_is, REPETICIONES);
    t_prom_ss = calcularPromedio(tiempos_ss, REPETICIONES);
    t_prom_bs = calcularPromedio(tiempos_bs, REPETICIONES);
    t_prom_ms = calcularPromedio(tiempos_ms, REPETICIONES);
    t_prom_qs = calcularPromedio(tiempos_qs, REPETICIONES);

    // Cálculo de desviación estándar.
    double desviacion_is = calcularDesviacionEstandar(tiempos_is, REPETICIONES);
    double desviacion_ss = calcularDesviacionEstandar(tiempos_ss, REPETICIONES);
    double desviacion_bs = calcularDesviacionEstandar(tiempos_bs, REPETICIONES);
    double desviacion_ms = calcularDesviacionEstandar(tiempos_ms, REPETICIONES);
    double desviacion_qs = calcularDesviacionEstandar(tiempos_qs, REPETICIONES);

    // Desplegar resultados.
    cout << "\n*** Tiempo Promedio ***" << endl;
    cout << "Insertion sort: " << t_prom_is << endl;
    cout << "Selection sort: " << t_prom_ss << endl;
    cout << "Bubblesort: " << t_prom_bs << endl;
    cout << "Merge sort: " << t_prom_ms << endl;
    cout << "Quicksort: " << t_prom_qs << endl;

    cout << "\n*** Desviación Estándar ***" << endl;
    cout << "Insertion sort: " << calcularDesviacionEstandar(tiempos_is, REPETICIONES) << endl;
    cout << "Selection sort: " << calcularDesviacionEstandar(tiempos_ss, REPETICIONES) << endl;
    cout << "Bubblesort: " << calcularDesviacionEstandar(tiempos_bs, REPETICIONES) << endl;
    cout << "Merge sort: " << calcularDesviacionEstandar(tiempos_ms, REPETICIONES) << endl;
    cout << "Quick sort: " << calcularDesviacionEstandar(tiempos_qs, REPETICIONES) << endl;
}

// Función principal que ejecuta el programa.
int main(int argc, char *argv[]) {
    // Verificar si se proporciona el tamaño del arreglo como argumento de línea de comandos.
    if (argc != 2) {
        cout << "Sintaxis: tamaño_arreglo > archivo_salida" << endl;
    } else {
        // Imprimir el tamaño del arreglo.
        cout << "Tamaño del arreglo: " << argv[1] << endl;

        // Llamar a la función 'experimentos' para realizar experimentos con el tamaño del arreglo.
        experimentos(atoi(argv[1]));
    }

    // Devolver un código de salida EXIT_SUCCESS indicando que el programa se ejecutó correctamente.
    return EXIT_SUCCESS;
}
