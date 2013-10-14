#ifndef INPUT_H
#define INPUT_H
#include <string>
#include <QWidget>

/// Clase que se ocupa de la entrada de datos del parser, transmiti�ndosela al entorno gr�fico
class Input
{
    public:
        Input();
        /// Constructor
        /// @param *prnt Puntero a un widget que ser� el padre de las ventanas que se necesite crear.
        Input(QWidget *prnt);
        /// Funci�n que se ocupa de solicitar una entrada mostrando como descripci�n un texto
        /// @param texto Texto a mostrar en la pantalla de solicitud
        /// @return Cadena con la entrada del usuario
        std::string ask(std::string texto);
    private:
        /// Puntero a un widget que ser� el padre de las ventanas que se necesite crear.
        QWidget *parentW;
};

#endif // INPUT_H
