#include <fstream>
#include <iostream>
#include <vector>
#include "listas.hpp"

using namespace std;

int main()
{
    fstream arch_in;
    arch_in.open("entrada.txt");
    if (!arch_in) {
        cout << "Error al inicializar el archivo entrada.txt" << endl;
        return 1;     
    }

    fstream arch_out;
    arch_out.open("salida.txt");
    if (!arch_out) {
        cout << "Error al inicializar el archivo salida.txt" << endl;
        return 1;
    }

    int size = 14;
    char sb[size]{}; //search buffer
    char lb[size]{}; //lock-ahead buffer

    Nodo<char> *window = nullptr;

    // arch_in >> sb[0];
    for (int i = 0; arch_in >> lb[i] && i < size; i++) {
        agregar(window, lb[i]);
    } //Carga inicial del lb y sw
    arch_in.seekg(size, ios::beg);

    // arch_out << "< " << 0 << "; " << 0 << "; " << sb[0] << " >" << endl;a

    char letra;
    int length = 0;
    int offset = 0;
    char ltr_fin;
    int j = 0;
    int i = 0;
    int d = 0;
    int cp = 0;
    Nodo<char> *aux = window;
    for (cp;lb[0] != '\0'; cp++) { 
        for (i = 0; i < size; i++) {
            if (sb[i] == lb[j]) {
                offset = i;
                length = j;
                while (sb[i++] == lb[j++]) {
                    length = j;
                    if (sb[i] == '\0') {
                        i--;
                    }
                }
                break;
            }
        }

        if (length == size) {
            length--;
            ltr_fin = lb[length];
        } else {
            ltr_fin = lb[length];
        }  
        arch_out << length << " " << offset << " " << ltr_fin << endl;

        if (cp < size) {
            for (int i = 0; i < length+1 && arch_in.get(letra); i++) {
                agregar(window, letra);
            }
            
             if(length +1 >= size) {
                pop(window);
            }

            Nodo<char> *aux = window;
            if (length +1 < size) {
                for (int i = 0; i < d; i++) {
                    aux = aux->sig;
                }
            }
            for (int i = 0; i < length+1; i++) {
                sb[d] = aux->dato;
                aux = aux->sig;
                d++;
            }
            for (int i = 0; i < size; i++) {
                lb[i] = aux->dato;
                aux = aux->sig;
            }

            
            
        } else {
            for (int i = 0; i < length+1; i++) {
                if (!(arch_in >> letra)) {
                    pop(window);
                    agregar(window, '\0');
                } else {
                    pop(window);
                    agregar(window, letra);
                }
            }
            Nodo<char> *aux = window;
            for (int i = 0; i < size; i++) {
                sb[i] = aux->dato;
                aux = aux->sig;
            }
            for (int i = 0; i < size; i++) {
                lb[i] = aux->dato;
                aux = aux->sig;
            }
        }

        cp += length;
        length = 0;
        j = 0;
    }

    arch_out.seekg(0, ios::beg);

    char texto[cp]{};
    for (int indice = 0; arch_out >> length >> offset >> ltr_fin; indice++) {
        if (indice < size && indice != 0) {
            for (int i = 0; i < length; i++) {
                letra = texto[i+offset];
                texto[indice] = letra;
                indice++;
            }
        } else {
            for (int i = 0; i < length; i++) {
                if (offset > length) {
                    letra = texto[(indice-size)+offset-i];
                    texto[indice] = letra;
                    indice++;
                } else {
                    letra = texto[(indice-size)+offset];
                    texto[indice] = letra;
                    indice++;
                }
                
            }
        }
        texto[indice] = ltr_fin;
    }

    for (int i = 0; i < cp; i++) {
        cout << texto[i];
    }
    
    
    arch_in.close();
    arch_out.close();

    return 0;
}