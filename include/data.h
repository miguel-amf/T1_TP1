#ifndef DATA_H
#define DATA_H

#include <stdexcept> //invalid_argument
#include <string> //string

using namespace std;

//!Dominio Data
/*!
* Armazena uma data no formato DD/MM/AAAA (1-31 / 1-12 / 2016-2050)
*/
class Data {

    public:
        //!Construtor
        /*!
        * Constroi o objeto
        */
        Data();
        //! get o valor data
        /*!
        * retorna uma string no formato DD/MM/AAAA
        * \param [out] <return> string contendo data
        */
        string getData();

        //! set o valor data
        /*!
        * recebe uma string contendo o valor data, valida, armazena ou retorna erro.
        * \param [in] <entrada> string com o valor desejado
        */
        void setData(string entrada) throw(invalid_argument);

    private:
        //!variavel que armazena a data
        string data;
        //!funcao que valida a data
        void avalia(string entrada) throw(invalid_argument);
};

//!Unidade de teste TesteData
/*!Testa o objeto Data quanto a validacao que ele oferece para o proprio tipo
*
*/
class TesteData {
    public:
        //!Construtor
        /*!
        *Constroi o objeto
        */
        TesteData();

        //!setUp da unidade
        /*!
         * Realiza as atividades necessarias para iniciar o teste de unidade no
         * modulo alvo de Data
         * Armazena o valor da data, para nao alterar os valores
         * \param [in] <alvo> objeto alvo do metodo
         */
         void setUp(Data);

        //!tearDown da unidade
         /*!
         * Realiza as atividades necessarias para concluir o teste de unidade
         * no modulo alvo de Data
         * Atribui ao alvo o valor armazenado durante o setUp
         * \param [in] <alvo> objeto alvo do metodo
         */
         void tearDown(Data);

        //! Run de TesteData
        /*!
        * inicia os testes no objeto alvo. Sera verificado se ele aceita um valor dentro
        * do padrao DD/MM/AAAA requerido, bem como tentara colocar valores invalidos
        * \param [in] <alvo> objeto alvo do metodo
        */
        void run(Data);

    private:

        //!valor temporario para uso do setUp e tearDown
        string dataTemp;



};
#endif // DATA_H
