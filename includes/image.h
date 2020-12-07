/*
    Desarrollado por:
        * Baca Barbosa Braulio José.
        * Guevara Mosqueda Héctor.
        * Hernández Antonio Aldo Isaac.
    Fecha de creación: 25/11/2020.
    Descripción: Declaración clase Image.
*/

#ifndef IMAGE_H
#define IMAGE_H

// Dependencias.
#include <vector>
#include "../includes/pixel.h"

using namespace std;

class Image {
public:
    // Constructor por defecto.
    Image();

    // Constructor paramétrico (crear imagen de ancho y alto definido).
    Image( int, int );

    // Constructor paramétrico (abre el archivo con el nombre especificado).
    Image( const char * );

    // Constructor copia.
    Image( const Image & );

    // Abrir una imagen.
    void read( const char * = "images/salida.png" );

    // Guardar una imagen.
    void write( const char * );

    // Obtener los miembros privados (funciones inline).
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // Regresa referencia al valor en x, y. Para consultar/modificar el valor.
    Pixel &operator()( int, int );

    // Operador de asignación.
    const Image &operator=( const Image & );

    // Combina dos imágenes superponiéndolas (A arriba, B abajo).
    Image operator+( const Image & );

    // Destructor.
    ~Image();
private:
    // Datos miembro.
    int width;	// Ancho de la imagen.
    int height;	// Alto de la imagen.
    Pixel* pixels;  // Arreglo/matriz de Pixel contenedora de la imagen en formato bruto.

    // Funciones de utilidad.
};

#endif //IMAGE_H
