#ifndef DELETEMEDIACOMMAND_H_INCLUDED
#define DELETEMEDIACOMMAND_H_INCLUDED

#include <string>
#include "Command.h"
#include "deleteShape.h"

class DeleteMediaCommand : public Command {
public:
    DeleteMediaCommand(vector<Media *> m, string cmd): media(m), command(cmd){}

    void Execute(){
        deleteShape ds;
        media = ds.deleteShapes(media,command);
    }

    void Undo(){}

    void Redo(){}

    vector<Media *> getMedia(){
        return media;
    }

private:
    string command;
    vector<Media *> media;
};

#endif // DELETEMEDIACOMMAND_H_INCLUDED

