#ifndef OPERADOR_H
#define OPERADOR_H

#include <string>
#include <iostream>

#include "excepciones\EMalformedBlockError.h"

// Operandos
#include "Operando.h"
#include "operandos\OpEntero.h"
#include "operandos\OpFlotante.h"
#include "operandos\OpCadena.h"
#include "operandos\OpBooleano.h"

/// Clase base para los operadores soportados
class Operador
{
    public:
        /// plantilla para la funci�n que ejecuta la operaci�n correspondiente al operador.
        /// @param opA Puntero a @see Operando
        /// @param opB Puntero a @see Operando
        /// @return Cadena con el resultado de la operaci�n.
        virtual std::string ejecuta(Operando* opA, Operando* opB)=0;
        /// funci�n que devuelve el s�mbolo que identifica el operador.
        /// @return string con el s�mbolo.
        virtual std::string getSimbolo()=0;
};

#endif // OPERADOR_H
