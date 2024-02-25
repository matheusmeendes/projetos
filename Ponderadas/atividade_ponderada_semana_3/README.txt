Olá, Hayashi! Tudo bem? Os arquivos desta pasta podem ser compilados com:

$ g++ *.cpp

E a execução feita com:

$ ./a.out

## Casos de Teste

1. **Inserção de Produto**:
   - Descrição: Testa a funcionalidade de inserção de produtos na tabela hash.
   - Como Testar: Insira produtos na tabela hash usando a função `insertItem(Produto produto)`, em seguida, imprima a tabela para verificar se os produtos foram inseridos corretamente.
   - Resultado:
     ```
     0:23000, Celular
     1:50600, Lapis
     2:20090, Caneta
     3:60400, Notebook
     4:67890, Mouse
     5:12345, Caderno
     6:91234, Camera
     7:-1, 
     8:-1, 
     9:-1,
     ```

2. **Recuperação de Produto**:
   - Descrição: Testa a funcionalidade de recuperação de produtos da tabela hash.
   - Como Testar: Tente recuperar produtos da tabela hash usando a função `retrieveItem(Produto& produto, bool& found)`, em seguida, verifique se os produtos são recuperados corretamente.
   - Resultado:
     ```
     Celular -> 1
     ```

3. **Exclusão de Produto**:
   - Descrição: Testa a funcionalidade de exclusão de produtos da tabela hash.
   - Como Testar: Tente excluir produtos da tabela hash usando a função `deleteItem(Produto produto)`, em seguida, imprima a tabela para verificar se os produtos foram excluídos corretamente.
   - Resultado:
     ```
     0:-2, 
     1:50600, Lapis
     2:20090, Caneta
     3:60400, Notebook
     4:67890, Mouse
     5:12345, Caderno
     6:91234, Camera
     7:-1, 
     8:-1, 
     9:-1,
     ```

4. **Verificação de Tabela Cheia**:
   - Descrição: Testa se a tabela hash está corretamente identificando quando está cheia.
   - Como Testar: Insira produtos na tabela hash até que ela esteja cheia usando a função `insertItem(Produto produto)` e verifique se a função `isFull()` retorna true.

5. **Verificação de Tabela Vazia**:
   - Descrição: Testa se a tabela hash está corretamente identificando quando está vazia.
   - Como Testar: Insira e exclua produtos da tabela hash usando as funções `insertItem(Produto produto)` e `deleteItem(Produto produto)`, respectivamente. Em seguida, verifique se a função `getLength()` retorna 0 quando a tabela está vazia.

