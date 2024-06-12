#include <iostream>
#include <locale.h>
#include <conio.h>
#include <string.h>
using namespace std;

///STRUCTS
struct Cidades{
int idCidade;
char nome[50];
string UF;
};

struct EspecialidadesMedicas{
int idEspecialidade;
char descricao[80];
};

struct Medicos{
int idMedicos;
char nome[50];
EspecialidadesMedicas especialidade;
char endereco[50];
char telefone[50];
Cidades cidade;
};

struct Pacientes{
int cpf;
char nome[50];
char endereco[50];
Cidades Cidade;
};

struct CID{
int idCID;
char descricao[80];
};

struct Medicamentos{
int idMedicamentos;
char descricao[80];
int quantEstoque, estoqueMinimo, estoqueMaximo;
float preco_unitario;
};

struct Consultas{
int idConsulta;
Pacientes cpfPaciente;
Medicos idMedico;
int dia;
int mes;
int ano;
int hora;
int minutos;
CID idCID;
Medicamentos idMedicamento;
int quantMedicamento;
};

///FUNÇÕES
void LerCidade(Cidades DadoCidade[], int &contCidade, string conf){

    while(conf=="s" || conf=="S"){
        cout << "Informe os dados da sua cidade" << endl;
        cout << "Id: ";
        cin >> DadoCidade[contCidade].idCidade;
        cout << "Nome: ";
        cin >> DadoCidade[contCidade].nome;
        cout << "UF: ";
        cin >> DadoCidade[contCidade].UF;
        cout << endl;
        contCidade++;

        cout << "\nDeseja inserir mais uma cidade? [S/N]: ";
        cin >> conf;
    }
}

void LerEspecialidades(EspecialidadesMedicas especialidades[], int &contEspe, string conf){
    while(conf == "s" || conf == "S"){
        cout << "Informe os dados das suas Especialidades Medicas" << endl;
        cout << "Id: ";
        cin >> especialidades[contEspe].idEspecialidade;
        cout << "Descrição da especialidade: ";
        cin >> especialidades[contEspe].descricao;
        cout << endl;
        contEspe++;

        cout << "Deseja inserir mais uma especialidade? [S/N]: ";
        cin >> conf;
    }


}

void LerCID(CID cid[], int &contCID, string conf){
    while(conf=="s" || conf=="S"){
        cout << "Informe os dados do CID" << endl;
        cout << "Id: ";
        cin >> cid[contCID].idCID;
        cout << "Descrição: ";
        cin >> cid[contCID].descricao;

        contCID++;

        cout << "\nDeseja inserir mais uma CID? [S/N]: ";
        cin >> conf;
    }
}

void LerMedicamentos(Medicamentos medicamentos[], int &contME, string conf){
    while(conf=="s" || conf == "S"){
        cout << "Informe os dados dos Medicamentos" << endl;
        cout << "Id: ";
        cin >> medicamentos[contME].idMedicamentos;
        cout << "Descrição do Medicamento: ";
        cin >> medicamentos[contME].descricao;
        cout << "Quantidade em estoque: ";
        cin >> medicamentos[contME].quantEstoque;
        cout << "Estoque minimo: ";
        cin >> medicamentos[contME].estoqueMinimo;
        cout << "Estoque maximo: ";
        cin >> medicamentos[contME].estoqueMaximo;
        cout << "Preço por Unidade: ";
        cin >> medicamentos[contME].preco_unitario;

        contME++;

        cout << "\nDeseja inserir mais um Medicamento? [S/N]: ";
        cin >> conf;
    }
}

void MostrarMedico(Medicos medicos[], int &contM){ //SÓ SERVER PARA TESTE
    if(medicos[0].idMedicos == 1){
        cout << "\n\nMostrar Tabela Medico Atualizada\n";
        for(int i=0; i<contM; i++){
            cout << "Id: " << medicos[i].idMedicos << endl;
            cout << "Nome: " << medicos[i].nome << endl;
            cout << "Id Especialidade: " << medicos[i].especialidade.idEspecialidade << endl;
            cout << "Endereço: " << medicos[i].endereco << endl;
            cout << "Telefone: " << medicos[i].telefone << endl;
            cout << "Id Cidade: " << medicos[i].cidade.idCidade << endl;
            cout << endl;
        }

    }else{cout << "Não pussiu nenhum medico ainda.\n\n";}
}

