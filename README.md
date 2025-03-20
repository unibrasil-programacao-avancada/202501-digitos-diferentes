Projeto: Contagem de Números sem Dígitos Repetidos

Este projeto é uma solução para o problema "Dígitos Diferentes", que consiste em contar quantos números em um intervalo [N, M] não possuem dígitos repetidos. O programa lê os valores de N e M de arquivos de entrada, processa os dados e compara os resultados com arquivos de saída pré-definidos.

Como Funciona:
O programa faz o seguinte:

Lê os valores de N e M de arquivos de entrada na pasta input/.

Para cada intervalo [N, M], conta quantos números não possuem dígitos repetidos.

Compara o resultado com o valor esperado no arquivo de saída correspondente na pasta output/.

Exibe no terminal se cada teste passou (OK) ou falhou (Falhou).

Estrutura do Projeto

Copy

root/

├── warmup/

│   ├── 04-digitos-diferentes/

│   │   ├── input/                  # Pasta com arquivos de entrada

│   │   │   ├── instance_1          # Exemplo de arquivo de entrada

│   │   │   ├── instance_2

│   │   │   ├── ...

│   │   │   └── instance_ex1

│   │   ├── output/                 # Pasta com arquivos de saída

│   │   │   ├── instance_1          # Exemplo de arquivo de saída

│   │   │   ├── instance_2

│   │   │   ├── ...

│   │   │   └── instance_ex1

│   │   ├── warmup_solver.c         # Código fonte do programa

│   │   └── README.md               # Este arquivo

Requisitos

Compilador C (por exemplo, gcc).

Um ambiente de desenvolvimento (como CLion, VS Code ou qualquer editor de texto).

Arquivos de entrada e saída na estrutura correta (fornecidos no projeto).

Como Executar
Compilação
Abra o terminal na pasta do projeto.

Compile o código usando o comando:

bash
Copy
gcc warmup_solver.c -o warmup_solver
Execução
Execute o programa:

bash
Copy
./warmup_solver
O programa processará todos os arquivos de entrada na pasta input/ e exibirá os resultados no terminal.

Exemplo de Saída
Se todos os testes passarem, você verá algo como:

Copy
Teste input/instance_1: OK
Teste input/instance_2: OK
Teste input/instance_ex1: OK
...
Se algum teste falhar, a saída indicará o problema:

Copy
Teste input/instance_1: Falhou (Esperado: 72, Obtido: 70)
Personalização
Se os arquivos de entrada/saída estiverem em outro diretório, atualize as constantes INPUT_DIR e OUTPUT_DIR no código.

Adicione mais casos de teste criando novos arquivos nas pastas input/ e output/.

Contribuição
Se você quiser contribuir para o projeto, sinta-se à vontade para:

Abrir uma issue para reportar bugs ou sugerir melhorias.

Fazer um fork do projeto e enviar um pull request com suas alterações.
