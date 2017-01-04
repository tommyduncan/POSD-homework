#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

class Calculator{
public :
    vector<Media*> calculate(vector<Media*> m,string strInput){
         bool exists = strInput.find(".") != std::string::npos;
             if(strInput.size()>6 && exists==true){
                istringstream ss2(strInput);
                vector<string> mathCalculate;
                string token = "";
                while(getline(ss2, token, '.'))
                    mathCalculate.push_back(token);
                if(mathCalculate[1] == "area?"){
                    bool findDot = false;
                    for(int i = 0; i < m.size(); i++)
                        if(mathCalculate[0] == m[i]->getName()){
                            findDot = true;
                            cout<<">> "<< m[i]->area() << endl;
                            break;
                        }
                    if(findDot == false)
                       cout<<"Input error1!\n";
                }
                else if(mathCalculate[1] == "perimeter?"){
                    bool findDot = false;
                    for(int i = 0; i < m.size(); i++)
                        if(mathCalculate[0] == m[i]->getName()){
                            findDot = true;
                            cout<<">> "<< m[i]->perimeter() << endl;
                            break;
                        }
                    if(findDot == false)
                       cout<<"Input error1!\n";
                }
                else
                   cout<<"Input error2!\n";
            }
            else
                cout<<"Input error3!\n";
            return m;
    }
};

#endif // CALCULATOR_H_INCLUDED
