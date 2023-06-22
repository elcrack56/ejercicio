#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float puntos[3][2] = {(0, 0, 3), (3, 0, 0), (0, 0, 0), (1, 7, 1)};
    float per1, per2, per3, per4, l1, l2, l3, l4, l5, l6, areab;
    calcularPerimetro(puntos, &per1, &per2, &per3, &per4, &l1, &l2, &l3, &l4, &l5, &l6);
    float Areasuperficial = calcularArea(per1, per2, per3, per4, l1, l2, l3, l4, l5, l6, &areab);
    printf("El Area superficial es: %f\n", Areasuperficial);
    float vol = calcularVolumen(puntos, areab);
    printf("El volumen es: %f\n", vol);
    return 0;
}

float calculardistancia(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) + pow(z1 - z2, 2);
    return dist;
}

void calcularPerimetro(float puntos[3][2], float *per1, float *per2, float *per3, float *per4, float *l1, float *l2, float *l3, float *l4, float *l5, float *l6)
{
    *l1 = calculardistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l2 = calculardistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *l3 = calculardistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l4 = calculardistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l5 = calculardistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l6 = calculardistancia(puntos[3][0], puntos[3][1], puntos[3][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *per1 = *l1 + *l2 + *l3;
    *per2 = *l2 + *l4 + *l6;
    *per3 = *l3 + *l5 + *l6;
    *per4 = *l1 + *l5 + *l4;
}

float calcularArea(float per1, float per2, float per3, float per4, float l1, float l2, float l3, float l4, float l5, float l6, float *areab)
{
    float s1, s2, s3, s4;
    s1 = per1 / 2;
    s2 = per2 / 2;
    s3 = per3 / 2;
    s4 = per4 / 2;
    *areab = sqrt(s1 * (s1 - l1) * (s1 - l2) * (s1 - l3));
    float areal = sqrt(s2 * (s2 - l2) * (s2 - l4) * (s2 - l6));
    float areall = sqrt(s3 * (s3 - l3) * (s3 - l5) * (s3 - l6));
    float arealll = sqrt(s4 * (s4 - l1) * (s4 - l5) * (s4 - l4));
    float Areasup = *areab + areal + areall + arealll;
    return Areasup;
}

float calcularVolumen(float puntos[3][2], float areab)
{
    float baricentro[1][2];
    baricentro[0][0] = (puntos[0][0] + puntos[1][0] + puntos[2][0])/2;
    baricentro[0][1] = (puntos[0][1] + puntos[1][1] + puntos[2][1])/2;
    baricentro[0][2] = (puntos[0][2] + puntos[1][2] + puntos[2][2])/2;
    float alt = calculardistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    float volu = (areab * alt)/3;
    return volu;
}