#ifndef INSTRUCCION_H
#define INSTRUCCION_H

#include "Operando.h"

/// Clase abstracta que representa una instrucci�n del programa
class Instruccion
{
    public:
        /// plantilla para la funci�n que ejecuta la instrucci�n
        /// @return bool Retorna True si la ejecuci�n ha sido correcta. False en caso contrario.
        virtual bool ejecuta() = 0;
};

#endif // INSTRUCCION_H
