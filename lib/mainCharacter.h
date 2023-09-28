#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <media.h>
#include <bullet.h>

class mainCha{
public :

    Dot * a;
    bullet * b[sl_bullet];
    vector<int>  chuaBan;

    mainCha(SDL_Renderer * newRender,mPoint other);

    ~mainCha();

    void render( double angle);

    void dichuyen( int x, int y);

    void bandan( double ha, double hb, bool okx , bool oky); /// goc tu mainCha den enemy

    static void playSound();
};

#endif
