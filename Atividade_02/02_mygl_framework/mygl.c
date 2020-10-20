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

RGBA red = {255, 0, 0, 255}; 
RGBA green = {0, 255, 0, 255};
RGBA blue = {0, 0, 255, 255};
RGBA alpha = {0, 0, 0, 255};

void putPixel(int x, int y, RGBA cor){

if((x>=0 && x<IMAGE_HEIGHT) && (y>=0 && y<IMAGE_WIDTH)){
        fb_ptr[pixelPosition(x, y) +0] = cor.red;
        fb_ptr[pixelPosition(x, y) +1] = cor.green;
        fb_ptr[pixelPosition(x, y) +2] = cor.blue;
        fb_ptr[pixelPosition(x, y) +3] = cor.alpha;
}

}

int sinal (int valor){
    if (valor > 0){
        return 1;
    } else if (valor < 0){
        return -1;
    }
        return 0;
}

void drawLine (Pixel pi, Pixel pf, RGBA cor1, RGBA cor2 ){
int x, y, s1, s2, aux, i;
float inter1, inter2, inter3, inter4;
double dx, dy;
double D, inc_L, inc_NE;
int interchange = 0;

    x = pi.x;
    y = pi.y;

    dx = abs(pf.x - pi.x);
    dy = abs(pf.y - pi.y);

    s1 = sinal(pf.x - pi.x);
    s2 = sinal(pf.y - pi.y);

    /* Check if dx or dy has a glp2reater range */
    /* if dy has a greater range than dx swap dx and dy */
    //inclanação maior que 1
    if(dy > dx){
        aux = dx; dx = dy; dy = aux; interchange = 1;
    } else{
        interchange = 0;
    }

    D = 2*dy - dx;
    inc_L = 2*dy; 
    inc_NE = 2*(dy - dx); 

    RGBA cor = cor1;

    inter1 = ((cor2.red) - (cor1.red))/dx;
    inter2 = ((cor2.blue)- (cor1.blue))/dx;
    inter3 = ((cor2.green)- (cor1.green))/dx;
    inter4 = ((cor2.alpha) - (cor1.alpha))/dx;

    putPixel(x, y, cor1); //pixel inicial

    
    for(i = 0; i < dx; i++){
        if(D < 0){ //Ponto medio ta abaixo da reta, deveria ir para nordeste ?
            if(interchange){
                y = y + s2; //Se ocorreu troca eu mexo em Y
            }else{
                x = x + s1;
            } //Seno mexo em x
            D = D + inc_L; //Nessa condição mexo no pixel leste
        }else{
            y = y + s2; // Mexo em x e em y.
            x = x + s1;
            D = D + inc_NE; //Se D for maior que 0 então vou para leste?
        }

         putPixel(x, y, cor);

        cor.red = cor.red + inter1; // incrementa cor por pixel  ate a cor final no ultimo pixel
        cor.green = cor.green + inter2;
        cor.blue = cor.blue + inter3;
        cor.alpha =  cor.alpha + inter4; 
    }
}

void drawTriangle(Pixel p1, Pixel p2, Pixel p3){
    drawLine(p1, p2, green, red);
    drawLine(p2, p3, red, blue);
    drawLine(p1, p3, blue, green);
}


// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
//putPixel

/*
putPixel(400,450, red);

*/

 //drawLine

/* Pixel p1 = {320, 320};
    Pixel p2 = {650, 550};

    Linha linha1 = {p2, p1};

    drawLine(linha1.pi, linha1.pf, red, green);
*/

// drawTriangle

 /* Pixel p1;
    p1.x = 250;
    p1.y = 450;

    Pixel p2;
    p2.x = 300;
    p2.y = 350;
    
    Pixel p3;
    p3.x = 350;
    p3.y = 450;

    drawTriangle(p1,p2,p3);
*/

}
