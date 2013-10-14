#ifndef EEXECABORTED_H
#define EEXECABORTED_H

#include <string>
#include <stdexcept>

using namespace std;

/// Excepci�n que se lanza cuando se aborta la ejecuci�n del programa
class EExecAborted : public runtime_error
{
    public:
        EExecAborted() : runtime_error("Ejecuci�n abortada") {};
    private:
};

#endif // EEXECABORTED_H
