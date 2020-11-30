/*
 * Desarrollado por: Baca Barbosa Braulio José.
 * 	 	     Guevara Mosqueda Héctor.
 * 	 	     Hernández Antonio Aldo Isaac.
 * Fecha de creación: 25/11/2020.
 * Descripción: Definición de funciones clase Image.
 */

// Dependencias
#include "../includes/pixel.hpp"
#include "../includes/image.hpp"
#include "../includes/lodepng.hpp"
#include <iostream>

// Funciones miembro de clase Image
// Constructor por defecto.
Image::Image() {

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
void Image::read(char*filename) {
	std::vector<unsigned char> image;
	unsigned w,h;
	unsigned error=lodepng::decode(image,w,h,filename);
	if(error) std::cout<<"Error ";lodepng_error_text(error);
	if(pixels!=NULL){
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


