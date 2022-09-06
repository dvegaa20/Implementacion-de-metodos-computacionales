![Tec de Monterrey](images/logotecmty.png)
# Act 1.2 - Search and Sort Algorithms

## <span style="color: rgb(26, 99, 169);">What I have to do?</span>
In this working repository you will find the files "search.h", "bubble.h", "selection.h", "insertion.h" and "main.cpp", which you will have to modify for the development of this activity. In the "main.cpp" file, you must place your data at the top, in comments. For example:
```
// =========================================================
// File: main.cpp
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// =========================================================
```

Implement, <span style="text-decoration: underline;">individually</span>, an application that reads *n* data, sorts it and indicates the number of comparisons to be made for each of the three basic sorting algorithms (bubble, selection, insertion), then it must read *q* values, showing the position where finds the value in the sorted array (-1 if not found) and the number of comparisons it made by both sequential and binary search.

## <span style="color: rgb(26, 99, 169);">**Input**</span>
The first line contains a positive integer *n* (300 <= *n* <= 500) indicating the number of elements to read. Next, *n* whole integers. Then there will be a line with a value, *q*, indicating the number of numbers to search and on the next line the *q* to search.

## <span style="color: rgb(26, 99, 169);">**Output**</span>
The first line will display the number of comparisons that each basic sorting algorithm performed (bubble, select, insert), separated by spaces.

Afterwards, *q* lines will be printed (one for each value to be searched) showing the position, number of comparisons of the sequential search and number of comparisons of the binary search, separated by spaces.

## <span style="color: rgb(26, 99, 169);">**Example of input**</span>
```
8
10 4 8 12 20 15 54 18
4
20 54 100 12
```

## <span style="color: rgb(26, 99, 169);">**Example of output**</span>
```
5 5 5

6 7 3
7 8 4
-1 8 4
3 4 1
```

To test your implementation, compile your program with the command:
```
g++ -std=c++11 main.cpp -o app
```
Then try each of the test input files you'll find in this repository (input1.txt, input2.txt, input3.txt, input4.txt). The results you should get are in files named solution1.txt, solution2.txt, solution3.txt, and solution4.txt. To perform the tests, you can use the following lines of code. For example, if we want to test with the test file "input1.txt".
```
./app < input1.txt > mysolution1.txt
diff mysolution1.txt solution1.txt
```
If the second command has no output, the results you got are as expected.

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **90%** - Para cada una de las funcionalidades se evaluará:

    - **Excelente (90%)** - pasa correctamente todos los casos de prueba.
    - **Muy Bien (70%)** - pasa correctamente el 75% de los casos de prueba.
    - **Bien (45%)** - pasa correctamente el 50% de los casos de prueba.
    - **Insuficiente (22%)** - pasa correctamente menos del 50% de los casos de prueba.


- **10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación: <span class="instructure_file_holder link_holder">[liga_estándar_codificación](estandar.pdf)</span>

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>
Cuando hayas pasado todas las pruebas, recuerda publicar el código en tu repositorio (*git push*).
