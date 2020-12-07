// Directivas del preprocesador
#include <iostream>

#include "./includes/image.h"
#include "./includes/lodepng.h"

// Función principal
int main( void ) {

	unsigned int resp;

	cout << endl << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;
	do{
		// Declaración e inicialización de variables.
		char input[80], output[80];

		// Menú de selección de acciones.
		cout << "*** Asegúrate de colocar tus imágenes en la carpeta images o especificar la ruta de acceso ***" << endl << endl
		     << "1. Crear una imagen vacía (con fondo blanco). " << endl
		     << "2. Abrir una imagen (sólo muestra las dimensiones de la imagen)." << endl
		     << "3. Editar 1 píxel de una imagen (.png)." << endl
		     << "4. Sumar dos imágenes (A encima de B)." << endl
		     <<"0. Salir del programa"<<endl
		     << "Respuesta: ";

		// Introducción de la operación.
		cin >> resp; cin.ignore( 256, '\n' );
		cout << endl << "--------------------------------------------------------------" << endl << endl;

		// Menú y acciones.
		switch( resp ) {

			// Crear imagen vacía (en blanco).
			case 1: {
				int w = 0, h = 0;	// Variabes para ancho y alto de imagen.

				cout << "1. Crear una imagen vacía (con fondo blanco). " << endl;
				cout << "Introduce alto: ";  cin >> h; cin.ignore( 256, '\n' );
				cout << "Introduce ancho: "; cin >> w; cin.ignore( 256, '\n' );

				// Creación del objeto imagen usando el constructor paramétrico.
				Image img( w, h );

				// Introducción de nombre para salida de la imagen. (Por defecto "salida.png").
				cout << "Introduce el nombre del archivo resultante: ";
				cin.getline( output, 80, '\n' );

				// Creación de la imagen de salida.
				img.write( output );
			}
			break;

			case 2: { // Abrir una imagen existente, simplemente muestra su alto y ancho.

				// Solicitud del nombre de la imagen a leer.
				cout << "Introduce el nombre del archivo de imagen (.png): ";
				cin.getline( input, 80, '\n' );

				// Creación del objeto Image utilizando el constructor con el nombre del archivo.
				Image img( input );

				// Impresión de las dimensiones de la imagen.
				cout << "El ancho de la imagen: " << img.getWidth() << '.' << endl
				     << "El alto de la imagen: "  << img.getHeight() << '.' << endl << endl;
			}
			break;

			case 3: { // Editar el píxel de una imagen (recomendable para imágenes de dimensiones pequeñas).

				Image img; // Imagen a almacenar y editar.
				unsigned int x = 0, y = 0;  // Coordenadas píxel.
				unsigned int r = 0, g = 0, b = 0, a = 0;    // Parámetros píxel.

				// Solicitud del nombre de la imagen a editar.
				cout << "Introduce el nombre del archivo de imagen (.png): ";
				cin.getline( input, 80, '\n' );

				// Abriendo la imagen utilizando el constructor paramétrico con nombre.
				img.read( input );

				// Impresión de las dimensiones de la imagen.
				cout << "El ancho de la imagen: " << img.getWidth() << '.' << endl
				     << "El alto de la imagen: "  << img.getHeight() << '.' << endl << endl;

				int cent = 0; // Variable centinela para controlar el ciclo.

				do {
					// Introducción coordenadas de píxel.
					cout << "Coordenada X del píxel a editar: "; cin >> x; cin.ignore( 256, '\n' );
					cout << "Coordenada Y del píxel a editar: "; cin >> y; cin.ignore( 256, '\n' );
					cout << endl;

					// Almacenar la dirección del píxel a editar con una referencia a tipo Pixel.
					Pixel &px = img( x, y );

					// Muestra de la información del Pixel obtenido en la referencia.
					cout << "Parámetros originales de Píxel (" << x << ", " << y << "):" << endl
					     << "Rojo: "      	  << +px.r << endl
					     << "Verde: " 	  << +px.g << endl
					     << "Azul: " 	  << +px.b << endl
					     << "Alpha: " 	  << +px.a << endl << endl;

					// Introducción de los parámetros de píxel.
					cout << "Introduce un nuevo valor de r: "; cin >> r; cin.ignore( 256, '\n' );
					cout << "Introduce un nuevo valor de g: "; cin >> g; cin.ignore( 256, '\n' );
					cout << "Introduce un nuevo valor de b: "; cin >> b; cin.ignore( 256, '\n' );
					cout << "Introduce un nuevo valor de a: "; cin >> a; cin.ignore( 256, '\n' );
					cout << endl;

					// Asignación de valores a la estructura.
					px.modificarPixel( r, g, b, a );

					cout << "¿Desea editar más píxeles?\nRespuesta: "; cin >> cent; cin.ignore( 256, '\n' );
					cout << endl;

				} while( cent > 0 && cent < 2 );

				// Solicitud del nombre de la imagen de salida. (Por defecto "salida.png").
				cout << "Introduce el nombre del archivo de salida: ";
				cin >> output; cin.ignore( 256, '\n' );

				// Guardar la imagen en el disco con el nombre introducido.
				img.write( output );
			}
			break;

			case 4: { // Suma dos imágenes (superpone A sobre B).
				Image imgA, imgB, imgC; // ImgA e ImgB operandos, ImgC resultado.

				// Solicitud del nombre de la primer imagen.
				cout << "Introduce el nombre del archivo de la imagen A (.png): ";
				cin.getline( input, 80, '\n' );

				// Lectura de la imagen.
				imgA.read( input );

				// Solicitud del nombre de la segunda imagen.
				cout << "Introduce el nombre del archivo de la imagen B (.png): ";
				cin.getline( input, 80, '\n' );

				// Lectura de la imagen.
				imgB.read( input );

				// Superponiendo A sobre B por medio del operador suma.
				imgC = imgA + imgB;

				// Solicitud del nombre de la imagen de salida. (Por defecto "salida.png").
				cout << "Introduce el nombre del archivo de salida C (.png): ";
				cin.getline( output, 80, '\n' );

				// Guardando la imagen creada en Disco.
				imgC.write( output );
			}
			break;

			case 0:
				// Salida del programa.
				cout << "Saliendo del programa. Gracias por usar." << endl;
			break;

			default: { // Si se llegan a introducir opciones inválidas en el menú.
				cout << "*** Introduce una opción válida***" << endl << endl;
			}
			break;
		}

		cout << endl << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;

	} while( resp != 0 );

	return 0;
}
