#include <stdio.h>

// Variables globales
int K = 3;

// Prototipos
int f1(void);
int f2(void);
int f3(void);
int f4(void);

int main(void) {
    int I;
    for (I = 1; I <= 3; I++) {
        printf("\nEl resultado de la función f1 es %d", f1());
        printf("\nEl resultado de la función f2 es %d", f2());
        printf("\nEl resultado de la función f3 es %d", f3());
        printf("\nEl resultado de la función f4 es %d", f4());

    }
    return 0;
}

int f1(void) {
    // Usa la variable global K
    K += K;
    return K;
}

int f2(void) {
    // Variable local K (oculta a la global)
    int K = 1;
    K++;
    return K;
}

int f3(void) {
    // Variable estática K (conserva valor entre llamadas)
    static int K = 8;
    K += 2;
    return K;
}

int f4(void) {
    // Variable local K
    int local_K = 5;
    // Suma la global K
    local_K = local_K + K;
    return local_K;
}
