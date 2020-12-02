#include <iostream>

#include "./includes/image.h"
#include "./includes/lodepng.h"

//Solo es para probar segun escribe una imagen a archivo
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height);

int main() {
    Image img;
    img.read("test.png");
    std::vector<unsigned char>  *imgr =imgToChar(img);
    char filename[80];
    cout<<"w: "<<img.getWidth()<<" h"<<img.getHeight()<<endl;
    cout<<"Nombre del nuevo archivo archivo: ";
    cin>>filename;
    //encodeOneStep(filename,*imgr,img.getWidth(),img.getHeight());

    img.write(strcat(filename, ".png"));

    delete imgr;
    return 0;
}