void InclusaoMedicos(Medicos medicos[], EspecialidadesMedicas especialidades[], Cidades cidade[], int &contM, string conf){//ESTÁ FUNFANDO
        Medicos Trans[1];
        int v=0; ///para verificação do id
        int contT=0;

        cout << "\nInclusão de Medicos\n";

        while(conf == "s" || conf == "S" && contM == 4 ){
            cout << "Informe os Dados:\n";
            cout << "Id: ";
            cin >> Trans[contT].idMedicos;
            ///INTEROMPER OPERAÇÃO CASO HAJA ID IGUAL
                    for(int i=0; i<contM ;i++){
                        if(Trans[contT].idMedicos == medicos[i].idMedicos){
                            cout << "Esse ID já existe na tabela!!\n\n";
                            v++;
                            break;
                        }
                    }if(v > 0){
                        v=0;
                        break;
                    }

            cout << "Nome: ";
            cin >> Trans[contT].nome;
            cout << "Id Especialidade: ";
            cin >> Trans[contT].especialidade.idEspecialidade;
            ///BUSCAR ESPECIALIDADE
              for(int i=0;i<5;i++){
                if(Trans[contT].especialidade.idEspecialidade == especialidades[i].idEspecialidade){
                    Trans[contT].especialidade = especialidades[i];
                    cout << "Nome: " << especialidades[i].descricao << endl;
                    i=5;}
              }
            cout << "Endereço: ";
            cin >> Trans[contT].endereco;
            cout << "Telefone: ";
            cin >> Trans[contT].telefone;
            cout << "Id Cidade: ";
            cin >> Trans[contT].cidade.idCidade;
            ///BUSCAR CIDADE
            for(int i=0;i<5;i++){
                if(Trans[contT].cidade.idCidade == cidade[i].idCidade){
                    cout << "Nome: " << cidade[i].nome << endl;
                    cout << "UF: " << cidade[i].UF << endl;
                    i=5;}
              }

            medicos[contM] = Trans[contT];
            contM++;


            cout << "Deseja inserir mais algum Medico ? [S/N] ";
            cin >> conf;
            cout << endl;

        }
}

void InclusaoPacientes(Pacientes pacientes[], Cidades cidade[], int &contP, string conf){
    Pacientes Trans[1];
    int v=0;
    int contT=0;

    cout << "\nInclusão de pacientes\n";
    while(conf == "s" || conf == "S" && contP == 4 ){
        cout << "CPF: ";
        cin >> Trans[contT].cpf;
        ///INTEROMPER OPERAÇÃO CASO HAJA CPF IGUAL
           for(int i=0; i<contP ;i++){
                if(Trans[contT].cpf == pacientes[i].cpf){
                  cout << "Esse CPF já existe na tabela!!\n\n";
                  v = 1;
                  break;
                }
           }if(v > 0){
                 v=0;
                 break;
                }

        cout << "Nome: ";
        cin >> Trans[contT].nome;
        cout << "Endereço: ";
        cin >> Trans[contT].endereco;
        cout << "Id Cidade: ";
        cin >> Trans[contT].Cidade.idCidade;
            ///BUSCAR CIDADE
            for(int i=0;i<5;i++){
                if(Trans[contT].Cidade.idCidade == cidade[i].idCidade){
                    Trans[contT].Cidade = cidade[i];
                    cout << "Nome: " << Trans[contT].Cidade.nome << endl;
                    cout << "UF: " << Trans[contT].Cidade.UF << endl;
                    i=5;}
              }
        cout << endl;

        pacientes[contP] = Trans[contT];
        contP++;

        cout << "Deseja inserir mais algum Paciente ? [S/N] ";
            cin >> conf;
            cout << endl;
    }

}

void ExclusaoPacientes(Pacientes pacientes[], int &contP, string conf){
    int num;
    int posicao;

    if(contP != 0){
        while(conf == "s" || conf == "S"){
        cout << "\nTABELA PACIENTE\n";
            for(int i=0; i<contP; i++){
                    cout << "CPF: " << pacientes[i].cpf << endl;
                    cout << "Nome: " << pacientes[i].nome << endl;
                    cout << "Endereço: " << pacientes[i].endereco << endl;
                    cout << "Id Cidade: " << pacientes[i].Cidade.idCidade << endl;
                    cout << endl;
                }
            cout << "Qual paciente Deseja exluir ? CPF:";
            cin >> num;
            for(int i=0; i<contP ;i++){
                if(pacientes[i].cpf == num){
                   cout << "Esse Paciente foi excluido da tabela!!\n";
                   contP = contP - 1;
                   posicao = i;
                   break;
                        }else if(num != pacientes[posicao].cpf){
                            cout << "TÁ CEGO?!, não tem ninguém com esse cpf";
                            }
                   }
                 cout << "\nDeseja Excluir mais alguém? [S/N]:";
                 cin >> conf;

            }
    }else if(contP == 0){
        cout << "\nNão possui nenhum paciente!\n";
    }



}

