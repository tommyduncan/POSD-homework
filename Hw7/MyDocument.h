#ifndef MYDOCUMENT_H_INCLUDED
#define MYDOCUMENT_H_INCLUDED

#include "Document.h"
#include <fstream>

class MyDocument : public Document{
private :
    void openFile(const string name){
        //std::cout << name << std::endl;
        file.open(name,std::ios::in);
        //ifstream f(name);
    }
    bool canOpenDocument(const string name){
        if(name != "" || !file){
            return true;
        }
        return false;
    }
    string readFile(){
       //char buffer[80];

       std::string line;
       getline(file,line);
       return line;
    }
    ofstream sfile;
    ifstream file;
};

class MyShellDocument : public Document{
private :
    void openFile(const string name){
        file.open(name,std::ios::in);
    }
    bool canOpenDocument(const string name){
        if(name != "" || !file){
            return true;
        }
        return false;
    }
    string readFile(){
       std::string line = "", temp;
       getline(file,temp);
       line+=temp;
       getline(file,temp);
       line = line + "/" + temp;
       file.close();
       return line;
    }
    ifstream file;
};

#endif // MYDOCUMENT_H_INCLUDED
