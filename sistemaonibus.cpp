#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Passagem {
public:
    int numeroAssento;
    string dataHora;
    string CPF;
    string nome;
    int idade;

    Passagem(int assento, const string& dataHora, const string& cpf, const string& nome, int idade)
        : numeroAssento(assento), dataHora(dataHora), CPF(cpf), nome(nome), idade(idade) {}
};

class Viagem {
public:
    int numeroViagem;
    string origem;
    string destino;
    string data;
    vector<Passagem> passagens;

    Viagem(int numero, const string& origem, const string& destino, const string& data)
        : numeroViagem(numero), origem(origem), destino(destino), data(data) {}

    void venderPassagem(int assento, const string& dataHora, const string& cpf, const string& nome, int idade) {
        passagens.push_back(Passagem(assento, dataHora, cpf, nome, idade));
    }

    double calcularArrecadacao() const {
        return passagens.size() * 80.0;
    }
};

class EmpresaOnibus {
public:
    vector<Viagem> viagens;

    void criarViagem(int numero, const string& origem, const string& destino, const string& data) {
        viagens.push_back(Viagem(numero, origem, destino, data));
    }

    double calcularArrecadacaoViagem(int numeroViagem) {
        for (const Viagem& viagem : viagens) {
            if (viagem.numeroViagem == numeroViagem) {
                return viagem.calcularArrecadacao();
            }
        }
        return 0.0;
    }

    double calcularArrecadacaoMes(const string& mes) {
        double totalArrecadado = 0.0;
        for (const Viagem& viagem : viagens) {
            if (viagem.data.find(mes) != string::npos) {
                totalArrecadado += viagem.calcularArrecadacao();
            }
        }
        return totalArrecadado;
    }

    string obterNomePassageiro(int numeroViagem, int assento) {
        for (const Viagem& viagem : viagens) {
            if (viagem.numeroViagem == numeroViagem) {
                for (const Passagem& passagem : viagem.passagens) {
                    if (passagem.numeroAssento == assento) {
                        return passagem.nome;
                    }
                }
            }
        }
        return "Passageiro não encontrado";
    }

    string horarioMaisRentavel() {

        double maiorArrecadacao = 0.0;
        string horarioMaisRentavel;

        for (const Viagem& viagem : viagens) {
        double arrecadacaoViagem = viagem.calcularArrecadacao();
        if (arrecadacaoViagem > maiorArrecadacao) {
            maiorArrecadacao = arrecadacaoViagem;
            horarioMaisRentavel = viagem.data;
        }
    }

    return horarioMaisRentavel;
    }   
        return "Horário não encontrado";
}

    double mediaIdadePassageiros() {
        int totalPassageiros = 0;
        int somaIdades = 0;
        for (const Viagem& viagem : viagens) {
            for (const Passagem& passagem : viagem.passagens) {
                totalPassageiros++;
                somaIdades += passagem.idade;
            }
        }
        return totalPassageiros > 0 ? static_cast<double>(somaIdades) / totalPassageiros : 0.0;
}

int main() {
    EmpresaOnibus empresa;

    empresa.criarViagem(1, "Rio de Janeiro", "São Paulo", "2023-08-01");
    empresa.criarViagem(2, "São Paulo", "Rio de Janeiro", "2023-08-02");

    empresa.venderPassagem(1, "2023-08-01 08:00", "12345678901", "Alice", 30);
    empresa.venderPassagem(2, "2023-08-02 09:30", "98765432101", "Bob", 25);


    return 0;
}
