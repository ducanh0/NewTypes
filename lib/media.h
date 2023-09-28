#ifndef MEDIA_H
#define MEDIA_H

#include <const.h>
#include <geo.h>

class LTexture{
public :

    SDL_Renderer * mRender ;
    TTF_Font * mFont ;
    SDL_Texture * mTexture ;
    int mWidth , mHeight ;

    LTexture();

    LTexture( SDL_Renderer * newRender, TTF_Font * newFont) ;

    ~LTexture();

    void loadImage( string path, int r, int g, int b);

    void loadText( string text, SDL_Color textColor);

    void setAlpha( Uint8 alpha );

    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    void render( int x,  int y , SDL_Rect * clip = NULL, double angle = 0.0 ,
                 SDL_Point * center = NULL,  SDL_RendererFlip flip = SDL_FLIP_NONE);
};

class LSound {
public :

    Mix_Chunk * mSou ;

    ~LSound();

    LSound( string path);

    void playSound();
};

class LMusic{
public :

    Mix_Music * mMus ;

    ~LMusic();

    LMusic( string path);

    void playMusic();

    void stopMusic();
};

class bling{ /// for enemy
public :

    mPoint td;
    int   mFrame , id ; /// id de random xem vao mau nao

    bling();

    ~bling();

    bool isDead();

    void reset(mPoint other);

    void render( SDL_Renderer * newRender, mPoint other, bool ok);
};

class Dot{
public :

    mPoint td ;
    double  vx, vy ;
    LTexture * pic;

    Dot( string path,mPoint other, SDL_Renderer * newRender, int r, int g, int b);

    ~Dot();

    bool dichuyen( int w  , int h );

    bool vacham(Dot * other);

    void render( double angle);
};

class LButton{
public :

    mouseStatus a ;
    mPoint td;
    LTexture * b;
    int w, h, n ;

    LButton(SDL_Renderer * newRender, TTF_Font * f[] , mPoint other, vector<string>  V);

    ~LButton();

    void handleEvent(SDL_Event e,bool & ok,bool  &ok2,bool & replay);

    void render( bool ok1, bool ok, bool ok2,bool ok3 = 0);
};

#endif
