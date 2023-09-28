#ifndef GEO_H
#define GEO_H

#include <const.h>

class mPoint{
public :

    int x , y;

    mPoint() ;

    mPoint( int x2 , int y2) ;

    int kc2( mPoint  other);

    double kc(mPoint other);

    bool isInside( int w ,  int h );

    double goc(mPoint * other);

    void operator = (mPoint other){
        x = other.x  , y = other.y ;
    }
};

#endif
