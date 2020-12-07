/*
    Desarrollado por:
        * Baca Barbosa Braulio José.
        * Guevara Mosqueda Héctor.
        * Hernández Antonio Aldo Isaac.
    Fecha de creación: 25/11/2020.
    Descripción: Declaración estructura Pixel.
*/

#ifndef PIXEL_H
#define PIXEL_H

struct Pixel {
    // Constructor.
    Pixel( char = 255, char = 255, char = 255, char = 255 );

    // Funciones miembro.
    void modificarPixel( char = 255, char = 255, char = 255, char = 255 );

    // Datos de miembro: Red, Green, Blue, Alpha, respectivamente.
    unsigned char r, g, b, a;
};

#endif //PIXEL_H
