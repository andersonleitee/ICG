# Atividade Prática 2 - Rasterizando Linhas

<p>A atividade proposta tem como principal objetivo realizar a implementação de algorítmos para rasterização de pontos e linhas utilizando um framework disponibilizado no <a href="https://github.com/capagot/icg/tree/master/mygl_framework">repositório</a> do professor, que simula o acesso direto à memória de vídeo. Além de rasterizar pontos e linhas a atividade também propõe que seja rasterizado um triângulo utilizando a função criada para rasterizar linhas, de modo que suas arestas sejam construídas por meio da interpolação linear das cores, o que dar um toque degradê na coloração durante toda a sua extensão. </p>

<p>Neste trabalho foi criado 5 funções, nas quais 2 são auxiliares e 3 principais respectivamente: pixelPosition(int x, int y), que calcula o deslocamento (offset) do pixel; sinal (int valor), ela serve para decidir se haverá um incremento, caso a varição da posição final e inicial for um número positivo, ou decremento  caso essa variação seja um número negativo; putPixel(int x, int y, RGBA cor), que serve para fazer a rasterização do ponto; drawLine (int x0, int y0, int x1, int y1, RGBA cor1, RGBA cor2 ), utilizada para rasterização de linhas onde nesta está o algorítimo do ponto médio, que foi o sugerido para relalizar esta atividade e por fim a drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2), utilizada para rasterizar o triângulo recebendo a posição dos 3 vérticies. Foi criado também, um bloco struct(RGBA) para definição das cores.</p>

## Rasterização de um ponto

Como mencionado, para a implementação da rasterização de um ponto foi utilizada a função:
`putPixel(int x, int y, cor RGBA)`, na qual passa como parâmetro as coordenadas X, Y e a cor do pixel de interesse (red, green, blue, alpha). 

### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_02/02_mygl_framework/prints/Pontos.png?raw=true) 
|:--:| 
| *Figura 1: Rasterização de dois pixels na tela. * |

## Rasterização de linhas

Para implementar a rasterização de linhas foi utilizada a função: `drawLine (int x0, int y0, int x1, int y1, RGBA cor1, RGBA cor2 )`. Nela, são passadas como parâmetros x0 e y0, que são as coordenadas referentes ao ponto inicial, x1 e y1 referentes ao ponto final e por fim as cores que serão usadas na rasterização da linha na qual a cor1 é referente ao primeiro ponto e a cor2 ao segundo. Nesta função é utilizado o algorítimo do ponto médio, para que a linha seja rasterizada de maneira inteligente. Além do algorítimo, nesta função foi feita a interpolação linear das cores, como sugerido. 

### Resultado


![](https://github.com/andersonleitee/ICG/blob/master/Atividade_02/02_mygl_framework/prints/LInhaa.png?raw=true) 
|:--:| 
| *Figura 2: Rasterização de linha. drawLine(0, 0, 512, 512, red, green)* |

## Rasterização de um triângulo

A função utilizada para implentar a rasterização do triângulo foi a:`drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2)`. Nela, os parâmentros são referentes aos 3 vértices do triângulo, onde x0 e y0 é primeiro vértice, x1 e y1 é o segundo e x2 e y2 é o terceiro. Essa função serve basicamente para pegar os valores dos vérticies do triânngulo, mas quem rasteriza as arestas é a função `drawLine (int x0, int y0, int x1, int y1, RGBA cor1, RGBA cor2 )` que está dentro da drawTriangle.

### Resultado



![](https://github.com/andersonleitee/ICG/blob/master/Atividade_02/02_mygl_framework/prints/trangle.png?raw=true) 
|:--:| 
| *Figura 3: Rasterização de triângulo. drawTriangle(50,450,400,250,350,450)* |

## Referências
- Com base nas aulas de rasterização do professor e <a href="https://github.com/capagot/icg/tree/master/mygl_framework"> repositório</a>disponibilizado
- <a href= "http://www.uobabylon.edu.iq/eprints/publication_2_22893_6215.pdf">Bresenham's Line Algorithm Lecture 3 / 3rd Class / 2016-2017 </a>
- <a href="https://stackoverflow.com/">Comunidade StackOverflow</a>
