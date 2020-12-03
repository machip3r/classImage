#include <iostream>

#include "./includes/image.h"
#include "./includes/lodepng.h"

int main( void ) {

    char input[80], output[80];
    unsigned int resp = 0;

    cout << "***Asegúrate de colocar tus imágenes en la carpeta images o especificar la ruta de acceso***" << endl << endl
         << "1. Crear una imagen vacía. " << endl
         << "2. Abrir una imagen (sólo muestra las dimensiones de la imagen)." << endl
         << "3. Editar 1 píxel de una imagen (.png)." << endl
         << "4. Sumar dos imágenes (A encima de B)." << endl
         << "Respuesta: ";
    cin >> resp; cin.ignore( 256, '\n' );
    cout << endl << "--------------------------------------------------------------" << endl << endl;

    switch( resp ) {
        case 1: {
            int w = 0, h = 0;
            cout << "Introduce alto: ";  cin >> h; cin.ignore( 256, '\n' );
            cout << "Introduce ancho: "; cin >> w; cin.ignore( 256, '\n' );
            Image img( h, w );
            
            cout << "Introduce el nombre del archivo resultante: ";
            cin.getline( output, 80, '\n' );
            img.write( output );
        }
        break;

        case 2: {
            cout << "Introduce el nombre del archivo de imagen (.png): ";
            cin.getline( input, 80, '\n' );
            Image img( input );

            cout << "El ancho de la imagen: " << img.getWidth() << '.' << endl
                 << "El alto de la imagen: "  << img.getHeight() << '.' << endl << endl;
        }
        break;

        case 3: {
            Image img;
            unsigned int x = 0, y = 0;  // Coordenadas píxel.
            unsigned int r = 0, g = 0, b = 0, a = 0;    // Parámetros píxel.

            cout << "Introduce el nombre del archivo de imagen (.png): ";
            cin.getline( input, 80, '\n' );
            img.read( input );

            cout << "El ancho de la imagen: " << img.getWidth() << '.' << endl
                 << "El alto de la imagen: "  << img.getHeight() << '.' << endl << endl;

            cout << "Coordenada X del píxel a editar: "; cin >> x; cin.ignore( 256, '\n' );
            cout << "Coordenada Y del píxel a editar: "; cin >> y; cin.ignore( 256, '\n' );

            Pixel &px = img( x, y );   
            cout << endl; 
            cout << "Información de Píxel (" << x << ", " << y << "):" << endl
                 << "Rojo: "      << +px.r << endl
                 << "Verde: " 	  << +px.g << endl
                 << "Azul: " 	  << +px.b << endl
                 << "Alpha: " 	  << +px.a << endl << endl;

            cout << "Introduce un nuevo valor de r: "; cin >> r; cin.ignore( 256, '\n' );
            cout << "Introduce un nuevo valor de g: "; cin >> g; cin.ignore( 256, '\n' );
            cout << "Introduce un nuevo valor de b: "; cin >> b; cin.ignore( 256, '\n' );
            cout << "Introduce un nuevo valor de a: "; cin >> a; cin.ignore( 256, '\n' );
            
            px.r = r;
            px.g = g;
            px.b = b;
            px.a = a;

            cout << endl;    
            cout << "Después de modificación de Píxel (" << x << ", " << y << "):" << endl
                 << "Rojo: "      << +px.r << endl
                 << "Verde: " 	  << +px.g << endl
                 << "Azul: " 	  << +px.b << endl
                 << "Alpha: " 	  << +px.a << endl << endl;

            cout << "Introduce el nombre del archivo de salida: ";
            cin >> output; cin.ignore( 256, '\n' );
            strcat( output, ".png" );

            img.write( output );
        }
        break;

        case 4: {

            Image imgA, imgB, imgC;

            cout << "Introduce el nombre del archivo de la imagen A (.png): ";
            cin.getline( input, 80, '\n' );
            imgA.read( input );

            cout << "Introduce el nombre del archivo de la imagen B (.png): ";
            cin.getline( input, 80, '\n' );
            imgB.read( input );

            imgC = imgA + imgB;

            cout << "Introduce el nombre del archivo de salida C (.png): ";
            cin.getline( output, 80, '\n' );
            imgC.write( output );
        }
        break;
    }

    return 0;
}