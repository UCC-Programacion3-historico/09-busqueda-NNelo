#include "gtest/gtest.h"
#include "../Ej-02/Lista.h"

Lista<int> *L;

TEST(test_Ej02, test) {
    EXPECT_EQ(true, true);
}

#define tam 8
int v[tam] = {4, 5, 9, 1, 2, 7, 2, 0};

TEST(test_Ej02, agrega) {
    L = new Lista<int>;
    for (int i = 0; i < tam; ++i) {
        L->insertarPrimero(v[i]);
    }
    EXPECT_EQ(0, L->getInicio()->getDato());
}

TEST(test_Ej02, encuentra) {
    for (int i = 0; i < tam; ++i) {
        EXPECT_TRUE(L->buscar(v[i]));
        EXPECT_TRUE(L->buscarRecursiva(v[i]));
    }
}

TEST(test_Ej02, noencuentra) {
    EXPECT_FALSE(L->buscar(10));
    EXPECT_FALSE(L->buscarRecursiva(10));
}