void InclusaoConsulta(Consultas consultas[], double &ValorConsulta, Pacientes pacientes[], Cidades cidade[], Medicos medicos[], CID cid[], Medicamentos medicamentos[], int &contC, string conf){
Consultas Trans[1];
int contT, valMedicamento, posicaoMedicamento=0;

        cout << "\nInforme os dados da Consulta\n";
        while(conf == "S" || conf == "s"){
             cout << "Id: ";
            cin >> Trans[contT].idConsulta;

            cout << "CPF do Paciente: ";
            cin >> Trans[contT].cpfPaciente.cpf;
            ///BUSCAR CPF E CIDADE
            for(int j=0;j<6;j++){
                if(Trans[contT].cpfPaciente.cpf == pacientes[j].cpf){
                    cout << "Paciente: " << pacientes[j].nome << endl;
                    cout << "Cidade: " << pacientes[j].Cidade.nome << endl;
                    cout << "UF: " << pacientes[j].Cidade.UF << endl;
                }
            }

            cout << "Id do Medico: ";
            cin >> Trans[contT].idMedico.idMedicos;
            ///BUSCAR MEDICO
            for(int i=0;i<6;i++){
                if(Trans[contT].idMedico.idMedicos == medicos[i].idMedicos){
                    cout << "Nome: " << medicos[i].nome << endl;
                    cout << "Especialidade: " << medicos[i].especialidade.descricao << endl;
                    i=6;}
              }
            cout << "Informe a Data da consulta:\n";
            cout << "Dia: ";
            cin >> Trans[contT].dia;
            cout << "Mes: ";
            cin >> Trans[contT].mes;
            cout << "Ano: ";
            cin >> Trans[contT].ano;
            cout << "Informe o Horário da consulta:\n";
            cout << "Hora: ";
            cin >> Trans[contT].hora;
            cout << "Minutos: ";
            cin >> Trans[contT].minutos;
            cout << "Id CID: ";
            cin >> Trans[contT].idCID.idCID;
            ///BUSCAR CID
            for(int i=0;i<6;i++){
                if(Trans[contT].idCID.idCID == cid[i].idCID){
                    cout << "Descrição: " << cid[i].descricao << endl;
                    i=6;}
              }
            cout << "Id Medicamento: ";
            cin >> Trans[contT].idMedicamento.idMedicamentos;
            ///BUSCAR MEDICAMENTOS
            for(int i=0;i<6;i++){
                if(Trans[contT].idMedicamento.idMedicamentos == medicamentos[i].idMedicamentos){
                    cout << "Descrição do Medicamento: " << medicamentos[i].descricao << endl;
                    valMedicamento = medicamentos[i].idMedicamentos;
                    posicaoMedicamento = i;
                    i=6;}
              }
            cout << "Informe a quantidade de Medicamento: ";
            cin >> Trans[contT].quantMedicamento;
            ///BUSCAR QUANTIDADE MEDICAMENTOS
                bool passou = true;
                while(passou == true){
                    if(Trans[contT].quantMedicamento > medicamentos[posicaoMedicamento].quantEstoque){
                        cout << "não tem essa quantidade no estoque no momento!\n";
                        cout << "\nInforme a quantidade de Medicamento: ";
                        cin >> Trans[contT].quantMedicamento;
                    }
                        if(medicamentos[posicaoMedicamento].quantEstoque >= Trans[contT].quantMedicamento){
                            cout << "Tem estoque suficiente!\n";
                            ValorConsulta += 100 + medicamentos[posicaoMedicamento].preco_unitario * Trans[contT].quantMedicamento;
                            medicamentos[posicaoMedicamento].quantEstoque = medicamentos[posicaoMedicamento].quantEstoque - Trans[contT].quantMedicamento;
                            passou = false;
                        }
                }

            consultas[contC] = Trans[contT];
            contC++;

            cout << "Deseja inserir mais algum Paciente ? [S/N] ";
            cin >> conf;
            cout << endl;

        }


}

void ConsultarMedicamento(Medicamentos medicamentos[], int &contME, string conf){
string Medicamento;
double ValorTotal =0;


    cout << "\nMedicamentos\n";
    while(conf == "S" || conf == "s"){
        for(int j=0;j<contME;j++){
            cout << "-" << medicamentos[j].descricao << endl;
        }
        cout << "Qual Medicamento deseja consultar ?";
        cout << " R: ";
        cin >> Medicamento;
        for(int i=0;i<6;i++){
            if(Medicamento == medicamentos[i].descricao){
            cout << "Id: " << medicamentos[i].idMedicamentos << endl;
            cout << "Descrição: " << medicamentos[i].descricao << endl;
            cout << "Quantidade em estoque: " << medicamentos[i].quantEstoque << endl;
            cout << "Estoque minimo: " << medicamentos[i].estoqueMinimo << endl;
            cout << "Estoque maximo: " << medicamentos[i].estoqueMaximo << endl;
            cout << "Preço: " << medicamentos[i].preco_unitario << endl;
            ValorTotal = medicamentos[i].quantEstoque * medicamentos[i].preco_unitario;
            cout << "Valor total em estoque: " << ValorTotal << endl;
            cout << endl;

            }
        }

        cout << "Deseja Consultar mais algum Medicamento ? [R\N]: ";
        cin >> conf;

    }


}

