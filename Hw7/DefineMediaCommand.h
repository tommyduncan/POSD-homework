#ifndef DEFINEMEDIACOMMAND_H_INCLUDED
#define DEFINEMEDIACOMMAND_H_INCLUDED

#include <string>
#include "Command.h"
#include "defineShape.h"
#include "deleteShape.h"

class DefineMediaCommand : public Command {
public:
    DefineMediaCommand(vector<Media *> m, string cmd): media(m), command(cmd){}

    void Execute(){
        defineShape ds;
        media = ds.define(media, command, false);
    }

    void Undo(){
        vector <string> s;
        istringstream ss(command);
        string token;
        deleteShape ds;

        while(getline(ss, token, ' ')){
            s.push_back(token);
        }

        undoCommand = "delete " + s[1];

        media = ds.deleteShapes(media, undoCommand);
    }

    void Redo(){}

    vector<Media *> getMedia(){
        return media;
    }

private:
    string command;
    string undoCommand;
    vector<Media *> media;
};

#endif // DEFINEMEDIACOMMAND_H_INCLUDED
