#include "MIU_Autenticacao.h"

#include <iostream>
#include "MRN_Autenticacao.h"
#include "Matricula.h"
#include "Senha.h"

MIU_Autenticacao::MIU_Autenticacao()
{
    MRN = NULL;
}

void MIU_Autenticacao::setMRN(MRN_Autenticacao* novoMRN){
    MRN = novoMRN;
}

int MIU_Autenticacao::run(){
    Matricula mat;
    Senha senha;
    string novaMat;
    string novaSenha;
    int permission = -1;

    while(permission == -1){
        try{
            cout << "Insira sua matricula para logar:";
            cin >> novaMat;
            mat.setMatricula(novaMat);

            cout << "Insira sua senha:";
            cin >> novaSenha;
            senha.setSenha(novaSenha);

            if(MRN){
                permission = MRN->autenticar(mat,senha);
                if(permission == -1){
                    cout << "Login ou senha invalidos" << endl << endl;
                }
            } else {
                cout << "Erro no modulo de autenticacao" << endl;
                break;
            }
        }
        catch (invalid_argument error){
            cout << error.what() << endl;
        }
        catch (runtime_error error){
            cout << error.what() << endl;
        }
    }

    // MRN.autrn
    return permission;
}
