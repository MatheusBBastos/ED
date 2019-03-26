#include "colisao.h"

bool colisaoCirculoRetangulo(Forma *c, Forma *r) {
    Circulo *circ = ((Circulo*) c->tipoForma);
    Retangulo *ret = ((Retangulo*) r->tipoForma);

    printf("%lf %lf %lf \n", c->x, r->x, r->x+ret->w);
    double xMaisProx = clamp(c->x, r->x, r->x + ret->w);
    double yMaisProx = clamp(c->y, r->y, r->y + ret->h);
    printf("%lf %lf\n", xMaisProx, yMaisProx);

    if( distancia(c->x, c->y, xMaisProx, yMaisProx) < circ->raio )
        return true;
    return false;
}

bool colisaoRetanguloRetangulo(Forma *r1, Forma *r2) {
    Retangulo *ret1 = ((Retangulo*) r1->tipoForma);
    Retangulo *ret2 = ((Retangulo*) r2->tipoForma);

    return (r1->x < r2->x + ret2->w) && (r1->x + ret1->w > r2->x) &&
            (r1->y < r2->y + ret2->h) && (r1->y + ret1->h > r2->y);
}

bool colisaoCirculoCirculo(Forma *c1, Forma *c2) {
    Circulo *circ1 = ((Circulo*) c1->tipoForma);
    Circulo *circ2 = ((Circulo*) c2->tipoForma);

    return distancia(c1->x, c1->y, c2->x, c2->y) < circ1->raio + circ2->raio;
}

bool formasColidem(Forma *a, Forma *b) {
    if(a->nome == 'c' && b->nome == 'r')
        return colisaoCirculoRetangulo(a, b);
    else if(a->nome == 'r' && b->nome == 'c')
        return colisaoCirculoRetangulo(b, a);
    else if(a->nome == 'r' && b->nome == 'r')
        return colisaoRetanguloRetangulo(a, b);
    else if(a->nome == 'c' && b->nome == 'c')
        return colisaoCirculoCirculo(a, b);
}   