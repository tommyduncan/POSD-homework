#ifndef ADDSHAPE_H_INCLUDED
#define ADDSHAPE_H_INCLUDED

class addShape{
public:
    vector<Media*> add(vector<Media*> m,string strInput){
            istringstream ss(strInput);
            vector <string> s;
            string token;
            while(getline(ss, token, ' ')){
                s.push_back(token);
            }
            if(s.size()!=4)
                throw string("input add fail!!!!");
            ComboMedia * com;
            int num=0;
            for(int i=0;i<m.size();i++){
                if(s[3] == m[i]->getName()){
                    com = dynamic_cast<ComboMedia *>(m[i]);
                    num = i;
                }
            }
            for(int i=0;i<m.size();i++){
                if(s[1]==m[i]->getName()){
                    Media &mtemp = *m[i];
                    com->add(&mtemp);
                }
            }
            DescriptionVisitor dv;
            m[num]->accept(&dv);
            NameVisitor nv;
            m[num]->acceptNV(&nv);
            cout<<">> "<<m[num]->getName()<<" = "<<nv.getAllName()<<" = "<<dv.getDescription()<<endl;
            return m;
        }
};

#endif // ADDSHAPE_H_INCLUDED
