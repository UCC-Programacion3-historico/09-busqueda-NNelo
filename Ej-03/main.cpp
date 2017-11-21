#include <iostream>
#include "Arbol.h"

int main() {
    Arbol<int> A;

    int k = 0;

    srand(time(nullptr));
    while (k < 500) {
        try {
            A.put(rand() % 1000);
            k++;
        } catch (int e) {}
    }

    A.print();
    cout << "******************\n";
    A.inorder();
    cout << "\n" << k << endl;

//    for (k = 0; k < 3001; k++) {
//        A.put(k);
//    }
//
//   A.print();
//    cout << "******************\n";

    while (k) {
        int d;
        cout << "\nBORRAR\n";
        cin >> d;
        try {
            A.remover(d);
        } catch (int e) {}
        A.print();
        A.inorder();
    }
//    cout << "\nHOLA\n";
//
//    k=0;
//    while (k < 100) {
//        try {
//            A.put(rand()%1000);
//            k++;
//        } catch (int e) {}
//    }

//    A.print();
    cout << "\nTERMINA\n";

    return 0;
}