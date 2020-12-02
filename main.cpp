#include <iostream>

#include "./includes/image.h"
#include "./includes/lodepng.h"

//Solo es para probar segun escribe una imagen a archivo
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height);

int main( void ) {

    Image img;
    Pixel px;
    char filename[80], filename2[80];
    // unsigned int r = 0, g = 0, b = 0, a = 0;

    img.read("test.png");

    Image img2( img );

    cout << "El ancho de la imagen: " << img.getWidth() << '.' << endl
         << "El alto de la imagen: " << img.getHeight() << '.' << endl << endl;

    // cout << "Píxel 7, 3 original de img:" << endl
	//  << "Rojo: "      << +px.r << endl
	//  << "Verde: " 	  << +px.g << endl
	//  << "Azul: " 	  << +px.b << endl
	//  << "Alpha: " 	  << +px.a << endl << endl;

    // cout << "Píxel 7, 3 original de img2:" << endl
	//  << "Rojo: "      << +px2.r << endl
	//  << "Verde: " 	  << +px2.g << endl
	//  << "Azul: " 	  << +px2.b << endl
	//  << "Alpha: " 	  << +px2.a << endl << endl;

    // cout << "Introduce un nuevo valor de r: "; cin >> r;
    // cout << "Introduce un nuevo valor de g: "; cin >> g;
    // cout << "Introduce un nuevo valor de b: "; cin >> b;
    // cout << "Introduce un nuevo valor de a: "; cin >> a;

    // px.r = r;
    // px.g = g;
    // px.b = b;
    // px.a = a;

    // px2.r = r;
    // px2.g = g;
    // px2.b = b;
    // px2.a = a;

    // cout << endl;    
    // cout << "Píxel 7, 3 de img modificado:" << endl
	//  << "Rojo: "      << +px.r << endl
	//  << "Verde: " 	  << +px.g << endl
	//  << "Azul: " 	  << +px.b << endl
	//  << "Alpha: " 	  << +px.a << endl << endl;
    
    // cout << endl;
    // cout << "Píxel 7, 3 de img2 modificado:" << endl
	//  << "Rojo: "      << +px2.r << endl
	//  << "Verde: " 	  << +px2.g << endl
	//  << "Azul: " 	  << +px2.b << endl
	//  << "Alpha: " 	  << +px2.a << endl << endl;

    cout << "Introduce el nombre del archivo de salida: ";
    cin >> filename;
    strcpy( filename2, filename );
    strcat( filename,   ".png" );
    strcat( filename2, "2.png" );

    vector< unsigned char > *imgr = imgToChar( img );
    img.write( filename );

    vector< unsigned char > *imgr2 = imgToChar( img2 );
    img2.write( filename2 );

    delete imgr;
    delete imgr2;

    return 0;
}
