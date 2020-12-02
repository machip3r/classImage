/*
    Desarrollado por:
        * Baca Barbosa Braulio José.
        * Guevara Mosqueda Héctor.
        * Hernández Antonio Aldo Isaac.
    Fecha de creación: 25/11/2020.
    Descripción: Definición de funciones de clase Image.
*/

// Dependencias.
#include <iostream>

#include "../includes/pixel.h"
#include "../includes/image.h"
#include "../includes/lodepng.h"

using namespace std;
using namespace lodepng;

// Constructor por defecto.
Image::Image() {
    width  = 0;
    height = 0;
    pixels = nullptr;
}

// Constructor paramétrico (crear imagen de ancho y alto definido).
Image::Image( int w, int h ) {
    // Asignación de ancho y alto de la imagem
    width  = w;
    height = h;
    pixels = nullptr;
}

// Constructor paramétrico (abre el archivo con el nombre especificado).
Image::Image( const char *f ) {
    // Lectura de archivo y asignación al objeto
    read(f);
}

// Constructor copia.
Image::Image( Image *img ) {

}

// Abrir una imagen.
void Image::read( const char *filename ) {
    vector< unsigned char > image;

    // Decodificamos la imagen.
    unsigned error = decode( image, ( unsigned & ) width, ( unsigned & ) height, filename );

    if( error ) cout << "Hubo un error de ejecución.\nEl error: " << lodepng_error_text(error) << endl;

    // Si el arreglo de pixeles se encuentra inicializado, eliminar.
    if( pixels ) delete [] pixels;

    pixels = new Pixel[ width*height ];

    int j = 0;
    for( int i = 0; i < image.size(); i += 4, j++ ){
        pixels[ j ].r = image[ i ];
        pixels[ j ].g = image[ i+1 ];
        pixels[ j ].b = image[ i+2 ];
        pixels[ j ].a = image[ i+3 ];
    }
}

// Guardar una imagen.
void Image::write(const char *f) {
    // Declaración de variables
    vector<unsigned char> image;
    int j = 0;

    // Aumentar tamaño para manipulación
    image.resize(width * height * 4);

    // Asignación de pixeles en la imagen
    for( int i = 0; i < image.size(); i += 4, j++ ){
        image[i] = pixels[j].r;
        image[(i + 1)] = pixels[j].g;
        image[(i + 2)] = pixels[j].b;
        image[(i + 3)] = pixels[j].a;
    }

    // Creando archivo de salida
    encodeOneStep(f, image, width, height);
}

// Regresa referencia al valor en x, y. Para consultar/modificar el valor.
Pixel &Image::operator()( int x, int y ) {
    int index = ( y * width ) + x;
    return pixels[ index ];
}

// Operador de asignación.
const Image &Image::operator=( const Image &img ) {
    return *this;
}

// Combina dos imágenes superponiéndolas (A arriba, B abajo).
Image &Image::operator+( const Image &img ) {
    return *this;
}

Image::~Image() { if( pixels ) delete [] pixels; }

vector<unsigned char> *imgToChar( const Image &img ) {
    int size = 4 * ( img.width * img.height );
    int sizep = img.width * img.height;
    
    vector< unsigned char > *arrimg = new vector< unsigned char >( size );

    int j = 0;
    for( int i = 0; i < size; i += 4, j++ ) {
        (*arrimg)[ i ]   = img.pixels[ j ].r;
        (*arrimg)[ i+1 ] = img.pixels[ j ].g;
        (*arrimg)[ i+2 ] = img.pixels[ j ].b;
        (*arrimg)[ i+3 ] = img.pixels[ j ].a;
    }

    return  arrimg;
}

void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);
    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}