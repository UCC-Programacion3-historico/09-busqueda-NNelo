//
// Created by nelon on 21/11/2017.
//

#ifndef INC_09_BUSQUEDA_LISTA_H
#define INC_09_BUSQUEDA_LISTA_H

template<class T>
class Nodo {
private:
    T dato;
    Nodo<T> *next;
public:
    Nodo() { next = nullptr; }

    Nodo(T d, Nodo<T> *n) {
        dato = d;
        next = n;
    }

    void setDato(T d) { dato = d; }

    void setNext(Nodo<T> *n) { next = n; }

    T getDato() { return dato; }

    Nodo<T> *getNext() { return next; }
};

template<class T>
class Lista {
private:
    Nodo<T> *inicio;

    bool buscarR(T, Nodo<T> *);

public:
    Lista();

    ~Lista();

    bool esVacia();

    Nodo<T> *getInicio() const;

    void insertarPrimero(T);

    void remover(T);

    void vaciar();

    bool buscar(T);

    bool buscarRecursiva(T);
};


template<class T>
Lista<T>::Lista() {
    inicio = nullptr;
}

template<class T>
Lista<T>::~Lista() {
    vaciar();

}

template<class T>
void Lista<T>::vaciar() {
    Nodo<T> *borr;
    Nodo<T> *aux = inicio;

    while (aux != nullptr) {
        borr = aux;
        aux = aux->getNext();
        delete borr;
    }
    inicio = nullptr;
}

template<class T>
bool Lista<T>::esVacia() {
    return inicio == nullptr;
}

template<class T>
Nodo<T> *Lista<T>::getInicio() const {
    return inicio;
}

template<class T>
void Lista<T>::insertarPrimero(T dato) {
    Nodo<T> *nn = new Nodo<T>(dato, inicio);
    inicio = nn;
}

template<class T>
void Lista<T>::remover(T dato) {
    Nodo<T> *aux = inicio;
    if (aux == nullptr)
        throw -1;
    if (dato == inicio->getDato()) {
        inicio = inicio->getNext();
        delete aux;
        return;
    }

    while (aux->getNext() != nullptr && aux->getNext()->getDato() != dato) {
        aux = aux->getNext();
    }

    Nodo<T> *tmp = aux->getNext();

    if (tmp == nullptr) {
        throw -1;
    }

    aux->setNext(tmp->getNext());
    delete tmp;
}

template<class T>
bool Lista<T>::buscar(T d) {
    Nodo<T> *aux = inicio;
    while (aux != nullptr && aux->getDato() != d)
        aux = aux->getNext();
    if (aux == nullptr)
        return false;
    return true;
}

template<class T>
bool Lista<T>::buscarRecursiva(T d) {
    return buscarR(d, inicio);
}

template<class T>
bool Lista<T>::buscarR(T d, Nodo<T> *ptr) {
    if (ptr == nullptr)
        return false;
    else {
        if(ptr->getDato() == d)
            return true;
        else
            buscarR(d, ptr->getNext());
    }
}

#endif //INC_09_BUSQUEDA_LISTA_H
