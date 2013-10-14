#ifndef EINVALIDKEYWORD_H
#define EINVALIDKEYWORD_H

#include <string>
#include <stdexcept>

using namespace std;

/// Excepci�n que se lanza cuando se encuentra una palabra no v�lida.
class EInvalidKeyword : public invalid_argument
{
    public:
        EInvalidKeyword(string msg) : invalid_argument("Palabra clave no reconocida: "+msg) {};
};

/// Excepci�n que se lanza cuando se encuentra una instrucci�n no v�lida.
class EInvalidInstr : public EInvalidKeyword
{
    public:
        EInvalidInstr(string msg) : EInvalidKeyword(msg) {};
};

/// Excepci�n que se lanza cuando se pretende operar sobre un operando pero no ha sido inicializado.
class EOperandoNoInicializado : public invalid_argument
{
    public:
        EOperandoNoInicializado(string msg) : invalid_argument(msg) {};
};

/// Excepci�n que se lanza cuando no se puede llevar a cabo una conversi�n a un tipo.
class EInvalidConversion : public invalid_argument
{
    public:
        EInvalidConversion(string origen, string destino) : invalid_argument(origen+" no es un "+destino+" valido") {};
};

#endif // EINVALIDKEYWORD_H
