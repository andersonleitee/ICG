# Atividade Prática 3 - Implementação do Pipeline Gráfico

<p>A atividade proposta tem como objetivo a realização de 5 exercícios propostos relacionados a transformações geométricas no pipeline gráfico, no qual o exercício 1 solicita uma modificação na matriz Model de modo que haja uma transformação na escala da figura, o exercício 2 requisita uma translação no x, o exercício 3 demanda uma modificação da matriz projection de modo que possa gerar uma determinada projeção perspectiva, já no exercício 4 requer uma modificação na matriz View com base na posição da câmera dada no anunciado e o exercício 5 requisita transformações livres. Vale salientar que a implementação é realizada com auxilio da biblioteca glm e o codigo fonte foi disponibilizado no <a href="https://github.com/capagot/icg/tree/master/03_transformations">repositório</a> do professor.</p>


## Exercício 1: Escala

Para esse exercício foi solicitado uma alteração na escala da imagem dos triângulos, conforme os dados cedidos para esta atividade, no qual a nova figura deverá conter os valores de coordenada (x,y,z)=(1/3,3/2,1) ou (0.3,1.5,1). Com isso, realizamos uma alteração na matriz Model do programa para que se obtivesse o resultado esperado. Segue a alteração da matriz abaixo onde `sx = 0.3f, sy = 1.5f, sz = 1.0f`.

```C
  float model_array[16] = { sx , 0.0f, 0.0f, 0.0f, 
                           0.0f,  sy , 0.0f, 0.0f, 
                           0.0f, 0.0f,  sz , 0.0f, 
                           0.0f, 0.0f, 0.0f, 1.0f};
    glm::mat4 model_mat = glm::make_mat4(model_array); 
```

### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-1.png?raw=true) 
|:--:| 
| *Figura 1: (x,y,z)=(1/3,3/2,1)* |

## Exercício 2: Translação

Neste exercício foi demandado realizar uma translação no eixo x, na qual as coordenadas são: (x,y,z) = (1,0,0). Para `x = 1.0f`, alteramos o eixo x da matriz View abaixo para que houvesse a translação como solicidado no exercício.

```C
    float view_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                            0.0f, 1.0f, 0.0f, 0.0f, 
                            0.0f, 0.0f, 1.0f, 0.0f, 
                              x , 0.0f, 0.0f, 1.0f};

    glm::mat4 view_mat = glm::make_mat4(view_array);
```

### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-2.png?raw=true) 
|:--:| 
| *Figura 2: (x,y,z)=(1,0,0)* |

## Exercício 3: Projeção Perspectiva

Para este exercício foi requisitado alterar a matriz projeção (proj_array) baseada na matriz cedida no anunciado. Com isso, para que obtivéssemos o resultado conforme o solicitado foi alterado o valor do `d`, no qual `d = 0.125f`, e derivou-se a matriz projeção abaixo:  

```C
    float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                            0.0f, 1.0f, 0.0f, 0.0f, 
                            0.0f, 0.0f, 1.0f,-1.0f/d, 
                            0.0f, 0.0f,   d , 1.0f};

    glm::mat4 proj_mat = glm::make_mat4(proj_array);
```

### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-3.png?raw=true) 
|:--:| 
| *Figura 3: d = 0.5f* |


## Exercício 4: Posição da Câmera

Esse exercício solicita inicialmente que seja calculado os vetores do espaço da câmera ultilizando as seguintes informações: `Posição da câmera = (−1/10, 1/10,1/10), vetor Up da câmera = (0,1,0), ponto para o qual a câmera está apontando = (0,0,-1)`. Além disso, como é necessário conhecer o vetor direção, para calculá-lo basta subtrair a posição da câmera com o ponto para onde a câmera aponta (look at). 

```C

    //Informações
    glm::vec3 cam_pos = glm::vec3(-1.0/10.0, 1.0/10.0, 1.0/10.0);//posição da câmera.
    glm::vec3 cam_look_at = glm::vec3(0.0, 0.0, -1.0);//ponto para onde a câmera aponta.
    glm::vec3 cam_up = glm::vec3(0.0, 1.0, 0.0);//Vetor Up
    glm::vec3 D = cam_pos - cam_look_at; //Vetor direção

    //Vetores da base do espaço câmera
    glm::vec3 Zcam = glm::normalize(D);
    glm::vec3 Xcam = glm::normalize(glm::cross(glm::normalize(cam_up), Zcam));
    glm::vec3 Ycam = glm::cross(Zcam, Xcam);

```

