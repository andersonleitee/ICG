#include "mygl.h"

unsigned char* fb_ptr = NULL;

void InitMyGl(void) {
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));	

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i) {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }    
}

unsigned char* GetFBMemPtr(void) {
	return fb_ptr;
}

void CloseMyGl(void) {
    if (!fb_ptr)
        free(fb_ptr);
}

//
// >>> Caro aluno: defina aqui as funções que você implementar <<<
//

int posicaoPixel(int x, int y){
    int linha = ((y*4)*IMAGE_WIDTH);
    int coluna = (x*4);
    int posicao = linha + coluna;

    return posicao;
}

void putPixel(void){

// Escreve um pixel vermelho 
 fb_ptr[posicaoPixel(400,450)+0] = 255;
 fb_ptr[posicaoPixel(400,450)+1] = 0;
 fb_ptr[posicaoPixel(400,450)+2] = 0;
 fb_ptr[posicaoPixel(400,450)+3] = 255;

// Escreve um pixel verde 
fb_ptr[posicaoPixel(320,320)+0] = 0;
fb_ptr[posicaoPixel(320,320)+1] = 255;
fb_ptr[posicaoPixel(320,320)+2] = 0;
fb_ptr[posicaoPixel(320,320)+3] = 255;

// Escreve um pixel azul
fb_ptr[posicaoPixel(157,200)+0] = 0;
fb_ptr[posicaoPixel(157,200)+1] = 0;
fb_ptr[posicaoPixel(157,200)+2] = 255;
fb_ptr[posicaoPixel(157,200)+3] = 255;

}


// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Caro aluno: chame aqui as funções que você implementou <<<
    //
    putPixel();
}
