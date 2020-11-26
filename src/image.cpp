/*
 * Desarrollado por: Baca Barbosa Braulio José.
 * 		     Guevara Mosqueda Héctor.
 * 		     Hernández Antonio Aldo Isaac.
 * Fecha de creación: 25/11/2020.
 * Descripción: Definición de funciones clase Image.
 */

// #include "../includes/pixel.hpp"
#include "../includes/image.hpp"

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
void Image::read() const {

}

// Guardar una imagen.
void Image::write() {

}

// Regresa referencia al valor en x, y. Para consultar/modificar el valor.
Pixel Image::operator()( int x, int y ) {
	Pixel px;
	return px;
}

// Operador de asignación.
const Image &Image::operator=( const Image &img ) {
	return *this;
}

// Combina dos imágenes superponiéndolas (A arriba, B abajo).
Image &Image::operator+( const Image &img ) {
	return *this;
}
