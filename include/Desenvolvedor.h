#ifndef DESENVOLVEDOR_H
#define DESENVOLVEDOR_H


class Desenvolvedor
{
    public:
        Desenvolvedor();

        Nome getNome();
        void setNome(Nome) throw (invalid_argument);

        Matricula getMatricula();
        void setmatricula(Matricula) throw (invalid_argument);

        Senha getSenha();
        void setSenha(Senha) throw (invalid_argument);

        Email getEmail();
        void setEmail(Email) throw (invalid_argument);

        Funcao getFuncao();
        void setFuncao(Funcao) throw (invalid_argument);



    private:
        Nome nome;
        Matricula matricula;
        Senha senha;
        Email email;
        Funcao funcao;
};

#endif // DESENVOLVEDOR_H
