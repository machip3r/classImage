#include <iostream>

#include "./includes/image.h"
#include "./includes/lodepng.h"

//Solo es para probar segun escribe una imagen a archivo
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height);

int main( void ) {

    Image img;
    Pixel px;
    char filename[ 80 ];
    unsigned int r = 0, g = 0, b = 0, a = 0;

    img.read("test.png");

    cout << "El ancho de la imagen: " << img.getWidth() << '.' << endl
         << "El alto de la imagen: " << img.getHeight() << '.' << endl << endl;

    px = img( 7, 3 );

    cout << "Píxel 7, 3 original:" << endl
	 << "Rojo: "      << +px.r << endl
	 << "Verde: " 	  << +px.g << endl
	 << "Azul: " 	  << +px.b << endl
	 << "Alpha: " 	  << +px.a << endl << endl;

    cout << "Introduce un nuevo valor de r: "; cin >> r;
    cout << "Introduce un nuevo valor de g: "; cin >> g;
    cout << "Introduce un nuevo valor de b: "; cin >> b;
    cout << "Introduce un nuevo valor de a: "; cin >> a;

    px.r = r;
    px.g = g;
    px.b = b;
    px.a = a;

    cout << endl;
    cout << "Píxel 7, 3 modificado:" << endl
	 << "Rojo: "      << +px.r << endl
	 << "Verde: " 	  << +px.g << endl
	 << "Azul: " 	  << +px.b << endl
	 << "Alpha: " 	  << +px.a << endl << endl;

    cout << "Introduce el nombre del archivo de salida: ";
    cin >> filename;

    vector< unsigned char > *imgr = imgToChar( img );

    img.write(strcat(filename, ".png"));

    delete imgr;
    return 0;
}
