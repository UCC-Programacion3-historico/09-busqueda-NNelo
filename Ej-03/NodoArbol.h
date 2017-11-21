//
// Created by nelon on 10/11/2017.
//

#ifndef ARBOLB_NODOARBOL_H
#define ARBOLB_NODOARBOL_H


#include <iostream>

using namespace std;

template<class T>
class NodoArbol {
private:
    T dato;
    NodoArbol<T> *izq;
    NodoArbol<T> *der;
    int balance;

    int calculaBalance(NodoArbol<T> *);

    int altura();

    NodoArbol<T> *rotacionII(NodoArbol<T> *, NodoArbol<T> *);

    NodoArbol<T> *rotacionDD(NodoArbol<T> *, NodoArbol<T> *);

    NodoArbol<T> *rotacionDI(NodoArbol<T> *, NodoArbol<T> *);

    NodoArbol<T> *rotacionID(NodoArbol<T> *, NodoArbol<T> *);

    NodoArbol<T> *balancearNodo(NodoArbol<T> *);

    T mayor();

public:
    NodoArbol(T);

//    ~NodoArbol();

    T getDato();

    NodoArbol<T> *put(NodoArbol<T> *);

    T search(T);

    void print(bool, string);

    void inorder();

    NodoArbol<T> *remover(T);
};

template<class T>
NodoArbol<T>::NodoArbol(T d) {
    this->dato = d;
    this->izq = nullptr;
    this->der = nullptr;
    balance = 0;
}

template<class T>
T NodoArbol<T>::getDato() {
    return this->dato;
}

template<class T>
NodoArbol<T> *NodoArbol<T>::put(NodoArbol<T> *NN) {
    if (this->dato == NN->dato)
        throw -1;
    if (this->dato > NN->dato) {
        if (this->izq == nullptr) {
            this->izq = NN;
//            this->balance = calculaBalance(this);
            if (this->der != nullptr)
                this->balance = 0;
            else
                this->balance = -1;
        } else {
            this->izq = this->izq->put(NN);
            return balancearNodo(this);
        }
    } else {
        if (this->der == nullptr) {
            this->der = NN;
//            this->balance = calculaBalance(this);
            if (this->izq != nullptr)
                this->balance = 0;
            else
                this->balance = 1;
        } else {
            this->der = this->der->put(NN);
            return balancearNodo(this);
        }
    }
}

template<class T>
NodoArbol<T> *NodoArbol<T>::remover(T d) {
    if (this == nullptr)
        throw -1;
    if (this->dato == d) {
        if (this->izq == nullptr && this->der == nullptr) {
            delete this;
            return nullptr;
        }
        if (this->izq == nullptr && this->der != nullptr) {
            NodoArbol<T> *tmp = this->der;
            delete this;
            return tmp;
        }
        if (this->izq != nullptr && this->der == nullptr) {
            NodoArbol<T> *tmp = this->izq;
            delete this;
            return tmp;
        }
        if (this->izq != nullptr && this->der != nullptr) {
            T nd = this->izq->mayor();
            this->dato = nd;
            this->izq = this->izq->remover(nd);
        }
    }



    else {
        if (this->dato > d) {
            this->izq = this->izq->remover(d);
        } else {
            if (this->dato < d) {
                this->der = this->der->remover(d);
            }
        }
    }
    return balancearNodo(this);
}

template<class T>
T NodoArbol<T>::mayor() {
    if (this->der == nullptr)
        return this->dato;
    this->der->mayor();
}

template<class T>
NodoArbol<T> *NodoArbol<T>::balancearNodo(NodoArbol<T> *ptr) {
    ptr->balance = calculaBalance(ptr);
    NodoArbol<T> *n1;
    if (this->balance == -2) {
        n1 = ptr->izq;
        if (n1->balance == -1) {
            ptr = rotacionII(ptr, n1);
        } else if (n1->balance == 1) {
            ptr = rotacionID(ptr, n1);
        } else if (n1->balance == 0)
            ptr = rotacionII(ptr, n1);
        cout << "BALANCEO\n";
    }

    if (this->balance == 2) {
        n1 = this->der;
        if (n1->balance == 1) {
            ptr = rotacionDD(ptr, n1);
        } else if (n1->balance == -1) {   // capaz sea else
            ptr = rotacionDI(ptr, n1);
        } else if (n1->balance == 0)
            ptr = rotacionDD(ptr, n1);
        cout << "BALANCEO\n";
    }
    cout << "BN" << endl;
    return ptr;
}

