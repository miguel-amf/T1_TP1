#ifndef NOME_H
#define NOME_H

#include <string>
#include <stdexcept>

using namespace std;

//!Classe Nome
/*!
* Classe que implementa o dominio nome, formado por caracteres A-Z e espacos em branco
*/
class Nome {

    public:
        //!Construtor do objeto
        /*!instancia o modulo, colocando as variaveis em valores padrao
        */
        Nome();

        //!get do nome
        /*!retorna o valor armazenado para nome
        * \param [out] <return> string contendo nome
        */
        string getNome();

        //!set do nome
        /*!armazena o valor requerido, caso esteja dentro do padrao
        * \param [in] <entrada> string contendo nome
        */
        void setNome(string) throw(invalid_argument);

    private:
        string nome;
        //!valida a string de entrada
        void avalia(string) throw(invalid_argument);
};








#endif // NOME_H
