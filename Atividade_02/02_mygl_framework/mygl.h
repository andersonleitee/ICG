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
   float red;
   float green; 
   float blue;
   float alpha; //transparente
} RGBA;

int pixelPosition(int x, int y);
int sinal (int valor);
void putPixel(int x, int y, RGBA cor); 
void drawLine (int x0, int y0, int x1, int y1, RGBA cor1, RGBA cor2 );
void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2);
#endif  // MYGL_H
