#include <iostream>
#include "chord.h"

void testarInsercaoRecuperacao() {
    ChordNode node(1);
    Aluno aluno(450, "João");

    node.insertKey(aluno);

    Aluno alunoEncontrado;
    bool encontrado = node.retrieveKey(450, alunoEncontrado);

    std::cout << "Teste de inserção e recuperação: " 
              << (encontrado ? "PASSOU" : "FALHOU") << std::endl;
}

void testarChaveInexistente() {
    ChordNode node(1);
    Aluno alunoEncontrado;
    bool encontrado = node.retrieveKey(9999, alunoEncontrado);

    std::cout << "Teste de chave inexistente: " 
              << (!encontrado ? "PASSOU" : "FALHOU") << std::endl;
}

void testarRemocao() {
    ChordNode node(1);
    Aluno aluno(3500, "Maria");

    node.insertKey(aluno);
    node.deleteKey(3500);

    Aluno alunoEncontrado;
    bool encontrado = node.retrieveKey(3500, alunoEncontrado);

    std::cout << "Teste de remoção: " 
              << (!encontrado ? "PASSOU" : "FALHOU") << std::endl;
}

void testarTabelaDeRoteamento() {
    std::vector<int> todosOsNos = {1, 2, 3, 4, 5};
    ChordNode no(2);
    no.updateFingerTable(todosOsNos);

    int sucessor = no.findSuccessor(no.getNodeID() + 1);
    std::cout << "Teste de tabela de roteamento: Sucessor encontrado: " << sucessor << std::endl;
}

int main() {
    testarInsercaoRecuperacao();
    testarChaveInexistente();
    testarRemocao();
    testarTabelaDeRoteamento();

    std::cout << "Todos os testes foram executados." << std::endl;
    return 0;
}
