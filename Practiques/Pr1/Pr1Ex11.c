//
// Programa per a solucionar equacions polinomiques de segon grau.
//
// Sergi Palau 1750517
// Nicolás Merayo 1752648

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
        printf("L'equacio no es de segon grau si poseu a=0 .\n");
        
        // Comprovació de b per veure si és menor que la tolerància
        if (fabs(b) < tol) {
            fprintf(stderr, "Les dades generen una equacio sense incognita\n");
            return -1;
        }
        
        printf("La solucio de\n (%.12g) * x + (%.12g) =0\nes:\n",b,c);
        printf("x= %.12g\n",-c/b);
    }
    
    else{
        discr = b*b-4*a*c;
        if(discr<0){
            printf("\nEquacio amb solucions complexes\n");
            printf("(%.12g)*x^2+(%.12g)*x+(%.12g)=0\n",a,b,c);
            printf("Te solucions:\n");

            double x_1 = -b/(2 * a);
            double x_2 = sqrt(-discr)/(2 * a);

            printf("%.12g + i%.12g\n", (x_1), (x_2));
            printf("%.12g - i%.12g\n", (x_1), (x_2));
        }
        
        else{
            if(discr<tol){
                printf("\nEquacio amb solucio doble:\n");
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
