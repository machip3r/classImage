//
// Created by vegue on 30/11/2020.
//

#ifndef POOCALIS_IMAGE_H
#define POOCALIS_IMAGE_H
#include "Pixel.h"
#include <vector>
using namespace std;
class Image {
    friend std::vector< unsigned char> imgToChar(Image img);
public:
    // Constructor por defecto.
    Image();

    // Constructor paramétrico (crear imagen de ancho y alto definido).
    Image( int, int );

    // Constructor paramétrico (abre el archivo con el nombre especificado).
    Image( const char * );

    // Constructor copia.
    Image( Image * );

    // Abrir una imagen.
    void read(char*filename) ;

    // Guardar una imagen.
    void write();

    // Obtener los miembros privados (funciones inline).
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // Regresa referencia al valor en x, y. Para consultar/modificar el valor.
    Pixel operator()( int, int );
    // Operador de asignación.
    const Image &operator=( const Image & );

    // Combina dos imágenes superponiéndolas (A arriba, B abajo).
    Image &operator+( const Image & );

    // Destructor.
    ~Image();
private:
    int width;	// Ancho de la imagen.
    int height;	// Alto de la imagen.
    Pixel* pixels;
};


#endif //POOCALIS_IMAGE_H
