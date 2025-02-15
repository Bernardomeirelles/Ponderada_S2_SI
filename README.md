# Ponderada Semana 2

Esta documentação descreve os testes implementados no arquivo `test_chord.cpp` para validar as principais funcionalidades da implementação do Chord DHT.

---

## Sumário

1. [Objetivo dos Testes](#objetivo-dos-testes)
2. [Estrutura do Arquivo de Teste](#estrutura-do-arquivo-de-teste)
3. [Descrição dos Testes](#descrição-dos-testes)
   - [Teste 1: Inserção e Recuperação](#teste-1-inserção-e-recuperação)
   - [Teste 2: Busca por Chave Inexistente](#teste-2-busca-por-chave-inexistente)
   - [Teste 3: Remoção de Aluno](#teste-3-remoção-de-aluno)
   - [Teste 4: Tabela de Roteamento](#teste-4-tabela-de-roteamento)
4. [Compilação e Execução](#compilação-e-execução)
5. [Exemplo de Saída](#exemplo-de-saída)

---

## Objetivo dos Testes

Os testes têm como objetivo garantir que:

- A inserção e recuperação de um aluno funcionem corretamente.
- Uma busca por uma chave inexistente retorne o resultado esperado.
- A remoção de um aluno seja realizada com sucesso.
- A tabela de roteamento (finger table) esteja configurada corretamente e retorne o sucessor esperado.

---

## Estrutura do Arquivo de Teste

O arquivo `test_chord.cpp` contém as seguintes funções:

- `testarInsercaoRecuperacao()`
- `testarChaveInexistente()`
- `testarRemocao()`
- `testarTabelaDeRoteamento()`
- `main()`

Cada função realiza um conjunto de operações no sistema Chord e imprime o resultado do teste.

---

## Descrição dos Testes

### Teste 1: Inserção e Recuperação ( 2 em 1 )

**Função:** `testarInsercaoRecuperacao()`

**Procedimento:**
- Um nó do Chord é criado com ID `1`.
- Um aluno com RA `450` e nome `"João"` é criado.
- O aluno é inserido no nó usando `insertKey`.
- O aluno é recuperado com `retrieveKey` utilizando o RA `450`.

**Mensagem Esperada:**

Teste de inserção e recuperação: PASSOU


**Significado:**
- **PASSOU:** O aluno foi inserido e recuperado com sucesso.
- **FALHOU:** Indicaria que a recuperação não ocorreu conforme esperado.

---

### Teste 2: Busca por Chave Inexistente

**Função:** `testarChaveInexistente()`

**Procedimento:**
- Um nó do Chord é criado com ID `1`.
- Uma tentativa de recuperar um aluno é feita usando uma chave inexistente (`9999`).

**Mensagem Esperada:**
Teste de chave inexistente: PASSOU


**Significado:**
- **PASSOU:** Nenhum aluno foi encontrado, conforme o esperado.
- **FALHOU:** Se um aluno fosse retornado erroneamente.

---

### Teste 3: Remoção de Aluno

**Função:** `testarRemocao()`

**Procedimento:**
- Um nó do Chord é criado com ID `1`.
- Um aluno com RA `3500` e nome `"Maria"` é inserido no nó.
- O aluno é removido com `deleteKey` utilizando a chave `3500`.
- É feita uma tentativa de recuperar o aluno removido.

**Mensagem Esperada:**

Teste de remoção: PASSOU

**Significado:**
- **PASSOU:** O aluno foi removido corretamente e não foi encontrado na recuperação.
- **FALHOU:** Se o aluno ainda fosse encontrado após a remoção.

---

### Teste 4: Tabela de Roteamento

**Função:** `testarTabelaDeRoteamento()`

**Procedimento:**
- Um vetor de IDs de nós `{1, 2, 3, 4, 5}` é definido.
- Um nó do Chord com ID `2` é criado.
- A finger table do nó é atualizada com a lista de nós usando `updateFingerTable`.
- O método `findSuccessor` é utilizado para encontrar o sucessor para a chave `no.getNodeID() + 1` (neste caso, `3`).

**Mensagem Esperada:**
Teste de tabela de roteamento: Sucessor encontrado: 3


**Significado:**
- O teste confirma que a tabela de roteamento foi configurada corretamente, retornando o sucessor esperado (nó com ID `3`).

---

## Compilação e Execução

Para compilar os testes, certifique-se de que os arquivos `chord.cpp`, `aluno.cpp` e `test_chord.cpp` estejam no mesmo diretório. Use o comando:

```bash
g++ -o testes test_chord.cpp chord.cpp aluno.cpp -std=c++11

```

## Output Esperado

Aluno João armazenado no nó 1.  
Verificação de recuperação do aluno: SUCESSO.  

Tentativa de recuperação de RA 9999: Chave não encontrada (OK).  

Aluno Maria armazenado no nó 1.  
Aluno com RA 3500 removido do nó 1.  
Verificação de remoção: SUCESSO.  

Tabela de roteamento configurada.  
Sucessor esperado para a chave 3: Nó 3.  

Todos os testes foram executados com sucesso.

