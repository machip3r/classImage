//
// Created by vegue on 30/11/2020.
//

#include "../includes/Image.h"
#include "../includes/Pixel.h"
#include "../source/lodepng.h"

#include <iostream>

// Funciones miembro de clase Image
// Constructor por defecto.
Image::Image() {
    this->width=0;
    this->height=0;
    this->pixels= nullptr;
}

// Constructor paramétrico (crear imagen de ancho y alto definido).
Image::Image( int width, int height ) {

}

// Constructor paramétrico (abre el archivo con el nombre especificado).
Image::Image( const char *archivo ) {

}

// Constructor copia.
Image::Image( Image *img ) {

}

// Abrir una imagen.
void Image::read(const char *filename) {
    std::vector<unsigned char> image;
    unsigned w,h;
    unsigned error=lodepng::decode(image,w,h,filename);
    if(error) std::cout<<"Error "<<lodepng_error_text(error)<<std::endl;
    if(pixels!= nullptr){
        delete [] pixels;
    }
    pixels=new Pixel[w*h];
    int j=0;
    for(int i=0;i<image.size();i+=4){
        pixels[j].r=image[i];
        pixels[j].g=image[i+1];
        pixels[j].b=image[i+2];
        pixels[j].a=image[i+3];
        j++;
    }

    this->width=w;
    this->height=h;
}


// Guardar una imagen.
void Image::write() {

}

// Regresa referencia al valor en x, y. Para consultar/modificar el valor.
Pixel Image::operator()( int x, int y ) {
    int index=y*this->width+x;
    return pixels[index];
}

// Operador de asignación.
const Image &Image::operator=( const Image &img ) {
    return *this;
}

// Combina dos imágenes superponiéndolas (A arriba, B abajo).
Image &Image::operator+( const Image &img ) {
    return *this;
}
Image::~Image(){

}

std::vector<unsigned char>  imgToChar(Image img){
    int size=4*img.width*img.height;
    int sizep=img.width*img.height;
    std::vector< unsigned  char> arrimg(size);
    int j=0;
    int i;
    for (i = 0; i < size; i+=4) {
        arrimg[i]=img.pixels[j].r;
        arrimg[i+1]=img.pixels[j].g;
        arrimg[i+2]=img.pixels[j].b;
        arrimg[i+3]=img.pixels[j].a;
        j++;
    }
    return  arrimg;
}

