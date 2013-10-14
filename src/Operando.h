#ifndef OPERANDO_H
#define OPERANDO_H

#include <string>
#include <sstream>
#include "utils.h"
#include "excepciones\EInvalidKeyword.h"

/// clase abstracta que representa un operando
class Operando
{
    public:
        /// plantilla para la funci�n que devuelve una cadena con el valor del operando.
        /// @return cadena con el valor del operando.
        virtual std::string getValue()=0;
        /// plantilla para la funci�n que devuelve el tipo del operando.
        /// @return cadena con el tipo del operando.
        virtual std::string getTipo()=0;
        /// plantilla para el m�todo que establece el valor del operando.
        /// @param val Cadena con el nuevo valor para el operando.
        virtual void setValue(std::string val)=0;
        /// plantilla para la funci�n que devuelve el nombre del par�metro.
        /// @return Cadena con nombre del par�metro en caso de que lo tenga. Cadena vac�a en caso contrario.
        virtual std::string getNombre()=0;
        /// funci�n est�tica que utilizando plantillas, comprueba si una cadena proporcionada es convertible
        /// al tipo de la plantilla. En caso de que as� sea, almacena el valor en uno de sus par�metros.
        /// @param[in,out] num Puntero al tipo que se quiere comprobar.
        /// @param s cadena que contiene el dato del tipo T
        /// @return True en caso de ser convertible, False en caso contrario.
        template <typename T> static bool isT(T *num, string s);
        /// funci�n est�tica que utilizando plantillas, convierte el tipo de la plantilla a cadena.
        /// @param x par�metro del tipo que se quiere convertir.
        /// @return Cadena que representa el valor del par�metro.
        template <typename T> static string TToStr(T x);
};

template <typename T>
bool Operando::isT(T *num, string s)
{
    istringstream convert( s );
    return ( ( convert >> *num ) && convert.eof() );
}

template <typename T>
string Operando::TToStr(T x)
{
    ostringstream convert;
    convert << x;
    return convert.str();
}

#endif // OPERANDO_H
