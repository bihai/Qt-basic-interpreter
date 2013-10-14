#ifndef OPERADORNEQ_H
#define OPERADORNEQ_H

#include "..\Operador.h"

/// Clase que representa el operador "distinto"
class OperadorNEQ : public Operador
{
    public:
        OperadorNEQ();
        virtual ~OperadorNEQ();
        /// funci�n que implementa la plantilla @see Instruccion
        /// @param opA Puntero al primer @see Operando
        /// @param opB Puntero al segundo @see Operando
        /// @return cadena con el valor del resutado de ejecutar el operador sobre los operandos.
        std::string ejecuta(Operando* opA, Operando* opB);
        /// funci�n que devuelve el s�mbolo que identifica el operador.
        /// @return string con el s�mbolo.
        std::string getSimbolo();
    protected:
    private:
        /// atributo de clase que representa el s�mbolo del operador.
        static const std::string SIMBOLO;
};

#endif // OPERADORNEQ_H
