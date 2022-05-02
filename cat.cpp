#include<iostream>
#include<fstream>

int main(int argc, char **argv){
    char buffer[512];
    std::fstream file;
    std::string path=*(argv+2);
    std::string filename=*(argv+1);
    path=path+"/"+filename;

    file.open(path,std::ios::in);
    while(!file.eof()){
        file.getline(buffer,512,'\n');
        std::cout<<buffer<<"\n";
    }
    return 0;
}

