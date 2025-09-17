#include <stdio.h>

#define N 5

//estructura de los estudiantes
struct Estudiante {
    char nombre[20];
    int codigo;
    float nota;
};

// Lista predefinida de estudiantes
struct Estudiante estudiantes[N] = {
   {"Juan", 2024101, 4.5},
    {"Maria", 2024102, 3.2},
    {"Pedro", 2024103, 2.8},
    {"Ana", 2024104, 3.9},
    {"Luis", 2024105, 4.0}
};

// Función recursiva para encontrar la nota máxima
float buscarNotaMaxima(int index, float max) {
    if (index == N) {
        return max;
    }

    if (estudiantes[index].nota > max) {
        max = estudiantes[index].nota;
    }

    return buscarNotaMaxima(index + 1, max);
}

// Función recursiva para sumar las notas
float sumarNotas(int index) {
    if (index == N) {
        return 0;  // Caso base
    }

    return estudiantes[index].nota + sumarNotas(index + 1);
}

// Función recursiva de Selection Sort por código
void ordenarPorCodigo(int inicio) {
    if (inicio == N - 1) {
        return; 
    }

    int minIndex = inicio;

    // Buscar el índice del menor código
    for (int j = inicio + 1; j < N; j++) {
        if (estudiantes[j].codigo < estudiantes[minIndex].codigo) {
            minIndex = j;
        }
    }

    // Intercambiar estudiantes
    if (minIndex != inicio) {
        struct Estudiante temp = estudiantes[inicio];
        estudiantes[inicio] = estudiantes[minIndex];
        estudiantes[minIndex] = temp;
    }

    
    ordenarPorCodigo(inicio + 1);
}

// Función para mostrar la lista de estudiantes
void mostrarEstudiantes() {
    printf("\nLista de Estudiantes:\n");
    for (int i = 0; i < N; i++) {
        printf("Nombre: %s, Codigo: %d, Nota: %.2f\n", estudiantes[i].nombre, estudiantes[i].codigo, estudiantes[i].nota);
    }
}

// Función principal con menú
int main() {
    int opcion;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Buscar la Nota Maxima del Curso\n");
        printf("2. Calcular el Promedio del Curso\n");
        printf("3. Ordenar Codigos de Estudiantes\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Nota maxima: %.2f\n", buscarNotaMaxima(0, estudiantes[0].nota));
                break;

            case 2:
                printf("Promedio del curso: %.2f\n", sumarNotas(0) / N);
                break;

            case 3:
                ordenarPorCodigo(0);
                printf("Estudiantes ordenados por codigo:\n");
                mostrarEstudiantes();
                break;

            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
