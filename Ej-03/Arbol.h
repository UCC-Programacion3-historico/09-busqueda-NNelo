//
// Created by nelon on 10/11/2017.
//

#ifndef ARBOLB_ARBOL_H
#define ARBOLB_ARBOL_H

#include "NodoArbol.h"

template<class T>
class Arbol {
private:
    NodoArbol<T> *raiz;
public:
    Arbol();

//    ~Arbol();

    void put(T);

    T search(T);

    void print();

//    NodoArbol<T> *balancear(NodoArbol<T>*);

    void inorder();

    void remover(T);

    bool esVacio();
};

template<class T>
Arbol<T>::Arbol() {
    this->raiz = nullptr;
}

template<class T>
void Arbol<T>::put(T dato) {
    if (this->raiz == nullptr)
        this->raiz = new NodoArbol<T>(dato);
    else {
        NodoArbol<T> *NN = new NodoArbol<T>(dato);
        raiz = raiz->put(NN);
    }
}

template<class T>
T Arbol<T>::search(T dato) {
    if (raiz == nullptr)throw 1;
    return raiz->search(dato);
}

template<class T>
void Arbol<T>::print() {
    if (raiz != nullptr)
        raiz->print(false, "");
}

template<class T>
void Arbol<T>::inorder() {
    if (raiz != nullptr)
        raiz->inorder();
}

template<class T>
void Arbol<T>::remover(T d) {
    if(this->raiz == nullptr)
        throw -1;
    this->raiz = this->raiz->remover(d);

}

template <class T>
bool Arbol<T>::esVacio() {
    return raiz == nullptr;
}
#endif //ARBOLB_ARBOL_H