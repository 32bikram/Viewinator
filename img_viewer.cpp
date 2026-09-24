#include<iostream>
#include<SDL2/SDL.h>
#include<fstream>
#include <vector>
using namespace std;

//works with ppm files only
int main(){
    cout<<"please enter file path - ";
    string str;
    cin>>str;
    ifstream file(str,ios::binary); 
    string format;
    int width, height, max_col;
    file >> format;
    file>>ws; // skip whitespace + comments
    string comment;
    while (file.peek() == '#') {
        getline(file,comment);
    }
    file >> width >> height>>max_col;
    file>>ws; //consume the /n after max_col
    // width *= 8;
    // height *= 2;
    // cout<<comment<<" "<<width<<" "<<height<<" "<<max_col<<" "<<format;
    int size = height*width*3;
    vector<unsigned char> myvec(size);

    file.read(reinterpret_cast<char*>(myvec.data()),size);
    //myvec.data() return a pointer to the first element


    SDL_Window *my_win =  SDL_CreateWindow("my_win",0,0,width,height,0);
    SDL_Surface *my_sur =  SDL_GetWindowSurface(my_win);
    // Uint32 color = SDL_MapRGB(my_sur->format, 255, 0, 0); //red
    SDL_Rect pixel = {0,0,1,1};
    int k = 0;
    Uint32 color = 0;
    while(true){
        cout<<"FOR GREYSCALE ENTER : 1, FOR COLOR ENTER : 2\n";
        int a;
        cin>>a;
        int red, blue, green, grey;
        if(a==1){
            for(int i = 0; i<height; i++){
                for(int j = 0; j<width; j++){
                    red = myvec[k]; green = myvec[k+1]; blue = myvec[k+2];
                    grey = red*0.299+green*0.587+blue*0.114;
                    color = SDL_MapRGB(my_sur->format, grey, grey, grey);
                    pixel = {j,i,1,1};
                    SDL_FillRect(my_sur, &pixel, color);
                    k+=3;
                }
            }
            break;
        }
        if(a==2){
            for(int i = 0; i<height; i++){
                for(int j = 0; j<width; j++){
                    color = SDL_MapRGB(my_sur->format, myvec[k], myvec[k+1], myvec[k+2]);
                    pixel = {j,i,1,1};
                    SDL_FillRect(my_sur, &pixel, color);
                    k+=3;
                }
            }
            break;
        }
        else cout<<"PLEASE ENTER VALID INPUT\n";
    }
    SDL_UpdateWindowSurface(my_win);
    bool viewing = true;
    while(viewing){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                viewing = false;
            }
        }
        SDL_Delay(100);
    }
}
