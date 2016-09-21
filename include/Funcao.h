
#ifndef FUNCAO_H
#define FUNCAO_H

#include <stdexcept>

using namespace std;

//!Funcao do Projeto
/*!
* Esta classe armazena o valor de um funcao do projeto, variando de 0 a 4
*/
class Funcao {

    public:
    //! Construtor do Funcao
    /*!
    * Nao recebe nenhuma entrada e nem retorna saidas
    */
    Funcao();

    //!set da variavel funcao
    /*! \brief armazena o valor desejado no objeto
    * \param [in] <entrada> valor inteiro referente ao desejado
    */
    void setFuncao(int) throw(invalid_argument);

    //!get da variavel funcao
    /*! \brief retorna o valor da variavel funcao no objeto
    * \param [out] <retorno> valor de retorno referente ao funcao.
    */
    int getFuncao() const;
    private:

    //! avalia o valor
    /*!
    * Avalia o valor para as restricoes desejadas na variavel funcao
    */
    void avalia(int) throw(invalid_argument);

    //!variavel funcao
    int funcao;
};

//!Unidade de Teste para Funcao do Projeto
/*!
* Esta classe ira testar valores validos e invalidos em um objeto Funcao
*/
class TesteFuncao {
    public:
        //! Construtor do TesteFuncao
        /*!
        * Nao recebe nenhuma entrada e nem retorna saidas
        */
        TesteFuncao();

        //! setUp de TesteFuncao
        /*!
         * Realiza as atividades necessarias para iniciar o teste de unidade no
         * modulo alvo de Funcao
         * Armazena o valor do modulo, para nao alterar os valores
         * \param [in] <alvo> objeto alvo do metodo
         */
         void setUp(Funcao);

         //! tearDown de TesteFuncao
         /*!
         * Realiza as atividades necessarias para concluir o teste de unidade
         * no modulo alvo de Funcao
         * Atribui ao alvo o valor armazenado durante o setUp
         * \param [in] <alvo> objeto alvo do metodo
         */
        void tearDown(Funcao);

        //! Run de TesteFuncao
        /*!
        * inicia os testes no objeto alvo. Sera verificado se ele aceita um valor dentro
        * da faixa dinamica requerida, bem como tentara colocar valores invalidos
        * \param [in] <alvo> objeto alvo do metodo
        */
        void run(Funcao);

    private:
        //!valor temporario para uso do setUp e tearDown
        int funcaoTemp;
};
#endif // FUNCAO_H
