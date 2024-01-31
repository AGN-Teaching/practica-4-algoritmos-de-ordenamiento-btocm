# Práctica 4: Algoritmos de ordenamiento
# Resultados:
![promedios_t.png](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-btocm/blob/main/promedios_t.png)
![promedios_g.png](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-btocm/blob/main/promedios_g.png)
![ds.png](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-btocm/blob/main/ds.png)
![ds_g.png](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-btocm/blob/main/ds_g.png)

# Analisis:
<p>Haciendo una comparación entre algoritmos, en general, los algoritmos de ordenación más eficientes son Merge sort y Quicksort, ya que tienden a tener tiempos de ejecución más bajos en comparación con los otros algoritmos, especialmente a medida que aumenta el tamaño del arreglo.</p>
<p>Insertion sort, Selection sort y Bubblesort son algoritmos más simples y muestran un rendimiento más lento, especialmente cuando se enfrentan a arreglos más grandes.</p>

<p>Para tamaños pequeños de arreglos como n = 5, 10, 50, 100, los cinco algoritmos tienden a ejecutarse rápidamente, dando resultados con notación científica debido a que son cantidades pequeñas.</p>
<p>A medida que el tamaño del arreglo aumenta, las diferencias entre los algoritmos se vuelven más evidentes. Merge sort y Quicksort mantienen tiempos de ejecución bajos en comparación con los otros algoritmos. Insertion sort, Selection sort y Bubblesort experimentan un aumento en el tiempo de ejecución a medida que n crece, lo que demuestra su ineficiencia para arreglos grandes.</p>

<p>Al ver los resultamos podemos notar algunos casos particulares:</p>
<p>>1. Para arreglos pequeños, la elección del algoritmo puede no ser crítica, ya que los tiempos de ejecución son relativamente bajos y similares entre los algoritmos.</p>
<p>1. Cuando n = 500 y n = 1,000 notamos que Merge sort en la desviación estándar se encuentra en 0, debido a que en la ejecución de las 30 repeticiones los valores no son tan diferentes, por lo que tienen una desviación estándar casi nula.</p>
<p>1. Cuando n = 500,000 notamos que los algoritmos Insertion sort, Selection sort y Bubblesort dan resultados grandes en el promedio del tiempo y su desviación estándar también comienza a aumentar. Debido a su aumento esto hace retrasar la ejecución de los otros algoritmos, por lo que en las pruebas se descartá seguir usando Insertio sort, Selection sort y Bubblesort. </p>
<p>1. Cuando n = 1,000,000 notamos que el algoritmo Quicksort comienza a tener aumento en el tiempo como en la desviación estándar. Nuevamente se optó por descartar este algoritmo para no retrasar </p>


# Conclusión:
Los resultados resaltan la importancia de elegir el algoritmo de ordenamiento adecuado según el tamaño del arreglo y la eficiencia requerida. Los algoritmos más avanzados como Merge sort y Quicksort son preferibles para arreglos grandes, mientras que los otros algoritmos pueden ser suficientes para tamaños pequeños.