void RegistroMedicamento(Medicamentos medicamentos[], int &contME){
double quantComprada, valorCompra=0;

    cout << "\nRegistro de Medicamentos\n";
        for(int i=0;i<contME;i++){
            if(medicamentos[i].quantEstoque < medicamentos[i].estoqueMinimo){
                cout << "Id: " << medicamentos[i].idMedicamentos << endl;
                cout << "Descrição: " << medicamentos[i].descricao << endl;
                cout << "Quantidade no estoque: " << medicamentos[i].quantEstoque << endl;
                cout << "Estoque maximo: " << medicamentos[i].estoqueMaximo << endl;
                quantComprada = medicamentos[i].estoqueMaximo - medicamentos[i].quantEstoque;
                valorCompra = quantComprada * medicamentos[i].preco_unitario;
                cout << "Quantidade a ser comprada: " << quantComprada << endl;
                cout << "Valor Total da compra: " << valorCompra << endl;
                cout << endl;
            }
        }


}

void totalArrecadado(Consultas consultas[], double &ValorConsulta, int &contC){
    cout << "\nValor Total das Consultas: " << ValorConsulta << endl;
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil" );
    string conf = "s";
    int contM =0;
    int contP =0;
    int contC =0;
    int contME=2;
    int contCID=2;
    int contEspe=2;
    int contCidade=2;
    double ValorConsulta=0;
    bool ativo = true; ///INICAR MENU

    Cidades cidade[4]{1, "São Paulo", "SP", 2, "Candido Mota", "SP"};
    EspecialidadesMedicas especialidades[4]{1, "Cardiologista", 2, "Odontologia"};
    CID cid[4]{1, "A00", 2, "A09"};
    Medicamentos medicamentos[4]{1, "Dipirona", 12, 5, 20, 1.50, 2, "Ceftriaxona", 7, 5, 20, 20};
    Medicos medicos[10];
    Pacientes pacientes[10];
    Consultas consultas[10];


    ///MENU
    while(ativo == true){
        int num;
    cout << "|---------------------------------------------------------|\n";
    cout << "|              Gerenciamento de Hospital                  |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << "|                     Serviços                            |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << "| 1-Inserir Cidade                                        |\n";
    cout << "| 2-Inserir Especialidades Medicas                        |\n";
    cout << "| 3-Inserir CID                                           |\n";
    cout << "| 4-Inserir Medicamentos                                  |\n";
    cout << "| 5-Incluir Medicos                                       |\n";
    cout << "| 6-Mostrar Tabela Medicos Atualizada(TESTE)              |\n";
    cout << "| 7-Incluir Paciente                                      |\n";
    cout << "| 8-Exluir Paciente                                       |\n";
    cout << "| 9-Agendar consulta                                      |\n";
    cout << "| 10-Consultar Medicamento                                |\n";
    cout << "| 11-Registro de Medicamentos                             |\n";
    cout << "| 12-Valor da Consulta                                    |\n";
    cout << "| 13-Sair                                                 |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << "|Qual serviço você deseja? R: ";
    cin >> num;
    cout << "|---------------------------------------------------------|\n";
    switch(num){
    case 1:
        LerCidade(cidade, contCidade, conf);
        break;
    case 2:
        LerEspecialidades(especialidades, contEspe, conf);
        break;
    case 3:
        LerCID(cid, contCID, conf);
        break;
    case 4:
        LerMedicamentos(medicamentos, contME, conf);
        break;
    case 5:
        InclusaoMedicos(medicos, especialidades, cidade, contM, conf);
        break;
    case 6:
        MostrarMedico(medicos, contM);
        break;
    case 7:
        InclusaoPacientes(pacientes, cidade, contP, conf);
        break;
    case 8:
        ExclusaoPacientes(pacientes, contP, conf);
        break;
    case 9:
        InclusaoConsulta(consultas, ValorConsulta, pacientes, cidade, medicos, cid, medicamentos, contC, conf);
        break;
    case 10:
        ConsultarMedicamento(medicamentos, contME, conf);
        break;
    case 11:
        RegistroMedicamento(medicamentos, contME);
        break;
    case 12:
        totalArrecadado(consultas, ValorConsulta, contC);
        break;
    case 13:
        ativo = false;
        break;
    }

    }
    return 0;
}