Em seguida, implementamos a matriz transposta da base da câmera `B^t` e a matriz de translação `T`

```C
   //Matriz transposta da base da câmera, B^t
     float Bt_array[16] = {Xcam.x, Ycam.x, Zcam.x, 0.0f,
                          Xcam.y, Ycam.y, Zcam.y, 0.0f,
                          Xcam.z, Ycam.z, Zcam.z, 0.0f,
                          0.0f  , 0.0f  , 0.0f  , 1.0f};

    glm::mat4 Bt_mat = glm::make_mat4(Bt_array);

    //Matriz de translação, T
     float T_array[16] = {1.0f, 0.0f, 0.0f, 0.0f,
                          0.0f, 1.0f, 0.0f, 0.0f,
                          0.0f, 0.0f, 1.0f, 0.0f,
                         -cam_pos.x, -cam_pos.y, -cam_pos.z, 1.0f};

    glm::mat4 T_mat = glm::make_mat4(T_array);
```
Logo após, implementamos a matriz View como o produto das matrizes `B^t` e `T`.

```C
    //Matriz View como o produto das matrizes B^t e T

    glm::mat4 view_mat = Bt_mat * T_mat;

```
### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-4.png?raw=true) 
|:--:| 
| *Figura 4: Posição da câmera = (−1/10, 1/10,1/10), vetor Up da câmera = (0,1,0), ponto para o qual a câmera está apontando = (0,0,-1)* |

## Exercício 5: Transformações Livres

Neste exercício, como o intuito seria a realização de transformações geométricas livres, optamos por mudar a forma da imagem para um quadrado. Com isso, atualizamos os vértices para os seguintes valores:


```C
float vertices[] = {-0.5f,  0.5f, -0.4f, 1.0f, 0.0f, 0.0f,
                     0.5f,  0.5f, -0.4f, 0.0f, 1.0f, 0.0f,
                     0.5f, -0.5f, -0.4f, 0.0f, 0.0f, 1.0f,
                    -0.5f, -0.5f, -0.4f, 1.0f, 1.0f, 1.0f,
                    -0.5f,  0.5f, -0.4f, 1.0f, 0.0f, 0.0f,
                     0.5f, -0.5f, -0.4f, 0.0f, 0.0f, 1.0f};

```

### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-5-quadrado.png?raw=true) 
|:--:| 
| *Figura 5: Quadrado gerado com alteração dos vértices* |


Em seguida, realizamos a primeira modificação na matriz model com os valores `sx = 1.0f, sy = 1.5f, sz = 1.0f`

### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-5-matriz-model.png?raw=true) 
|:--:| 
| *Figura 6: Alteração na matriz model* |

A segunda alteração foi na matriz porjection, onde atualizamos o parâmetro `d` para `d = 0.250`.

### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-5-matriz-projection.png?raw=true) 
|:--:| 
| *Figura 7: Alteração na matriz projection* |

Por fim, alteramos a matriz view, na qual substituimos as seguintes informações: `Posição da câmera = (-1/20, 1/20, 1/10), vetor Up da câmera = (0, 1, 0), ponto para o qual a câmera está apontando = (0, 0, 0)`.
```C
   //Informações
    glm::vec3 cam_pos = glm::vec3(-1.0/20.0, 1.0/20.0, 1.0/10.0);//posição da câmera.
    glm::vec3 cam_look_at = glm::vec3(0.0, 0.0, 0.0);//ponto para onde a câmera aponta.
    glm::vec3 cam_up = glm::vec3(0.0, 1.0, 0.0);//Vetor Up
    glm::vec3 D = cam_pos - cam_look_at; //Vetor direção
```
### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-5-matriz-view.png?raw=true) 
|:--:| 
| *Figura 8: Alteração na matriz view* |


## Observação:
O código referente aos exercício estão dispostos nas branchs criadas para solucionar a atividade. Os nomes dos ramos seguem o seguinte padrão: `Atvd_3/Exercicio-n` onde n é um inteiro de 1 à 5, que representa a numeração de cada exercício. 

## Referências:
- Com base nas video aulas de pipeline gtáfico do professor Christian Azambuja e <a href="https://github.com/capagot/icg/tree/master/03_transformations"> repositório</a> disponibilizado;
- <a href="https://sigaa.ufpb.br/sigaa/portais/discente/beta/discente.jsf#"> Geometric Transformations </a>
- <a href="http://matheuspraxedescg.blogspot.com/"> Blog Matheus Praxedes</a>

