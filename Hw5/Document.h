#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED

#include<string>
#include<fstream>

using namespace std;

class Document{
public:
    string openDocument(const string name);

protected:
    virtual void openFile(const string name) = 0;
    virtual bool canOpenDocument(const string name) = 0;
    virtual string readFile() = 0;
};

class MyDocument : public Document{
public:
    void openFile(const string name);
    bool canOpenDocument(const string name);
    string readFile();

private:
    fstream fin;
    char line[128];
};

#endif
