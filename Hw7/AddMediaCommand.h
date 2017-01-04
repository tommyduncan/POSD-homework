#ifndef ADDMEDIACOMMAND_H_INCLUDED
#define ADDMEDIACOMMAND_H_INCLUDED

#include <string>
#include "Command.h"
#include "addShape.h"

class AddMediaCommand : public Command {
public:
    AddMediaCommand(vector<Media *> m, string cmd): media(m), command(cmd){}

    void Execute(){
        addShape as;
        media = as.add(media,command);
    }

    void Undo(){
        vector <string> s;
        istringstream ss(command);
        string token;
        deleteShape ds;

        while(getline(ss, token, ' ')){
            s.push_back(token);
        }

        undoCommand = "delete " + s[1] + " from " + s[3];
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

#endif // ADDMEDIACOMMAND_H_INCLUDED


