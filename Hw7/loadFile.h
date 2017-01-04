#ifndef LOADFILE_H_INCLUDED
#define LOADFILE_H_INCLUDED

#include "MyDocument.h"

class loadFile{
public :
    vector<Media*> loadShape(vector<Media*> m,string strInput){
        istringstream ss(strInput);
        vector <string> s;
        string token;
        while(getline(ss, token, '"')){
            s.push_back(token);
        }
        if(s.size()!=2)
            throw string("load fail!!!!");
        cout << ">> " << "loading "<< s[1] <<" ..." << endl;
        MyShellDocument msd;
        string filecontent;
        filecontent = msd.openDocument(s[1]);
        istringstream ss2(filecontent);
        string content[2], temp; int k =0;
        while(getline(ss2, temp, '/')){
            content[k]=temp;
            k++;
        }
        stack<MediaBuilder *>mbstack;
        MediaDirector director;
        director.setMediaBuilder(&mbstack);
        director.concrete(content[0]);

        ComboMedia * com = mbstack.top()->getComboMedia();
        DescriptionVisitor dv;
        com->accept(&dv);
        setNameVisitor snv(content[1]);
        com->acceptSV(&snv);
        putLoadDataVisitor pldv(&m);
        com->acceptPLDV(&pldv);
        return m;
    }
};

#endif // LOADFILE_H_INCLUDED
