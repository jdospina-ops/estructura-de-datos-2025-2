#include <stdio.h>

void llenarArray(int a[], int n);
void mostrarArray(int a[], int n);
void ordenarSelectionAscendente(int a[], int n);
void ordenarInsertionDescendente(int a[], int n);

int main() {
    int a[10];
    int n = 10;
    int opcion;
    int datosCargados = 0;

    do {
        printf("\n MENU PRINCIPAL \n");
        printf("1. Registrar tiempos\n");
        printf("2. Mostrar arreglo original\n");
        printf("3. Ordenar ascendente\n");
        printf("4. Ordenar descendente\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                llenarArray(a, n);
                datosCargados = 1;
                break;
            case 2:
                if (datosCargados)
                    mostrarArray(a, n);
                else
                    printf("Primero debe registrar los datos.\n");
                break;
            case 3:
                if (datosCargados) {
                    printf("\n Selection Sort Ascendente \n");
                    ordenarSelectionAscendente(a, n);
                } else
                    printf("Primero debe registrar los datos.\n");
                break;
            case 4:
                if (datosCargados) {
                    printf("\n Insertion Sort Descendente \n");
                    ordenarInsertionDescendente(a, n);
                } else
                    printf("Primero debe registrar los datos.\n");
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 5);

    return 0;
}


void llenarArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        do {
            printf("Ingrese el valor positivo #%d: ", i + 1);
            scanf("%d", &a[i]);
            if (a[i] <= 0)
                printf("El valor debe ser positivo.\n");
        } while (a[i] <= 0);
    }
}


void mostrarArray(int a[], int n) {
    printf("Arreglo: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}


void ordenarSelectionAscendente(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        printf("Paso %d: [ ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
        printf("]\n");
    }
    printf("Resultado final ascendente: ");
    mostrarArray(a, n);
}

void ordenarInsertionDescendente(int a[], int n) {
    int i, j, clave;
    for (i = 1; i < n; i++) {
        clave = a[i];
        j = i - 1;

        while (j >= 0 && a[j] < clave) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = clave;

        printf("Paso %d: [ ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
        printf("]\n");
    }
    printf("Resultado final descendente: ");
    mostrarArray(a, n);
}