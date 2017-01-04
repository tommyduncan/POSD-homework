#ifndef INSTRUCTION_H_INCLUDED
#define INSTRUCTION_H_INCLUDED

#include "defineShape.h"
#include "showShape.h"
#include "addShape.h"
#include "deleteShape.h"
#include "loadFile.h"
#include "saveFile.h"
#include "Calculator.h"
#include "CommandManager.h"
#include "DefineMediaCommand.h"
#include "DeleteMediaCommand.h"
#include "AddMediaCommand.h"


class Insruction
{
public :
    void InsructionProcess() {
        string strInput,instruction;
        std::stack<MediaBuilder *> mbstack;
        MediaDirector director;
        CommandManager cmdManager;
        director.setMediaBuilder(&mbstack);
        vector<Media*> m;// List
        bool duplicated = false;
        while(1) {
            cout<<":- ";
            getline(cin,strInput,'\n');

            instruction = strInput.substr(0,strInput.find_first_of(" "));

            if(instruction == "def") {
                DefineMediaCommand dmc(m, strInput);
                cmdManager.ExecuteCMD(&dmc);
                m = dmc.getMedia();
            }
            else if(instruction == "show") {
                showShape ss;
                ss.show(m);
            }
            else if(instruction == "add") {
                AddMediaCommand amc(m, strInput);
                cmdManager.ExecuteCMD(&amc);
                m = amc.getMedia();
            }
            else if(instruction == "delete") {
                DeleteMediaCommand dmc(m, strInput);
                cmdManager.ExecuteCMD(&dmc);
                m = dmc.getMedia();
            }
            else if(instruction == "load") {
                loadFile lf;
                m = lf.loadShape(m,strInput);
            }
            else if(instruction == "save") {
                saveFile sf;
                sf.saveShape(m,strInput);
            }
            else {
                Calculator cac;
                m = cac.calculate(m,strInput);
            }
        }
    }
};

#endif // INSTRUCTION_H_INCLUDED