template<class T>
int NodoArbol<T>::altura() {
    int left, right;

    if (this->izq == nullptr && this->der == nullptr)
        return 1;

    if (this->izq == nullptr)
        return 1 + this->der->altura();

    if (this->der == nullptr)
        return 1 + this->izq->altura();

    left = this->izq->altura();
    right = this->der->altura();

    if (left > right)
        return left + 1;
    else
        return right + 1;
}

template<class T>
int NodoArbol<T>::calculaBalance(NodoArbol<T> *ptr) {
    int left = 0, right = 0;
    if (ptr->izq != nullptr)
        left = ptr->izq->altura();
    if (ptr->der != nullptr)
        right = ptr->der->altura();
    cout << "CB" << endl;
    return right - left;     //Joyanes der - izq
}

template<class T>
NodoArbol<T> *NodoArbol<T>::rotacionII(NodoArbol<T> *n, NodoArbol<T> *n1) {
    n->izq = n1->der;
    n1->der = n;
    if (n1->balance == 1) {
        n->balance = 0;
        n1->balance = 0;
    } else {
        n->balance = -1;
        n1->balance = 1;
    }
    return n1;
}

template<class T>
NodoArbol<T> *NodoArbol<T>::rotacionDD(NodoArbol<T> *n, NodoArbol<T> *n1) {
    n->der = n1->izq;
    n1->izq = n;
    if (n1->balance == 1) {
        n->balance = 0;
        n1->balance = 0;
    } else {
        n->balance = 1;
        n1->balance = -1;
    }
    return n1;
}

template<class T>
NodoArbol<T> *NodoArbol<T>::rotacionDI(NodoArbol<T> *n, NodoArbol<T> *n1) {
    NodoArbol<T> *n2 = n1->izq;
    n->der = n2->izq;
    n2->izq = n;
    n1->izq = n2->der;
    n2->der = n1;

    if (n2->balance == 1)
        n->balance = -1;
    else
        n->balance = 0;

    if (n2->balance == -1)
        n1->balance = 1;
    else
        n1->balance = 0;

    n2->balance = 0;
    return n2;
}

template<class T>
NodoArbol<T> *NodoArbol<T>::rotacionID(NodoArbol<T> *n, NodoArbol<T> *n1) {
    NodoArbol<T> *n2 = n1->der;
    n->izq = n2->der;
    n2->der = n;
    n1->der = n2->izq;
    n2->izq = n1;

    if (n2->balance == 1)
        n1->balance = -1;
    else
        n1->balance = 0;
    if (n2->balance == -1)
        n->balance = 1;
    else
        n->balance = 0;

    n2->balance = 0;
    return n2;
}

template<class T>
T NodoArbol<T>::search(T d) {
    if (d == dato)
        return dato;
    if (d < dato) {
        if (izq == nullptr)
            throw 1;
        return izq->search(d);
    } else {
        if (der == nullptr)
            throw 1;
        return der->search(d);
    }
}

template<class T>
void NodoArbol<T>::print(bool esDerecho, string identacion) {
    if (der != nullptr) {
        der->print(true, identacion + (esDerecho ? "     " : "|    "));
    }
    cout << identacion;
    if (esDerecho) {
        cout << " /";
    } else {
        cout << " \\";
    }
    cout << "-- ";
    cout << dato << endl;
    if (izq != nullptr) {
        izq->print(false, identacion + (esDerecho ? "|    " : "     "));
    }
}

template<class T>
void NodoArbol<T>::inorder() {
    if (izq != NULL) izq->inorder();
    cout << dato << ", ";
    if (der != NULL) der->inorder();
}

#endif //ARBOLB_NODOARBOL_H



