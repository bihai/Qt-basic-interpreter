#ifndef INSTRIF_H
#define INSTRIF_H

#include "..\Instruccion.h"
#include "InstrGOTO.h"


/// Prototipo de la clase parser
class Parser;
/// Prototipo de la clase InstrGOTO
class InstrGOTO;

/// Clase que representa una instrucci�n IF con salto condicional.
class InstrIF : public Instruccion
{
    public:
        InstrIF();
        virtual ~InstrIF();
        /// Constructor
        /// @param a @see Operando de la condici�n l�gica del if
        /// @param b @see Operando de la condici�n l�gica del if
        /// @param opr @see Operador l�gico de la condici�n del if
        /// @param jmp Etiqueta a la que se saltar� en caso de ser falsa la condici�n. Apuntar� a un ELSE o ENDIF seg�n proceda. Se utilizar� para crear una instrucci�n InstrGOTO que realizar� el salto.
        /// @param p Puntero a un objeto de tipo @see Parser, para poder acceder a las etiquetas y puntero de ejecuci�n y modificar su valor. Se utilizar� para crear una instrucci�n InstrGOTO que realizar� el salto.
        InstrIF(Operando* a, Operando* b, Operador* opr, std::string jmp, Parser* p);
        /// Constructor
        /// @param a @see Operando booleano con la condici�n del if
        /// @param jmp Etiqueta a la que se saltar� en caso de ser falsa la condici�n. Apuntar� a un ELSE o ENDIF seg�n proceda. Se utilizar� para crear una instrucci�n InstrGOTO que realizar� el salto.
        /// @param p Puntero a un objeto de tipo @see Parser, para poder acceder a las etiquetas y puntero de ejecuci�n y modificar su valor. Se utilizar� para crear una instrucci�n InstrGOTO que realizar� el salto.
        InstrIF(Operando* a, std::string jmp, Parser* p);
        /// Implementaci�n de la plantilla definida en la clase base. Ejecuta la instrucci�n.
        bool ejecuta();
    protected:
    private:
        /// Puntero al primer @see Operando.
        Operando* opA;
        /// Puntero al segundo @see Operando. Puede ser NULL.
        Operando* opB;
        /// Puntero al @see Operador. Puede ser NULL.
        Operador* operacion;
        /// Puntero a la instrucci�n de salto a ejecutar en caso de que la condici�n sea falsa;
        InstrGOTO* iGoto;
};

#endif // INSTRIF_H
