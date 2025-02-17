# **TRABALHO DE RESGATE DE ASTRONAUTAS**

O trabalho consiste na criação de uma matriz 2D que representa a estação espacial. Cada elemento dessa matriz será um módulo da estação, podendo conter diferentes tipos de elementos, como astronautas, espaço vazio, obstáculos, entre outros. O objetivo é desenvolver um robô que possa percorrer essa matriz para resgatar os astronautas, respeitando as restrições impostas por cada tipo de módulo.

O programa deve ser capaz de receber um arquivo de entrada contendo as informações da matriz e, após a execução, gerar um arquivo de saída com um relatório do desempenho do robô no resgate dos astronautas.

---

### **CLASSES DO PROGRAMA**

- **Módulo**
  - Tipos de módulo: segurança, astronauta, obstáculo, vazio, fogo e normal.
- **Estação Espacial**
- **Astronauta**
- **Robô de Resgate**

---

### **EXPLICAÇÃO DE CADA CLASSE**

#### **1. Módulo**

Classe que representa cada elemento da matriz dentro da estação espacial. Também serve como classe base para os diferentes tipos de módulos, como segurança, astronauta, obstáculo, etc. Cada tipo de módulo recebe um caractere que define suas propriedades, como se pode ser acessado ou não pelo robô.

#### **2. Astronauta**

Classe que armazena informações sobre os astronautas na estação. É essencial para gerar a lista de astronautas presentes e indicar quais foram resgatados pelo robô.

#### **3. Estação Espacial**

Classe central do programa, responsável pela criação da matriz e pela leitura dos arquivos de entrada com as informações da estação.

- **Construtor:** Recebe apenas o número de linhas e colunas da matriz. O tamanho correto da matriz será ajustado posteriormente com o método `resize()`.

- **Método ****`inicializarEstacao()`**:

  1. Usa `ifstream` para ler o arquivo de entrada, cujo nome é passado como parâmetro.
  2. Lê a primeira linha do arquivo e extrai as dimensões da matriz (linhas e colunas), separadas por vírgula.
  3. Redimensiona a matriz de acordo com os valores lidos.
  4. Lê cada caractere da linha e define o tipo de cada posição na matriz.
  5. Em seguida, lê as informações dos astronautas (nome, saúde e urgência), bem como suas posições dentro da estação.

- **Método ****`mostrarEstacao()`**: Percorre a matriz, transformando cada elemento em caractere através do método `getTipo()` da classe `Modulo`, e exibe a estação formatada.

- **Método ****`podeAcessar()`**: Verifica se uma posição `(linha, coluna)` está dentro dos limites da matriz e chama o método `podeAcessar()` do módulo correspondente.

---

Os métodos que faltam das classes são intuitivos e seguem a lógica de manipulação da matriz e gestão dos astronautas na estação espacial.

