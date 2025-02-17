# **Trabalho de Resgate de Astronautas**

Este trabalho consiste na criação de um programa para resgatar astronautas em uma estação espacial representada por uma matriz 2D. Cada elemento da matriz é um módulo da estação, que pode conter diferentes tipos de elementos, como astronautas, espaço vazio, obstáculos, etc. O objetivo é desenvolver um robô que percorra a matriz para resgatar astronautas, respeitando as restrições impostas por cada tipo de módulo.

O programa deve ler um arquivo de entrada com as informações da matriz e gerar um relatório de desempenho do robô ao final do resgate.

---

### **Estrutura das Classes**

O programa é composto por várias classes, cada uma responsável por uma parte específica da lógica do resgate.

---

#### **1. Módulo**

A classe `Modulo` representa cada elemento da matriz dentro da estação espacial. Ela serve como classe base para os diferentes tipos de módulos, como segurança, astronauta, obstáculo, etc. Cada tipo de módulo é identificado por um caractere que define suas propriedades, como se pode ou não ser acessado pelo robô.

---

#### **2. Astronauta**

A classe `Astronauta` armazena informações sobre os astronautas na estação. Ela é essencial para gerar a lista de astronautas presentes e indicar quais foram resgatados pelo robô.

---

#### **3. Estação Espacial**

A classe `EstacaoEspacial` é a classe central do programa, responsável pela criação da matriz que representa a estação. Ela também realiza a leitura dos arquivos de entrada.

- **Construtor**: Recebe o número de linhas e colunas da matriz. A matriz será redimensionada posteriormente com o método `resize()`.
  
- **Método `inicializarEstacao()`**: 
  1. Usa `ifstream` para ler o arquivo de entrada.
  2. Lê as dimensões da matriz (linhas e colunas) da primeira linha do arquivo.
  3. Redimensiona a matriz de acordo com os valores lidos.
  4. Lê cada caractere da linha e define o tipo de cada posição na matriz.
  5. Lê as informações dos astronautas (nome, saúde, urgência) e suas posições dentro da estação.

- **Método `mostrarEstacao()`**: Percorre a matriz, transformando cada elemento em caractere através do método `getTipo()` da classe `Modulo`, e exibe a estação formatada.

- **Método `podeAcessar()`**: Verifica se uma posição `(linha, coluna)` está dentro dos limites da matriz e chama o método `podeAcessar()` do módulo correspondente.

---

#### **4. Robô de Resgate**

A classe `RoboDeResgate` é responsável por executar o algoritmo de resgate. O robô percorre a estação espacial para resgatar os astronautas, respeitando as restrições impostas pelos módulos da estação.

- **Construtor**: Recebe a estação e a posição inicial do robô (linha e coluna). Usa os métodos `getLinhas()` e `getColunas()` da classe `EstacaoEspacial` para obter as dimensões da estação e redimensiona uma matriz chamada `visitado` com o mesmo tamanho da estação, preenchendo-a com valores `false`.

- **Método `podeMover()`**: Recebe uma nova posição `(x, y)` e retorna `true` se:
  - A posição está dentro dos limites da matriz.
  - A posição pode ser acessada de acordo com o método `podeAcessar()` da classe `EstacaoEspacial`.
  - A posição ainda não foi visitada.
  Caso algum desses critérios seja falso, o método retorna `false`, indicando que o robô não pode mover-se para essa posição.

- **Método `marcarFogo()`**: Marca como inacessíveis as áreas adjacentes aos módulos de fogo (`F`) na estação. A partir da posição do fogo, o robô percorre a matriz e define os módulos adjacentes como inacessíveis.

- **Método `percorreMatriz()`**: O algoritmo mais complexo do robô. Ele implementa um algoritmo de busca para percorrer a matriz em busca dos astronautas e resgatá-los.
  1. O robô começa adicionando seus movimentos iniciais à fila e marca as posições como visitadas.
  2. Define duas listas com os possíveis movimentos horizontais e verticais.
  3. A cada iteração, o robô remove o primeiro par de coordenadas da fila e verifica se há um astronauta na posição atual. Se houver, o astronauta é resgatado.
  4. Para cada movimento possível, o robô verifica se a nova posição pode ser acessada e, se sim, a adiciona à fila de movimentos e marca como visitada.
  5. O número de passos é incrementado a cada movimento válido.
  6. O processo continua até que a fila de movimentos esteja vazia.

---

### **Objetivos**

- **Arquivo de Entrada**: O programa deve ler um arquivo contendo a estação espacial, suas dimensões e os astronautas, para que o robô possa iniciar o resgate.
  
- **Arquivo de Saída**: O programa deve gerar um relatório com:
  - O número de passos necessários para resgatar os astronautas.
  - A lista de astronautas resgatados e os que não foram resgatados.

---

### **Conclusão**

Este programa permite simular um cenário de resgate na estação espacial, em que o robô percorre a matriz, resgata astronautas e gera um relatório detalhado sobre o desempenho da operação. As classes estão organizadas de forma a garantir a flexibilidade e a compreensão do processo de resgate.