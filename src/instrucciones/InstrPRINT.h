#ifndef INSTRPRINT_H
#define INSTRPRINT_H

#include <iostream>
#include <vector>
#include "..\Instruccion.h"
#include "..\Output.h"

using namespace std;

/// Clase que representa una instrucci�n PRINT que muestra datos por pantalla.
class InstrPRINT : public Instruccion
{
    public:
        InstrPRINT();
        /// Constructor
        /// @param txt Vector de punteros a operando con lo que se va a mostrar por pantalla.
        /// @param o Puntero a la clase que se ocupa de gestionar la salida de datos de la aplicaci�n
        InstrPRINT(vector<Operando *> txt,  Output *o);
        virtual ~InstrPRINT();
        /// Implementaci�n de la plantilla definida en la clase base. Ejecuta la instrucci�n.
        bool ejecuta();
    private:
        /// Vector de punteros a operando con lo que se va a mostrar por pantalla.
        vector<Operando *> op;
        /// Puntero a la clase que se ocupa de gestionar la salida de datos de la aplicaci�n
        Output *output;
};

#endif // INSTRPRINT_H
