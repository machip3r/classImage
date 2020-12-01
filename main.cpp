#include <iostream>


#include "../includes/image.h"

void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height);

int main() {
    Image img;
    img.read("test.png");
    std::vector<unsigned char>  imgr =imgToChar(img);
    char filename[80];
    cout<<"w: "<<img.getWidth()<<" h"<<img.getHeight()<<endl;
    cout<<"Nombre del archivo: ";
    cin>>filename;
    encodeOneStep(filename,imgr,img.getWidth(),img.getHeight());
    return 0;
}
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);
    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}
