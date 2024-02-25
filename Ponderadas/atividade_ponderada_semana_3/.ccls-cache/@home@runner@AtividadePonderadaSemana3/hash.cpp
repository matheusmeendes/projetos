#include <iostream>
#include "hash.h" //Inclui o arquivo de cabeçalho da classe Hash

using namespace std;

int main() {
    //Cria um objeto da classe Hash com capacidade para 10 itens
    Hash produtosHash(10);

    //Arrays de preços e nomes de produtos
    int precos[7] = {23000, 12345, 50600, 20090, 60400, 67890, 91234};
    string produtos[7] = {"Celular", "Caderno", "Lapis", "Caneta", "Notebook", "Mouse", "Camera"};

    //Insere os produtos na tabela hash
    for (int i = 0; i < 7; i++) {
        Produto produto = Produto(precos[i], produtos[i]); // Cria um objeto da classe Produto
        produtosHash.insertItem(produto); // Insere o produto na tabela hash
    }

    //Imprime a tabela hash
    produtosHash.print();  
    cout << "------------------------------" <<  endl;

    //Tenta recuperar um produto da tabela hash
    Produto produto(23000, "");  
    bool found = false;
    produtosHash.retrieveItem(produto, found);
    cout << produto.getProduto() << " -> " << found << endl;

    cout << "------------------------------" <<  endl;

    //Deleta um produto da tabela hash
    produtosHash.deleteItem(produto);
    produtosHash.print();
    cout << "Fim" << endl;  

    return 0;
}
