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


int pixelPosition(int x, int y){  //calcula o deslocamento (offset) do pixel
    int linha = ((y*4)*IMAGE_WIDTH);
    int coluna = (x*4);
    int posicao = linha + coluna;

    return posicao;
}

RGBA red = {255, 0, 0, 255}; //Struct inicializado já com a disposição de cores
RGBA green = {0, 255, 0, 255};
RGBA blue = {0, 0, 255, 255};
RGBA alpha = {0, 0, 0, 255};

void putPixel(int x, int y, RGBA cor){ //Função para rasterizar ponto 

if((x>=0 && x<IMAGE_HEIGHT) && (y>=0 && y<IMAGE_WIDTH)){ //verifica se as coordenadas estão dentro do tamanho máximo da tela
        fb_ptr[pixelPosition(x, y) +0] = cor.red;
        fb_ptr[pixelPosition(x, y) +1] = cor.green;
        fb_ptr[pixelPosition(x, y) +2] = cor.blue;
        fb_ptr[pixelPosition(x, y) +3] = cor.alpha;
}

}

// Verifica o sinal conforme a variação das coordenads, caso essa variação der um número negativo a reta será decrementada.
int sinal (int valor){
    if (valor > 0){
        return 1; //incrementa
    } else if (valor < 0){
        return -1; //decrementa
    }
        return 0;
}

void drawLine (int x0, int y0, int x1, int y1, RGBA cor1, RGBA cor2 ){ //Função para rasterizar linha
int x, y, s1, s2, aux, i;
float inter1, inter2, inter3, inter4; //inter = interpolação
double dx, dy;
double D, inc_L, inc_NE;
int flag = 0; // Flag para saber se a variação de y é maior que a de x

    x = x0;
    y = y0;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);

    s1 = sinal(x1 - x0);
    s2 = sinal(y1 - y0);

    if(dy > dx){ //verifica se a variação de y é maior que a de x, se for haverá uma troca de forma que nos resguarda que dx sempre será a maior variação.
        aux = dx; dx = dy; dy = aux; flag = 1; 
    } else{
        flag = 0;
    }
    // se a variação de y for maior que a variação de y, implica dizer que o angulo da reta é maior que 45 graus
    //ocasionando uma inclinação para cima, e assim saindo do pirmeiro octante. Caso isso ocorra, para que haja 
    //um calculo mais preciso do algorítimo há uma troca da variação. 

    D = 2*dy - dx;
    inc_L = 2*dy; 
    inc_NE = 2*(dy - dx); 

    RGBA cor = cor1; //Variável cor que guarda a cor do primeiro pixel

    putPixel(x, y, cor1); //pixel inicial

    inter1 = ((cor2.red) - (cor1.red))/dx; //Interpolação
    inter2 = ((cor2.green)- (cor1.green))/dx;
    inter3 = ((cor2.blue)- (cor1.blue))/dx;
    inter4 = ((cor2.alpha) - (cor1.alpha))/dx;

    for(i = 0; i < dx; i++){ 

        if(D <= 0){ //Variável de decisão negativa, reta abaixo do ponto médio então inclina pra leste
            if(flag){ //se a variação de Y for maior que X a flag estará ativa
                y = y + s2; //incrementa no eixo Y
            }else{
                x = x + s1;
            } 
            D = D + inc_L; //Incrementa a leste
        }else{
            y = y + s2; // Variável de decisão positiva, reta acima do ponto médio
            x = x + s1;
            D = D + inc_NE; //Incrementa a nordeste
        }

        cor.red = cor.red + inter1; // incrementa cada cor por pixel até a cor final no ultimo pixel 
        cor.green = cor.green + inter2;
        cor.blue = cor.blue + inter3;
        cor.alpha =  cor.alpha + inter4; 

         putPixel(x, y, cor); 
    }
}

void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2){ //Desenha triângulo
    drawLine(x0, y0, x1, y1, green, red);
    drawLine(x1, y1, x2, y2, red, blue);
    drawLine(x0, y0, x2, y2, blue, green);
}


// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

//Olá professor, caso queira testar as demais funções é só descomentar uma e comentar as outras :D

//putPixel
/*
putPixel(400,450, red);
putPixel(200,200, green);
putPixel(420,460, blue);
*/
//drawLine

//drawLine(0, 0, 512, 512, red, green);

// drawTriangle

drawTriangle(50,450,400,250,350,450);

}
