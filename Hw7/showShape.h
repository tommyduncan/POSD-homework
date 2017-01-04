#ifndef SHOWSHAPE_H_INCLUDED
#define SHOWSHAPE_H_INCLUDED

class showShape{
public:
    void show(vector<Media*> m){
        if(m.size()==0)
            cout<<"No shape!\n";
        else
            for(int i =0; i<m.size();i++)
              cout<<m[i]->getName()<<endl;
    }
};

#endif // SHOWSHAPE_H_INCLUDED
