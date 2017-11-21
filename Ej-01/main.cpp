#include <iostream>

using namespace std;

void fn(int x, int v[], int ini, int fin, int pos, bool &retorno);

void fnR(int x, int v[], int ini, int fin, int pos, bool &retorno);

int main() {
    std::cout << "Ejercicio 09/01\n" << std::endl;
    int arr[] = {3, 5, 8, 1, 2, 9, 7, 0, 4, 6};
    bool est;

    for (int i = 0; i < 10; ++i) {
        int aBuscar = arr[i], principio = 2, final = 5, posTemp = 2;
        fn(aBuscar, arr, principio, final, posTemp, est);
        if (est) {
            cout << "I: " << aBuscar << " está entre " << principio << " y " << final << endl;
        } else {
            cout << "I: No ta\n";
        }
        est = false;
        fnR(aBuscar, arr, principio, final, posTemp, est);
        if (est) {
            cout << "R: " << aBuscar << " está entre " << principio << " y " << final << endl;
        } else {
            cout << "R: No ta\n";
        }
        cout << "\n";
    }
    return 0;
}

//void fn(int x, int v[], int ini, int fin, int pos, bool retorno) {
void fn(int x, int v[], int ini, int fin, int pos, bool &retorno) {
    pos = ini;
    retorno = false;
    while ((pos <= fin) && (!retorno)) {
        if (v[pos] == x) {
            retorno = true;
        } else
            ++pos;
    }
}

/*
 * La funcion busca el valor del parametro x entre el rango ini y fin dentro del arreglo v. El parametro pos se recibe para no declararlo dentro de la funcion.
 * La función al ser void almacena el resultado parcial en su parámetro retorno, sin embargo al ser pasado por copia no puede ser interpretado por la instancia
 * del programa que ha llamado a la función.
 *
 * De haberse declarado como sigue,
 *      void fn(int x, int v[], int ini, int fin, int pos, bool &retorno)
 * el parametro por referencia retorno es modificado por true en caso de haber encontrado x y false en caso contrario. Por lo que en una instancia posterior del
 * programa principal se puede evaluar el estado de retorno.
 * */

void fnR(int x, int v[], int ini, int fin, int pos, bool &retorno) {
    if (ini > 0)
        fnR(x, &v[1], ini - 1, fin - 1, pos, retorno);
    else {
        if (fin < ini) {
            retorno = false;
        } else {
            if (v[0] == x) {
                retorno = true;
            } else {
                fnR(x, &v[1], 0, fin - 1, pos, retorno);
            }
        }
    }
}
