#include "gtest/gtest.h"
#include "../Ej-03/Arbol.h"


using namespace std;

Arbol<string> *miArbol;

TEST(test_ArbolBinario, nuevaTablaVacia) {
    miArbol = new Arbol<string>();
    EXPECT_EQ(miArbol->esVacio(), true);
}

TEST(test_ArbolBinario, agregoTres_noVacia) {
    miArbol->put("Tres");
    miArbol->put("Dos");
    miArbol->put("Uno");
    EXPECT_EQ(miArbol->esVacio(), false);
}

TEST(test_ArbolBinario, obtengoDato) {
    EXPECT_EQ(miArbol->search("Tres"), "Tres");
    EXPECT_EQ(miArbol->search("Dos"), "Dos");
    EXPECT_EQ(miArbol->search("Uno"), "Uno");
    EXPECT_ANY_THROW(miArbol->search("Cuatro"));
}

TEST(test_ArbolBinario, borroDato) {
    EXPECT_NO_THROW(miArbol->remover("Tres"));
    EXPECT_ANY_THROW(miArbol->remover("Tres")) << "Remover no tira exepción";
}
