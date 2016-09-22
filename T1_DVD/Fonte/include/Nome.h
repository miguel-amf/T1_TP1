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
        string getNome() const;

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


//!Classe TesteNome
/*!
* Testa um objeto de entrada do tipo Nome
*/
class TesteNome {

    public:

        //!Construtor
        /*!
        *Constroi o objeto TesteNome
        */
        TesteNome();
        //!setUp
        /*!
        * Realiza as operacoes necessarias para o setUp do objeto de teste
        * \param [in] <alvo> objeto alvo de teste
        */
        void setUp(Nome);

        //!tearDown
        /*!
        * Realiza a limpeza do objeto de teste, voltando o objeto alvo ao estado original
        * \param [in] <alvo> objeto alvo de teste
        */
        void tearDown(Nome);

        //!Run
        /*!
        * inicia o teste no objeto enviado pelo parametro
        * \param [in] <alvo> objeto alvo de teste
        */
        void run(Nome);

    private:
        //!variavel para armazenar o estado do objeto alvo
        string nomeTemp;
};





#endif // NOME_H
