#ifndef CODIGOPROJETO_H
#define CODIGOPROJETO_H


#include <string>
#include <stdexcept>

using namespace std;

//!Codigo de Projeto
/*!
*Classe de Dominio do Codigo de projeto
*Armazena um valor no formato AAAAA, ou seja,
*cinco caracteres alfabeticos em caixa alta
*possui
*/
class CodigoProjeto
{
    public:
        //!Construtor
        /*!
        *Constroi o objeto codigo de projeto e deixa como valor padrao para codigo como 0, respeitando o formato
        */
        CodigoProjeto();

        /*get e set*/
        //!metodo para get
        /*!
        *retorna o valor armazenado em codigo. nao altera nenhum valor
        */
        string getCodigo() const;

        //!metodo para set
        /*!
        * recebe como entrada uma string referente a um codigo de projeto, valida para o formato AAAAA, e caso esteja
        * no devido formato, armazena na variavel codigo o valor da entrada. retorna invalid_argument caso a string
        * enviada nao se adeque ao formato. coloca todo os caracteres em caixa alta antes de armazenar.
        */
        void setCodigo(string) throw (invalid_argument);


    private:
        /*!armazena o valor*/
        string codigo;

        //!Verifica valor de entrada para codigo de projeto
        /*!
        * Verifica se o tamanho da string eh igual a 5, e depois verifica se eh composta apenas por
        * valores alfabeticos.
        */
        void valida(string) throw (invalid_argument);

};

//!Unidade de Teste para Codigo de Projeto
/*!
* Esta classe tem como objetivo testar a classe Codigo de Projeto,
* inserindo valores validos e invalidos e observando o resultado.
*/
class TesteCodigoProjeto {

    public:
        //!Construtor
        /*!
        *Constroi o objeto para o teste de unidade para a classe CodigoProjeto
        */
        TesteCodigoProjeto();

        //!SetUp de TesteCodigoProjeto
        /*!
        *Inicializa os parametros necessarios para se iniciar os testes
        */
        void setUp(CodigoProjeto);

        //!TearDown de TesteCodigoProjeto
        /*!
        *Realiza a limpeza necessaria para finalizar os testes
        */
        void tearDown(CodigoProjeto);

        //!Run de TesteCodigoProjeto
        /*!
        *Inicia os testes
        */
        void run(CodigoProjeto);

    private:
        //!variavel para armazenar o valor do modulo a ser testado, para nao perder o dado
        string codigoTemp;

};
#endif // CODIGOPROJETO_H
