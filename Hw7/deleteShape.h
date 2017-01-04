#ifndef DELETESHAPE_H_INCLUDED
#define DELETESHAPE_H_INCLUDED

class deleteShape{
public :
    vector<Media*> deleteShapes(vector<Media*> m,string strInput){
        istringstream ss(strInput);
        vector <string> s;
        string token;
        int a;
        while(getline(ss, token, ' ')){s.push_back(token);}
        if(s.size() == 2){
            Media *shm;
            bool find_shape = false;
            for(int i=0 ; i < m.size() ; i++){
                if(s[1] == m[i]->getName()){
                  shm = m[i];
                  find_shape = true;
                  m.erase(m.begin()+i);}
            }
            if(find_shape == true){
                bool find_element;
                for(int i =0; i<m.size(); i++){
                    FindElementVisitor fv(s[1]);
                    find_element = false;
                    m[i]->acceptFV(&fv);
                    find_element = fv.getFindElement();
                    if(find_element == true){
                        shm = fv.getMedia();
                        m[i]->removeMedia(shm);
                    }}}
            delete shm;}
        if(s.size()==4){
            ComboMedia *com;
            Media *shm;
            bool find_combo = false;
            bool find_shape = false;
            for(int i=0 ; i < m.size() ; i++){
                if(s[3] == m[i]->getName()){
                    find_combo = true;
                    com = dynamic_cast<ComboMedia *>(m[i]);}
                if(s[1] == m[i]->getName()){find_shape = true;}}
            if( find_combo == true && find_shape == true ){
                FindElementVisitor fv(s[1]);
                com->acceptFV(&fv);
                if(fv.getFindElement()){
                    shm = fv.getMedia();
                    com->removeMedia(shm);
                    DescriptionVisitor dv;
                    com->accept(&dv);
                    cout<<dv.getDescription()<<"m[i] size = "<<m.size()<<endl;}
                else
                    cout<<"We can not find ShapeMedia in ComboMedia\n";
            }
            else
                cout<<"ComboMedia or ShapeMedia is not exist\n";
        }
        return m;
    }
};

#endif // DELETESHAPE_H_INCLUDED
