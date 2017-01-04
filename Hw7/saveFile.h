#ifndef SAVEFILE_H_INCLUDED
#define SAVEFILE_H_INCLUDED

class saveFile{
public :
    void saveShape(vector<Media*> m,string strInput){
        istringstream ss(strInput);
        vector <string> s;
        string token;
        while(getline(ss, token, ' ')){
            s.push_back(token);
        }
        if(s.size()!=4)
            throw string("save instruction fail!!!!");

        string temp = s[3];
        temp.erase(temp.begin(),temp.begin()+2);
        temp.erase(temp.end()-1,temp.end());
        ofstream fout(temp);
        DescriptionVisitor dv;
        NameVisitor nv;
        for(int i =0; i<m.size();i++){
            if(s[1]==m[i]->getName()){
                m[i]->accept(&dv);
                m[i]->acceptNV(&nv);
                fout << dv.getDescription()<<endl;
                fout << nv.getAllName()<<endl;
                fout.close();
                break;}
        }
        cout << ">> " <<s[1]<< " saved to "<< s[3] << endl;
    }
};

#endif // SAVEFILE_H_INCLUDED
