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
#include <cmath>

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
Image::Image( int w, int h ): Image() {
    // Asignación de ancho y alto de la imagen.
    width  = w;
    height = h;

    // Si llega a existir un arreglo pixels antes de ser inicializado, se libera.
    if( pixels ) delete [] pixels;

    pixels = new Pixel[ w * h ];
    for( int i = 0; i < height; i++ )
        for( int j = 0; j < width; j++ ) {
            pixels[ (i*width) + j ].r = 255;
            pixels[ (i*width) + j ].g = 255;
            pixels[ (i*width) + j ].b = 255;
            pixels[ (i*width) + j ].a = 255;
        }
}

// Constructor paramétrico (abre el archivo con el nombre especificado).
Image::Image( const char *filename ): Image() {
    // Lectura de archivo y asignación al objeto.
    read( filename );
}

// Constructor copia.
Image::Image( const Image &img ): Image() {
    if( &img != this ) {
        width = img.width;
        height = img.height;

        if( pixels ) delete [] pixels;
        pixels = new Pixel[ width*height ];

        for( int i = 0; i < ( width*height ); i++ ) pixels[i] = img.pixels[i];
    }
}

// Abrir una imagen.
void Image::read( const char *filename ) {
    vector< unsigned char > image;

    // Decodificamos la imagen.
    unsigned error = decode( image, ( unsigned & ) width, ( unsigned & ) height, filename );

    if( error ) cout << "Hubo un error al codificar (error " << error << "): " << lodepng_error_text(error) << endl;

    // Si el arreglo de pixeles se encuentra inicializado, eliminar.
    if( pixels ) delete [] pixels;

    pixels = new Pixel[ width*height ];

    // Asignación de pixeles de la imagen.
    int j = 0;
    for( int i = 0; i < image.size(); i += 4, j++ ){
        pixels[ j ].r = image[ i ];
        pixels[ j ].g = image[ (i+1) ];
        pixels[ j ].b = image[ (i+2) ];
        pixels[ j ].a = image[ (i+3) ];
    }

    // cout << "Imagen leída: " << endl;
    // printPixels();
}

// Guardar una imagen.
void Image::write( const char *filename ) {
    vector<unsigned char> image;

    // Aumentar tamaño para manipulación.
    image.resize( 4*( width*height ) );

    // Asignación de pixeles en la imagen.
    int j = 0;
    for( int i = 0; i < image.size(); i += 4, j++ ){
        image[ i ]     = pixels[j].r;
        image[ (i+1) ] = pixels[j].g;
        image[ (i+2) ] = pixels[j].b;
        image[ (i+3) ] = pixels[j].a;
    }

    // Codifica la imagen.
    unsigned error = encode( filename, image, width, height );

    // Si algún error se encuentra durante el proceso, mostrarlo.
    if( error ) cout << "Hubo un error al codificar (error " << error << "): " << lodepng_error_text( error ) << endl;
}

// Regresa referencia al valor en x, y. Para consultar/modificar el valor.
Pixel &Image::operator()( int x, int y ) {
    int index = ( y * width ) + x;
    return pixels[ index ];
}

// Operador de asignación.
const Image &Image::operator=( const Image &img ) {
    if( &img != this ) {
        // Si llega a existir un arreglo pixels antes de ser inicializado, se libera.
        if( pixels ) delete [] pixels;

        // Asignación de ancho y alto de la imagen.
        width  = img.width;
        height = img.height;

        pixels = new Pixel[ width * height ];
        for( int i = 0; i < ( width*height ); i++ ) pixels[i] = img.pixels[i];
    }

    return *this;
}

// Combina dos imágenes superponiéndolas (A arriba, B abajo).
Image Image::operator+( const Image &img ) {
    Image res;

    // Si las imágenes son el mismo objeto simplemente regresa una copia de este.
    if( ( this != &img ) && ( pixels && img.pixels ) ) {
        res.width = ( width > img.width ) ? width : img.width;
        res.height = ( height > img.height ) ? height : img.height;

        res.pixels = new Pixel[ res.width*res.height ];
        
        // Copiamos la imagen contenida en img primero (para que esté debajo).
        for( int i = 0; i < img.height; i++ )
            for( int j = 0; j < img.width; j++ )
                res.pixels[ (i*res.width) + j ] = img.pixels[ (i*img.width) + j ];

        // Copiamos la imagen contenida en *this después (para que esté encima de img).
        for( int i = 0; i < height; i++ )
            for( int j = 0; j < width; j++ )
                if( pixels[ (i*width) + j ].a > 0 )
                    res.pixels[ (i*res.width) + j ] = pixels[ (i*width) + j ];

    } else return *this;
    
    return res;
}

// Simplemente para debug, borrar después.
void Image::printPixels() const {
    for( int i = 0; i < height; i++ ) {
        for( int j = 0; j < width; j++ )
            cout << "[" << pixels[ (i*width) + j ].r << pixels[ (i*width) + j ].g
                        << pixels[ (i*width) + j ].b << pixels[ (i*width) + j ].a
                 << "]\t";
        cout << endl;
    }
    cout << endl;
}

Image::~Image() { if( pixels ) delete [] pixels; }