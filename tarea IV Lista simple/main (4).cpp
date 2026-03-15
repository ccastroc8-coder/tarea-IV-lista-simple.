#include <iostream>                                //Carlos Daniel Castro Caceres
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {
    Nodo* head = NULL;
    Nodo* actual = NULL;

    int valor;
    char opcion = 's';

    // Variables del punto extra
    int cantidad = 0;
    int suma = 0;
    double promedio = 0;

    while (opcion == 's' || opcion == 'S') {
        cout << "Ingrese un numero: ";
        cin >> valor;

        // Crear nodo dinamicamente
        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        // Insertar nodo al final de la lista
        if (head == NULL) {
            head = nuevo;
        } else {
            actual = head;
            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }

        // Acumular datos para el punto extra
        cantidad++;
        suma += valor;

        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> opcion;
    }

    // Recorrer lista
    cout << "\nLista generada:\n";
    actual = head;
    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;

    // Calculos extra
    if (cantidad > 0) {
        promedio = (double)suma / cantidad;
    }

    cout << "\nCantidad total de nodos: " << cantidad << endl;
    cout << "Suma de los valores: " << suma << endl;
    cout << "Promedio de los valores: " << promedio << endl;

    // Liberar memoria dinamica
    actual = head;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    return 0;
}