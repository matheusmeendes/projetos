// SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.0; //Versão do compilador Solidity requerida

contract anac {
    uint private idade; //Variável para armazenar a idade
    address private owner; //Variável o endereço do proprietário

    event variavelAtribuida(uint idade); //Evento emitido quando a variável idade é definida

    //Modificador para restringir o acesso apenas ao proprietário
    modifier OnlyOwner() {
        require(msg.sender == owner, "Not owner"); //Verifica se o remetente é o proprietário
        _;
    }

    //Construtor que define o endereço do proprietário como o remetente da transação de criação
    constructor() {
        owner = msg.sender;
        idade = 18;
    }

    //Função para definir a idade, acessível apenas pelo proprietário
    function setIdade(uint valor) public OnlyOwner {
        idade = valor; // Define o valor da idade
        emit variavelAtribuida(idade); // Emite o evento para notificar a alteração na idade
    }

    //Função para obter a idade, acessível apenas pelo proprietário
    function getIdade() private view returns(uint) {
        return idade; // Retorna o valor da idade
    }
}
