#ifndef DEFINESHAPE_H_INCLUDED
#define DEFINESHAPE_H_INCLUDED

#include <vector>
#include "ShapeMedia.h"

using namespace std;

class defineShape{
public :
    vector<Media*> define(vector<Media*> m,string strInput,bool duplicated){
         istringstream ss(strInput);
        vector <string> s;
        string token;
        while(getline(ss, token, ' ')){
            s.push_back(token);
        }
        if(s.size()!=4)
            throw string("input fail!!!!");

        string temp = s[3];
        string head = temp.substr(0, temp.find_first_of("("));
        for(int i =0; i<m.size();i++){
           if(s[1] == m[i]->getName()){
             cout << "name duplicated" << endl;
             duplicated = true;
           }
        }
        if(duplicated == false){
            if(head == "Circle"){
                temp.erase(0,temp.find_first_of("(")+1);
                temp.erase(temp.end()-1,temp.end());
                istringstream ss2(temp);
                vector<double> carray;
                while(getline(ss2, token, ',')){
                    istringstream sst(token);
                    int t = 0;
                    sst>>t;
                    carray.push_back(t);
                }
                if(carray.size()>3)
                    throw string("circle fail");
                Circle *c = new Circle(carray[0], carray[1],carray[2]);
                c->setName(s[1]);
                ShapeMedia *sh = new ShapeMedia(c);
                m.push_back(sh);

                cout<< ">> Circle (" << carray[0]<<","<<carray[1]<<","<<carray[2]<<")" << endl;
            }
            if(head == "Rectangle"){
                temp.erase(0,temp.find_first_of("(")+1);
                temp.erase(temp.end()-1,temp.end());
                istringstream ss2(temp);
                vector<double> rArray;
                while(getline(ss2, token, ',')){
                    istringstream sst(token);
                    int t = 0;
                    sst>>t;
                    rArray.push_back(t);
                }
                if(rArray.size()>4)
                    throw string("Rectangle fail");
                Rectangle *r = new Rectangle(rArray[0], rArray[1],rArray[2],rArray[3]);
                r->setName(s[1]);
                ShapeMedia *sh = new ShapeMedia(r);
                m.push_back(sh);

                cout<< ">> Rectangle (" << rArray[0]<<","<<rArray[1]<<","<<rArray[2]<<","<<rArray[3]<<")" << endl;
            }
            else{
                    string head = temp.substr(0, temp.find_first_of("{"));
                    if(head == "combo"){
                    temp.erase(0,temp.find_first_of("{")+1);
                    temp.erase(temp.end()-1,temp.end());
                    istringstream ss2(temp);
                    if(temp.size()<1)
                        throw string("Combo can not empty");
                    vector<string> cparray;
                    while(getline(ss2, token, ',')){
                        cparray.push_back(token);
                    }
                    if(cparray.size()<1)
                        throw string("Combo input error");
                    vector<Media*> mtemp;
                    int count = 0;
                    for(int i =0; i<cparray.size();i++){
                        for(int j=0; j< m.size();j++){
                            if(cparray[i]==m[j]->getName()){
                                mtemp.push_back(m[j]);
                                count++;
                            }
                        }
                    }
                    if(count!=cparray.size())
                        throw string("combo number is wrong!!");
                    ComboMedia *com = new ComboMedia(mtemp);
                    com->setName(s[1]);
                    m.push_back(com);
                    cout<<"success\n";
                  }
                }
            }
            return m;
    }
};

#endif // DEFINESHAPE_H_INCLUDED
