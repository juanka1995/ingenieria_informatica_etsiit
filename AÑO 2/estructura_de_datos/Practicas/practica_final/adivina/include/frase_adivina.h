#ifndef __FRASE_ADIVINA_H
#define __FRASE_ADIVINA_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <unordered_map>

class FraseAdivina{
    private:
        struct Letra{
            bool visible;
            char c;
            Letra(char c, bool v){
                this->c = c;
                this->visible = v;
            };
        };

        std::vector<Letra> cadena;
        std::string original;
        std::unordered_map<char, std::vector<int> > mapa;
        unsigned n_visible, n_total;

        // Funciones utilizadas por el constructor

        /**
        * @brief Almacena cada una de las posiciones de un string del caracter dado en un vector
        * @param string s: cadena en la que buscar las posiciones donde aparece c
        * @param char c: char a buscar en la cadena
        * @return Devuelve un vector que contiene cada una de las posiciones dentro de un string del caracter dado
        **/
        std::vector<int> posLetras(const std::string & s, char c);
        /**
        * @brief Crea un mapa, cuya clave es un caracter y cuyo valor es un vector de enteros que contiene las posiciones en las que está dicho caracter
        * @param string s: string donde buscar el numero de veces que aparece cada caracter
        * @return Devuelve el mapa creado
        **/
        std::unordered_map<char,std::vector<int> > stringToMap(const std::string & s);
        /**
        * @brief Añade una cadena al vector de letras y pone todos los caracteres alfabéticos de dicha cadena a no visibles
        * @param s: Cadena a añadir en el vector de letras con caracteres no visibles
        **/
        void setCadena(const std::string & s);

    public:
        /**
        * @brief Constructor de una frase para adivinar
        * @param s: frase original
        **/
        FraseAdivina(const std::string & s);
        /**
        * @brief Hace visible un porcentaje de letras de la frase a adivinar
        * @param perc: Porcentaje de letras a poner visibles
        **/
        void setVisible(int perc);
        /**
        * @brief Busca una letra en la frase y si la encuentra la pone visible
        * @param c: Letra a buscar en la frase para hacer visible
        * @return Devuelve el numero de letras actualizadas a visibles
        **/
        int estaYActualiza(char c);
        /**
        * @brief Comprueba si la cadena introducida es la frase a adivinar
        * @param s: Cadena a comparar con la original
        * @return True si la cadena es igual que la original, false en caso contrario
        **/
        bool esIgual(const std::string & s);
        /**
        * @brief Comprueba si se ha adivinado la frase
        * @return True si se ha adivinado la frase, false en caso contrario
        **/
        bool adivinada();
        /**
        * @brief Sobrecargar del operador << para mostrar una frase con sus letras visibles y ocultas
        * @return Duvuelve el flujo de salida
        **/
        friend std::ostream & operator<<(std::ostream & os, FraseAdivina & f);
};

#endif
