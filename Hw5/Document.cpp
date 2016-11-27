#include "Document.h"

string Document::openDocument(const string name){
    if(!canOpenDocument(name))
            throw std::string("file is not existed.");
    openFile(name);
    return readFile();
}

/* Class "MyDocument" which is the subclass of "Document" */
void MyDocument::openFile(const string name){
    fin.open(name, ios::in);
}

bool MyDocument::canOpenDocument(const string name){
    fin.open(name, ios::in);

    if(!fin)
        return false;

    fin.close();

    return true;
}

string MyDocument::readFile(){
    fin.getline(line,sizeof(line));

    return line;
}
