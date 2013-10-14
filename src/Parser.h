#ifndef PARSER_H
#define PARSER_H
/// @def MIDEBUG habilita o deshabilita la salida de depuraci�n del programa. Si se comenta el define, se deshabilita.
//#define MIDEBUG

#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include "Utils.h"

#include "Input.h"
#include "Output.h"

// Excepciones
#include "excepciones\EMalformedBlockError.h"
#include "excepciones\EInvalidKeyword.h"
#include "excepciones\EExecAborted.h"

// Instrucciones
#include "Instruccion.h"
#include "instrucciones\InstrPRINT.h"
#include "instrucciones\InstrGOTO.h"
#include "instrucciones\InstrLET.h"
#include "instrucciones\InstrINPUT.h"
#include "instrucciones\InstrIF.h"

// Operandos
#include "operandos\OpCadena.h"
#include "operandos\OpEntero.h"
#include "operandos\OpFlotante.h"
#include "operandos\OpBooleano.h"

// Operadores
#include "operadores\OperadorDIVIDE.h"
#include "operadores\OperadorEQ.h"
#include "operadores\OperadorGT.h"
#include "operadores\OperadorGTE.h"
#include "operadores\OperadorLT.h"
#include "operadores\OperadorLTE.h"
#include "operadores\OperadorMULTI.h"
#include "operadores\OperadorNEQ.h"
#include "operadores\OperadorSUMA.h"
#include "operadores\OperadorRESTA.h"

using namespace std;

