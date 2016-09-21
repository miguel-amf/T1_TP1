#ifndef ESTADOPROJETO_H
#define ESTADOPROJETO_H

#include <stdexcept>

using namespace std;

//!Estado do Projeto
/*!
* Esta classe armazena o valor de um estado do projeto, variando de 0 a 4
*/
class EstadoProjeto {

    public:
    //! Construtor do EstadoProjeto
    /*!
    * Nao recebe nenhuma entrada e nem retorna saidas
    */
    EstadoProjeto();

    //!set da variavel estado
    /*! \brief armazena o valor desejado no objeto
    * \param [in] <entrada> valor inteiro referente ao desejado
    */
    void setEstado(int) throw(invalid_argument);

    //!get da variavel estado
    /*! \brief retorna o valor da variavel estado no objeto
    * \param [out] <retorno> valor de retorno referente ao estado.
    */
    int getEstado() const;
    private:

    //! avalia o valor
    /*!
    * Avalia o valor para as restricoes desejadas na variavel estado
    */
    void avalia(int) throw(invalid_argument);

    //!variavel estado
    int estado;
};

//!Unidade de Teste para Estado do Projeto
/*!
* Esta classe ira testar valores validos e invalidos em um objeto EstadoProjeto
*/
class TesteEstadoProjeto {
    public:
        //! Construtor do TesteEstadoProjeto
        /*!
        * Nao recebe nenhuma entrada e nem retorna saidas
        */
        TesteEstadoProjeto();

        //! setUp de TesteEstadoProjeto
        /*!
         * Realiza as atividades necessarias para iniciar o teste de unidade no
         * modulo alvo de EstadoProjeto
         * Armazena o valor do modulo, para nao alterar os valores
         * \param [in] <alvo> objeto alvo do metodo
         */
         void setUp(EstadoProjeto);

         //! tearDown de TesteEstadoProjeto
         /*!
         * Realiza as atividades necessarias para concluir o teste de unidade
         * no modulo alvo de EstadoProjeto
         * Atribui ao alvo o valor armazenado durante o setUp
         * \param [in] <alvo> objeto alvo do metodo
         */
        void tearDown(EstadoProjeto);

        //! Run de TesteEstadoProjeto
        /*!
        * inicia os testes no objeto alvo. Sera verificado se ele aceita um valor dentro
        * da faixa dinamica requerida, bem como tentara colocar valores invalidos
        * \param [in] <alvo> objeto alvo do metodo
        */
        void run(EstadoProjeto);

    private:
        //!valor temporario para uso do setUp e tearDown
        int estadoTemp;
};
#endif // ESTADOPROJETO_H
