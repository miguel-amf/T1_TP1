
#ifndef FASEPROJETO_H
#define FASEPROJETO_H

#include <stdexcept>

using namespace std;

//!Fase do Projeto
/*!
* Esta classe armazena o valor de um fase do projeto, variando de 0 a 4
*/
class FaseProjeto {

    public:
    //! Construtor do FaseProjeto
    /*!
    * Nao recebe nenhuma entrada e nem retorna saidas
    */
    FaseProjeto();

    //!set da variavel fase
    /*! \brief armazena o valor desejado no objeto
    * \param [in] <entrada> valor inteiro referente ao desejado
    */
    void setFase(int) throw(invalid_argument);

    //!get da variavel fase
    /*! \brief retorna o valor da variavel fase no objeto
    * \param [out] <retorno> valor de retorno referente ao fase.
    */
    int getFase() const;
    private:

    //! avalia o valor
    /*!
    * Avalia o valor para as restricoes desejadas na variavel fase
    */
    void avalia(int) throw(invalid_argument);

    //!variavel fase
    int fase;
};

//!Unidade de Teste para Fase do Projeto
/*!
* Esta classe ira testar valores validos e invalidos em um objeto FaseProjeto
*/
class TesteFaseProjeto {
    public:
        //! Construtor do TesteFaseProjeto
        /*!
        * Nao recebe nenhuma entrada e nem retorna saidas
        */
        TesteFaseProjeto();

        //! setUp de TesteFaseProjeto
        /*!
         * Realiza as atividades necessarias para iniciar o teste de unidade no
         * modulo alvo de FaseProjeto
         * Armazena o valor do modulo, para nao alterar os valores
         * \param [in] <alvo> objeto alvo do metodo
         */
         void setUp(FaseProjeto);

         //! tearDown de TesteFaseProjeto
         /*!
         * Realiza as atividades necessarias para concluir o teste de unidade
         * no modulo alvo de FaseProjeto
         * Atribui ao alvo o valor armazenado durante o setUp
         * \param [in] <alvo> objeto alvo do metodo
         */
        void tearDown(FaseProjeto);

        //! Run de TesteFaseProjeto
        /*!
        * inicia os testes no objeto alvo. Sera verificado se ele aceita um valor dentro
        * da faixa dinamica requerida, bem como tentara colocar valores invalidos
        * \param [in] <alvo> objeto alvo do metodo
        */
        void run(FaseProjeto);

    private:
        //!valor temporario para uso do setUp e tearDown
        int faseTemp;
};
#endif // FASEPROJETO_H
