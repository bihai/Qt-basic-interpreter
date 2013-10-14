#ifndef OUTPUT_H
#define OUTPUT_H
#include <string>
#include <QPlainTextEdit>

/// Clase que se ocupar� de enviar la salida del scanner al entorno gr�fico.
class Output
{
    public:
        /// Constructor
        /// @param *s Puntero a un contenedor de texto que funcionar� como una salida de consola.
        Output(QPlainTextEdit *s);
        /// Escribe un texto en la consola
        /// @param texto Texto a escribir
        void escribe(std::string texto);
        /// Escribe un texto en la consola e inserta un salto de linea extra.
        /// @param texto Texto a escribir
        void escribeLn(std::string texto);
        /// Limpia la consola
        void limpiar();
    private:
        /// Puntero a un contenedor de texto que funcionar� como una salida de consola.
        QPlainTextEdit *salida;

};

#endif // OUTPUT_H
