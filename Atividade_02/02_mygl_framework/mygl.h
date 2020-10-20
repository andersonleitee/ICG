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

typedef struct 
{
    int x;
    int y;
    int RGBA[4];
}Pixel;

//
// >>> Caro aluno: declare aqui as funções que você implementar <<<
//

int posicaoPixel(int x, int y);
void putPixel(Pixel pixel); 
#endif  // MYGL_H
