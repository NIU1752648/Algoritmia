//
// Programa per a solucionar equacions polinomiques de segon grau.
//
#include <stdio.h>
#include <math.h>
#define tol 0.000000001
int main(){
    double a, b, c, discr;
    printf("\nIntroduiu les dades a,b,c del polinomi a*x^2+b*x+c:\n");
    while(scanf("%lf %lf %lf",&a,&b,&c)<3){
        while (getchar()!='\n'){}
        printf("Les dades no han entrat be....\nTorneu-hi...\n");
    }
    if(fabs(a)<tol){
        if (fabs(b)<tol){ // Exercici 1.1.1
            fprintf(stderr, "S'ha generat una equacio sense incognita\n");
            return 1;
        }
        printf("L'equacio no es de segon grau si poseu a=0 .\n");
        printf("La solucio de\n (%.12g) * x + (%.12g) =0\nes:\n",b,c);
        printf("x= %.12g\n",-c/b);
    }
    else{
        discr = b*b-4*a*c;
        if(discr<0){ // Exercici 1.1.2
            printf("\nEquacio amb solucions complexes\n");
            printf("Les solucions de l'equacio\n");
            printf("(%.12g)*x^2+(%.12g)*x+(%.12g)=0\n",a,b,c);
            printf("son\n");
            printf("x=%.12g+%.12gi, x=%.12g-%.12gi\n\n",-b/(2*a),sqrt(-discr)/(2*a),-b/(2*a),sqrt(-discr)/(2*a));
        }
        else{
            if(discr<tol){
                printf("\nEquacio amb solucio unica:\n");
                printf("La solucio de l'equacio\n");
                printf("(%.12g)*x^2+(%.12g)*x+(%.12g)=0\n",a,b,c);
                printf("es\n");
                printf("x=%.12g\n",-b/(2*a));
            }
            else{
                discr = sqrt(discr);
                printf("\nEquacio amb dues solucions.\n");
                printf("Les solucions de l'equacio\n");
                printf("(%.12g)*x^2+(%.12g)*x+(%.12g)=0\n",a,b,c);
                printf("son\n");
                printf("x=%.12g, x=%.12g\n\n",(-b+discr)/(2*a), (-b-discr)/(2*a));
            }
        }
    }
    return 0;
}
