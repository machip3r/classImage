/*
    Desarrollado por:
        * Baca Barbosa Braulio José.
        * Guevara Mosqueda Héctor.
        * Hernández Antonio Aldo Isaac.
    Fecha de creación: 25/11/2020.
    Descripción: Definición funciones estructura Pixel.
*/

// Dependencias.
#include "../includes/pixel.h"

// Constructor por defecto
Pixel::Pixel( char red, char green, char blue, char alpha ) {
    r = red;
    b = blue;
    g = green;
    a = alpha;
}

// Función para modificar Pixel
void Pixel::modificarPixel( char red, char green, char blue, char alpha ) {
	r = red;
	g = green;
	b = blue;
	a = alpha;
}
