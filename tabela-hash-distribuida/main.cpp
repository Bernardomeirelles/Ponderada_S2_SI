#include "chord.h"
#include <vector>

int main()
{
    std::vector<int> allNodes = {100, 500, 2000, 4000, 7000}; // Nós do Chord DHT

    std::vector<ChordNode> chordNodes;
    for (int id : allNodes)
    {
        chordNodes.emplace_back(id);
    }

    for (auto &node : chordNodes)
    {
        node.updateFingerTable(allNodes);
    }

    // Lista de alunos
    std::vector<Aluno> alunos = {
        Aluno(450, "Pedro"),
        Aluno(3500, "Maria"),
        Aluno(6200, "Lucas")};

    // Inserindo alunos automaticamente no nó correto
    for (Aluno aluno : alunos)
    {
        int targetNodeID = chordNodes[0].findSuccessor(aluno.getRa()); // Encontra o nó correto
        for (auto &node : chordNodes)
        {
            if (node.getNodeID() == targetNodeID) // Encontra o nó correspondente pelo ID
            {
                node.insertKey(aluno);
                break;
            }
        }
    }

    // Buscando alunos
    Aluno aluno;
    int nextNode = chordNodes[0].findSuccessor(450);
    for (auto &node : chordNodes)
    {
        if (node.getNodeID() == nextNode)
        {
            if (node.retrieveKey(450, aluno))
            {
                std::cout << "Aluno encontrado: " << aluno.getNome() << " no no " << nextNode << std::endl;
            }
            else
            {
                std::cout << "Aluno não encontrado!" << std::endl;
            }
        }
    }

    // Removendo um aluno
    /*int removeNodeID = chordNodes[0].findSuccessor(3500);
    for (auto &node : chordNodes)
    {
        if (node.getNodeID() == removeNodeID)
        {
            node.deleteKey(3500);
            break;
        }
    }*/

    // Imprimindo o estado final dos nós
    for (auto &node : chordNodes)
    {
        node.printNode();
    }

    return 0;
}
