#include<stdio.h>
#include<stdlib.h>
typedef struct{
    double real;
    double imag;
}Complex;

Complex* createComplex(double real, double imag){
    Complex* c = (Complex*)malloc(sizeof(Complex));
    c->real = real;
    c->imag=imag;
    return c;
}
void addComplex(Complex* c1, Complex* c2, Complex* result){
    result->real = c1->real + c2->real;
    result->imag = c1->imag + c2->imag;
}
void subtractComplex(Complex* c1, Complex* c2, Complex* result){
    result->real = c1->real - c2->real;
    result->imag = c1->imag - c2->imag;
}
void multiplyComplex(Complex* c1, Complex* c2, Complex* result){
    result ->real = c1->real * c2->real - c1->imag * c2->imag;
    result ->imag = c1->real*c2->imag + c1->imag*c2->real;
}
void printComplex(Complex* c){
    printf("%f + i%f", c->real, c->imag);
}
int main(){
    Complex* c1 = createComplex(1, 1);
    Complex* c2 = createComplex(2,2);
    Complex* result = createComplex(0,0);
    addComplex(c1, c2, result);
    printComplex(result);
    
    free(c1);
    free(c2);
    free(result);
    return 0;
}
