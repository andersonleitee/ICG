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

int pixelPosition(int x, int y){
    int linha = ((y*4)*IMAGE_WIDTH);
    int coluna = (x*4);
    int posicao = linha + coluna;

    return posicao;
}

void putPixel(Pixel pixel){

if((pixel.x>=0 && pixel.x<IMAGE_HEIGHT) && (pixel.y>=0 && pixel.y<IMAGE_WIDTH)){

    for (int i = 0; i < 4; i++){
        fb_ptr[pixelPosition(pixel.x, pixel.y)+i] = pixel.RGBA[i];
    }
}

}

// void drawLine(Pixel pi, Pixel pf){
//    double  dx, dy, D, inc_L , inc_NE;
//    int x, y;

//    dx = pf.x - pi.x;
//    dy = pf.y - pi.y;
//    D = 2*dy - dx;

//    inc_NE = 2*(dy-dx);
//    inc_L =  2*dy;

//    x = pi.x;
//    y = pi.y;

//    putPixel(x, y, color)

//    while (x<pf.x){
//        if(D <= 0){
//            D+= inc_L;
//            x++;
//        } else
//        {
//            D+= inc_NE;
//            y++;
//        }
//         x++;  
//        putPixel(x,y,color)
//    }


// }

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Caro aluno: chame aqui as funções que você implementou <<<
    //
    Pixel p1;
    p1.x = 500;
    p1.y = 500;
    p1.RGBA[0] = 255;
    p1.RGBA[1] = 0;
    p1.RGBA[2] = 0;
    p1.RGBA[3] = 255;

    putPixel(p1);
}
