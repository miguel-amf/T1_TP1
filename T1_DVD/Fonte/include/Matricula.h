#ifndef MATRICULA_H
#define MATRICULA_H

#include <stdexcept>
#include <string>

using namespace std;


class Matricula
{
    public:

        Matricula();
        string getMatricula();
        void setMatricula(string) throw(invalid_argument);

    private:

        string matricula;

        void avalia(string) throw(invalid_argument);

};

class TesteMatricula {

    public:
        //!Construtor
        /*!
        *Constroi o objeto para o teste de unidade para a classe Matricula
        */
        TesteMatricula();

        //!SetUp de TesteMatricula
        /*!
        *Inicializa os parametros necessarios para se iniciar os testes
        */
        void setUp(Matricula);

        //!TearDown de TesteMatricula
        /*!
        *Realiza a limpeza necessaria para finalizar os testes
        */
        void tearDown(Matricula);

        //!Run de TesteMatricula
        /*!
        *Inicia os testes
        */
        void run(Matricula);

    private:
        //!variavel para armazenar o valor do modulo a ser testado, para nao perder o dado
        string matriculaTemp;

};
#endif // MATRICULA_H
