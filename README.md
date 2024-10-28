# simulador-de-banco
Este foi um pequeno projeto feito no primeiro semestre do curso de análise e desenvolvimento de sistemas, seguindo um fluxo pré definido.

## Funcionalidades
O projeto é focado nas funcionalidades básicas encontradas em um banco, como criar uma conta (cliente ou funcionário), depositar, sacar e excluir.
Também foi feito uma entrada de dados mais "refinada", impossibilitando o usuário de digitar números nos locais de letras e vice e versa.
OBS: Não utilize caracteres com acentuação.

## Partes Técnicas
O programa foi feito 100% na linguagem C e fazendo com que os dados digitados sejam persistentes, ou seja, os dados serão guardados em um arquivo para não se perderem quando o programa for fechado.
Não foi usado a biblioteca locale para o uso de caracteres especiais do português, por conta disso, o texto no programa deve ser inserido sem acentuação.

as senhas para acessar aos locais protegidos:
Administrador: 112233
Funcionário: 12345
Cliente (para acessar o menu de gerenciamento): 54321

caso queira mudar as senhas, voce pode fazer isso na primeira linha do funcionarios.h
