#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>

#include "core.h"

void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a memória do framebuffer

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Caro aluno: declare aqui as funções que você implementar <<<
//

typedef struct 
{
    int x;
    int y;
}Pixel;

typedef struct 
{
   float red;
   float green; 
   float blue;
   float alpha; //transparente
} RGBA;

typedef struct 
{
    Pixel pi; 
    Pixel pf;
}Linha;

int posicaoPixel(int x, int y);
int sinal (int valor);
void putPixel(int x, int y, RGBA color); 
void drawLine (Pixel pi, Pixel pf, RGBA color1, RGBA color2 );
void drawTriangle(Pixel p1, Pixel p2, Pixel p3);
#endif  // MYGL_H
