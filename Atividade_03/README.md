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

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-1.jpg?raw=true) 
|:--:| 
| *Figura 1: (x,y,z)=(1/3,3/2,1)* |

## Exercício 2: Translação

Neste exercício foi demandado realizar uma translação no eixo x, na qual as coordenadas são: (x,y,z) = (1,0,0). Para `x = 1`, alteramos o eixo x da matriz View abaixo para que houvesse a translação como solicidado no exercício.

```C
    float view_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                            0.0f, 1.0f, 0.0f, 0.0f, 
                            0.0f, 0.0f, 1.0f, 0.0f, 
                              x , 0.0f, 0.0f, 1.0f};

    glm::mat4 view_mat = glm::make_mat4(view_array);
```

### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-2.jpg?raw=true) 
|:--:| 
| *Figura 2: (x,y,z)=(1,0,0)* |

## Exercício 3: Projeção Perspectiva

Para este exercício foi requisitado alterar a matriz projeção (proj_array) baseada na matriz cedida no anunciado. Com isso, para que obtivéssemos o resultado conforme o solicitado foi alterado o valor do `d`, no qual `d = 1`, e derivou-se a matriz projeção abaixo:  

```C
    float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                            0.0f, 1.0f, 0.0f, 0.0f, 
                            0.0f, 0.0f, 1.0f,-1.0f/d, 
                            0.0f, 0.0f,   d , 1.0f};

    glm::mat4 proj_mat = glm::make_mat4(proj_array);
```

### Resultado

![](https://github.com/andersonleitee/ICG/blob/master/Atividade_03/prints/Exercicio-3.jpg?raw=true) 
|:--:| 
| *Figura 2: d = 0.5f* |
## Referências

