# Atividade Prática 2 - Rasterizando Linhas

<p>A atividade proposta tem como principal objetivo realizar a implementação de algorítmos para rasterização de pontos e linhas utilizando um framework disponibilizado no [repositório](https://github.com/capagot/icg/tree/master/02_mygl_framework) do professor, que simula o caesso direto à memória de vídeo. tinha como principal objetivo, verificar se as instalações, dependências e bibliotecas do OpenGL estavam funcionando devidamente. O trabalho consistiu em compilar um programa disponibilizado no repositório GitHub (https://github.com/capagot/icg/tree/master/01_hello_world_gl/modern_opengl). Foi necessário fazer um clone do projeto para a máquina local, baixar e instalar as bibliotecas, realizar um make para criar um arquivo executável visto que havia um arquivo makefile no projeto e em seguida executá-lo.</p>

<p>A estratégia que foi seguida para realizar essa atividade teve como base os erros que estavam ocorrendo no momento de compilar o projeto no SO Windows. Após a aula síncrona do dia 30/09 (quarta-feira), foi deliberado maneiras de tentar solucionar os erros de compilação que estavam ocorrendo no Windows os quais estavam impossibilitando a execução do projeto. Visto o insucesso na realização do trabalho mesmo com os conselhos, vídeos tutoriais e documentações, foi decidido usar o SO Linux para compilar o projeto, o qual foi possível obter êxito logo na primeira tentativa após as devidas instalações. As bibliotecas que foram instaladas na máquina foram a libglu1-mesa, freeglut3 e também o pacote mesa-common, conforme web tutorial (Figura 1).</p>

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_01/modern_opengl/prints/Figura%201.jpeg?raw=true ) 
|:--:| 
| *Figura 1: Web tutorial.* |

<p>Posteriormente à migração do sistema operacional, foi dado início ao walkthrough para compilar o projeto. Após realizar o comando make surgiram alguns warnings no terminal de comando (Figura 2), entretanto foi criado um arquivo executável na mesma pasta (Figura 3). Em seguida, foi realizado o comando ./moderngl_hello_world para executar o arquivo que por fim resultou-se como o esperado e uma janela com um triângulo colorido apareceu (Figura 4). </p>

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_01/modern_opengl/prints/Figura%202.jpeg?raw=true) 
|:--:| 
| *Figura 2: Warnings no terminal.* |

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_01/modern_opengl/prints/Figura%203.jpeg?raw=true) 
|:--:| 
| *Figura 3: Executável.* |

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_01/modern_opengl/prints/Figura%204.jpeg?raw=true) 
|:--:| 
| *Figura 4: Triângulo colorido.* |
