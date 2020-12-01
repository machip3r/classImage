

#ifndef POOCALIS_PIXEL_H
#define POOCALIS_PIXEL_H
struct Pixel {
    // Constructor.
    Pixel( char = 0, char = 0, char = 0, char = 0 );
    // Datos de miembro: Red, Green, Blue, Alpha, respectivamente.
    unsigned char r, g, b, a;
};

#endif //POOCALIS_PIXEL_H