/// Clase que se ocupa del parseado del programa en BASIC proporcionado, generando una lista de instrucciones a ejecutar.
class Parser
{
    public:
        Parser(Input *i, Output *o);
        virtual ~Parser();
        /// Comprueba si una instrucci�n es v�lida
        /// @param inst Instrucci�n a ser validada.
        bool isValidInstr(const string inst);
        /// Ejecuta la lista de instrucciones generada.
        void ejecuta();
        /// M�todo que comprueba el estado de las variables despu�s del parseado.
        /// @throw EMalformedBlockError
        void checkStatus() throw (EMalformedBlockError);
        /// Parsea una linea de programa, generando las instrucciones pertinentes e insert�ndolas en la lista de instrucciones a ejecutar.
        /// @param linea L�nea a ser parseada.
        void parseaLinea(const string linea);
        /// M�todo que inicializa las variables de estado del parser (o las vac�a en caso necesario)
        void inicializa();
        /// Obtiene la instrucci�n de la l�nea proporcionada
        /// @param linea L�nea a ser parseada.
        /// @return La instrucci�n correspondiente, trimada.
        string getInstrucc(const string linea);
        /// Elimina la etiqueta de salto de la l�nea proporcionada
        /// @param linea L�nea de la que se eliminar� dicha etiqueta.
        string delLabel(const string linea);
        /// Declaraci�n de clase amiga de la clase que representa una orden GOTO. Declarada de esta manera para
        /// permitir que dicha clase acceda a los atributos privados del parser. (puntero de ejecuci�n)
        friend class InstrGOTO;
    private:
        Input *input;
        Output *output;
        /// variable a utilizar en la ejecuci�n de la lista de instrucciones final. Ser� modificada por la clase @see InstrGOTO para emular los saltos.
        unsigned int ptrInstruccion;
        /// Mapa de etiquetas del programa a las que pueden apuntar los GOTO.
        map<string, int> etiquetas;
        /// Mapa de variables definidas en el programa.
        map<string,Operando *> variables;
        /// Instrucciones reconocidas por el programa.
        set<string> instrucciones;
        /// Palabras reservadas por el programa.
        set<string> rsvWords;
        /// Lista de instrucciones a ser ejecutadas.
        vector<Instruccion *> instRunnable;
#ifdef MIDEBUG
        /// Lista de instrucciones para debug
        vector<string> instDebug;
#endif
        /// Pila que representa los comienzos de bloques if y while. Se utiliza para comprobar su correcta anidaci�n, as� como t�rmino.
        stack<string> ifs;
        /// Funci�n que procesa una linea, retornando si tiene o no etiqueta de salto
        /// @param[in,out] linea L�nea a ser parseada. En caso de tener etiqueta, el par�metro se modifica, eliminado dicha etiqueta.
        /// @param[out] etiqueta Cadena donde se almacenar� el nombre de la etiqueta.
        /// @return true En caso de que tenga etiqueta, adem�s de poner dicha etiqueta en el par�metro del mismo nombre.
        bool linHasLabel(string &linea, string &etiqueta);
        /// funci�n que devuelve la l�nea proporcionada sin la instrucci�n, es decir, sus argumentos
        /// @param linea L�nea de la que se va a eliminar la instrucci�n
        /// @return la l�nea sin la instrucci�n
        string getArguments(const string linea);
        /// funci�n que elimina la primera palabra de una l�nea. Se entiende por primera palabra, aquella que va desde el primer
        /// caracter hasta el primer espacio, o el fin de cadena en su caso.
        /// @param linea de la que se desea eliminar la primera palabra.
        /// @return la l�nea sin la primera palabra. Retorna cadena vac�a en caso de que s�lo hubiese una palabra en la l�nea original.
        string remFirstWord(const string linea);
        /// funci�n que selecciona y devuelve la primera palabra de una l�nea. Se entiende por palabra lo mismo que en @see getArguments
        /// @param linea L�nea de la que se desea seleccionar la primera palabra.
        /// @return La primera palabra de la l�nea proporcionada.
        string getFirstWord(const string linea);
        /// m�todo que se ocupa de parsear la instrucci�n PRINT y generar las instrucciones pertinentes
        /// @param linea L�nea con la instrucci�n mencionada
        void parsePRINT(const string linea);
        /// m�todo que se ocupa de parsear la instrucci�n DIM y generar las instrucciones pertinentes
        /// @param linea L�nea con la instrucci�n mencionada
        void parseDIM(const string linea);
        /// m�todo que se ocupa de parsear la instrucci�n LET y generar las instrucciones pertinentes
        /// @param linea L�nea con la instrucci�n mencionada
        void parseLET(const string linea);
        /// m�todo que se ocupa de parsear la instrucci�n GOTO y generar las instrucciones pertinentes
        /// @param linea L�nea con la instrucci�n mencionada
        void parseGOTO(const string linea);
        /// m�todo que se ocupa de parsear la instrucci�n INPUT y generar las instrucciones pertinentes
        /// @param linea L�nea con la instrucci�n mencionada
        void parseINPUT(const string linea);
        /// m�todo que se ocupa de parsear la instrucci�n IF y generar las instrucciones pertinentes. El segundo par�metro se introduce
        /// con el objetivo de que este m�todo sirva tambi�n para el parseado de la instrucci�n WHILE, cambiando dicho par�metro.
        /// @param linea L�nea con la instrucci�n mencionada
        /// @param etiq Par�metro que representa la etiqueta con la que se almacenar�n los datos necesarios en la pila @see ifs
        void parseIF(const string linea, const string etiq="lblIf");
        /// m�todo que se ocupa de parsear la instrucci�n WHILE y generar las instrucciones pertinentes
        /// @param linea L�nea con la instrucci�n mencionada
        void parseWHILE(const string linea);
        /// m�todo que se ocupa de parsear la instrucci�n ELSE y generar las instrucciones pertinentes
        void parseELSE();
        /// m�todo que se ocupa de parsear la instrucci�n ENDIF y generar las instrucciones pertinentes
        void parseENDIF();
        /// m�todo que se ocupa de parsear la instrucci�n WEND y generar las instrucciones pertinentes
        void parseWEND();
        /// funci�n que se ocupa de comprobar si una cadena tiene el formato de un nombre de variable
        /// @param linea Cadena de la que comprobar el formato.
        /// @return True si es un nombre de variable v�lido, false en caso contrario.
        bool isVarName(const string linea);
        /// funci�n que se ocupa de comprobar si una cadena tiene el formato de un n�mero (entero o flotante)
        /// @param linea Cadena de la que comprobar el formato.
        /// @return True si la cadena representa un n�mero v�lido, false en caso contrario.
        bool isNumber(const string linea);
        /// funci�n que se ocupa de comprobar si una cadena tiene el formato de un n�mero flotante
        /// @param linea Cadena de la que comprobar el formato.
        /// @return True si la cadena representa un n�mero flotante v�lido, false en caso contrario.
        bool isFlotante(const string linea);
        /// funci�n que se ocupa de comprobar si una cadena tiene el formato de un n�mero entero
        /// @param linea Cadena de la que comprobar el formato.
        /// @return True si la cadena representa un n�mero entero v�lido, false en caso contrario.
        bool isEntero(const string linea);
        /// funci�n que se ocupa de comprobar si una cadena tiene el formato de cadena aceptado por el programa.
        /// @param linea Cadena de la que comprobar el formato.
        /// @return True si la cadena representa una cadena v�lida, false en caso contrario.
        bool isCadena(const string linea);
        /// funci�n que se ocupa de comprobar si una cadena tiene el formato de booleano aceptado por el programa.
        /// @param linea Cadena de la que comprobar el formato.
        /// @return True si la cadena representa un valor booleano v�lida, false en caso contrario.
        bool isBooleano(const string linea);
        /// funci�n que se ocupa de determinar qu� tipo de operando se le proporciona en el par�metro, crear el objeto
        /// adecuado y devolver una referencia a �l.
        /// @param linea Cadena a partir de la que se pretende crear el objeto
        /// @return Puntero a un objeto cuya clase base es @see Operando.
        Operando* getOperando(const string linea);
        /// funci�n que se ocupa de determinar qu� tipo de operador se le proporciona en el par�metro, crear el objeto
        /// adecuado y devolver una referencia a �l.
        /// @param linea Cadena a partir de la que se pretende crear el objeto
        /// @return Puntero a un objeto cuya clase base es @see Operador.
        Operador* getOperador(const string linea);
        /// funci�n que devuelve la primera palabra de la l�nea proporcionada como par�metro, y modifica el par�metro, eliminando dicha palabra
        /// @param[in,out] linea Cadena a partir de la que se pretende crear el objeto
        /// @return Puntero a un objeto cuya clase base es @see Operando.
        string getVar(string &linea);
};

#endif // PARSER_H
