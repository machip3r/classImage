// Directivas del preprocesador
#include <iostream>

#include "./includes/image.h"
#include "./includes/lodepng.h"

// Función principal
int main( void ) {
     unsigned int resp;
    do{
    // Declaración e inicialización de variables
    char input[80], output[80];
   

    // Menú y solictud de variable
    cout << "***Asegúrate de colocar tus imágenes en la carpeta images o especificar la ruta de acceso***" << endl << endl
         << "1. Crear una imagen vacía. " << endl
         << "2. Abrir una imagen (sólo muestra las dimensiones de la imagen)." << endl
         << "3. Editar 1 píxel de una imagen (.png)." << endl
         << "4. Sumar dos imágenes (A encima de B)." << endl
         <<"0. Salir del programa"<<endl
         << "Respuesta: ";
    // Lectura de variable
    cin >> resp; cin.ignore( 256, '\n' );
    // Impresión estética
    cout << endl << "--------------------------------------------------------------" << endl << endl;

    // Menú y acciones
    switch( resp ) {
        // Crear imagen vacía
        case 1: {
            // Declaración de variables
            int w = 0, h = 0;

            // Solicitud y lectura de variable
            cout << "Introduce alto: ";  cin >> h; cin.ignore( 256, '\n' );
            cout << "Introduce ancho: "; cin >> w; cin.ignore( 256, '\n' );
            // Creación del objeto imagen
            Image img( h, w );

            // Solicitud del nombre de la imagen de salida
            cout << "Introduce el nombre del archivo resultante: ";
            cin.getline( output, 80, '\n' );

            // Creación de la imagen de salida
            img.write( output );
        }
        break;

        // Abrir imagen
        case 2: {
            // Solicitud del nombre de la imagen a leer
            cout << "Introduce el nombre del archivo de imagen (.png): ";
            cin.getline( input, 80, '\n' );
            // Creación del objeto imagen
            Image img( input );

            // Impresión de las dimensiones de la imagen
            cout << "El ancho de la imagen: " << img.getWidth() << '.' << endl
                 << "El alto de la imagen: "  << img.getHeight() << '.' << endl << endl;
        }
        break;

        // Editar pixel de imagen
        case 3: {
            // Declaración de variables
            Image img;
            unsigned int x = 0, y = 0;  // Coordenadas píxel.
            unsigned int r = 0, g = 0, b = 0, a = 0;    // Parámetros píxel.

            // Solicitud del nombre de la imagen a editar
            cout << "Introduce el nombre del archivo de imagen (.png): ";
            cin.getline( input, 80, '\n' );
            // Lectura de la imagen
            img.read( input );

            // Impresión de las dimensiones de la imagen
            cout << "El ancho de la imagen: " << img.getWidth() << '.' << endl
                 << "El alto de la imagen: "  << img.getHeight() << '.' << endl << endl;

            // Solicitud y lectura de variable
            cout << "Coordenada X del píxel a editar: "; cin >> x; cin.ignore( 256, '\n' );
            cout << "Coordenada Y del píxel a editar: "; cin >> y; cin.ignore( 256, '\n' );

            // Creación de la estructura Pixel para la edición en la imagem
            Pixel &px = img( x, y );
            // Salto de línea
            cout << endl;
            // Muestra de la información del Pixel
            cout << "Información de Píxel (" << x << ", " << y << "):" << endl
                 << "Rojo: "      << +px.r << endl
                 << "Verde: " 	  << +px.g << endl
                 << "Azul: " 	  << +px.b << endl
                 << "Alpha: " 	  << +px.a << endl << endl;

            // Solicitud y lectura de cada valor en el Pixel
            cout << "Introduce un nuevo valor de r: "; cin >> r; cin.ignore( 256, '\n' );
            cout << "Introduce un nuevo valor de g: "; cin >> g; cin.ignore( 256, '\n' );
            cout << "Introduce un nuevo valor de b: "; cin >> b; cin.ignore( 256, '\n' );
            cout << "Introduce un nuevo valor de a: "; cin >> a; cin.ignore( 256, '\n' );

            // Asignación de valores a la estructura
            px.r = r;
            px.g = g;
            px.b = b;
            px.a = a;

            // Salto de línea
            cout << endl;
            // Muestra de la información del Pixel editado
            cout << "Después de modificación de Píxel (" << x << ", " << y << "):" << endl
                 << "Rojo: "      << +px.r << endl
                 << "Verde: " 	  << +px.g << endl
                 << "Azul: " 	  << +px.b << endl
                 << "Alpha: " 	  << +px.a << endl << endl;

            // Solicitud del nombre de la imagen de salida
            cout << "Introduce el nombre del archivo de salida: ";
            cin >> output; cin.ignore( 256, '\n' );
            // Asignación del formato de imagen (.png)
            strcat( output, ".png" );

            // Creación de la imagen de salida
            img.write( output );
        }
        break;

        // Suma de imágenes
        case 4: {
            // Declaración de variables
            Image imgA, imgB, imgC;

            // Solicitud del nombre de la primer imagen
            cout << "Introduce el nombre del archivo de la imagen A (.png): ";
            cin.getline( input, 80, '\n' );
            // Lectura de la imagen
            imgA.read( input );

            // Solicitud del nombre de la segunda imagen
            cout << "Introduce el nombre del archivo de la imagen B (.png): ";
            cin.getline( input, 80, '\n' );
            // Lectura de la imagen
            imgB.read( input );

            // Suma de las imágenes con ayuda del operador suma
            imgC = imgA + imgB;

            // Solicitud del nombre de la imagen de salida
            cout << "Introduce el nombre del archivo de salida C (.png): ";
            cin.getline( output, 80, '\n' );

            // Creación de la imagen de salida
            imgC.write( output );
        }
        break;
        case 0:
            cout<<"\nAdios......";
        break;
        // Validación de valores inválidos en el menú
        default: {
            // Salto de línea
            cout << endl;
            // Impresión estática
            cout << "Introduce una opción válida" << endl;
            // Salto de línea
            cout << endl;
        }
        break;
    }
    }while(resp!=0);
    // Salida exitosa del programa
    return 0;
}