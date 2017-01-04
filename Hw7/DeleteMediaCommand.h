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
        media_copy = media;
        media = ds.deleteShapes(media,command);
    }

    void Undo(){
        vector <string> s;
        istringstream ss(command);
        string token;
        addShape as;
        defineShape ds;

        DescriptionVisitor dv;

        while(getline(ss, token, ' ')){
            s.push_back(token);
        }

        if(s.size() == 2){
            for(int i = 0; i < media_copy.size(); i++){
                if(media_copy[i]->getName() == s[1]){
                    if(media_copy[i]->getMedia().size() == 0){
                        media_copy[i]->accept(&dv);
                        undoCommand = "def " + s[1] + " = " + dv.getDescription();
                    }else{
                        undoCommand = "def " + media_copy[i]->getName() + " = combo{";
                        vector<Media *> m = media_copy[i]->getMedia();

                        for(int j = 0; j < m.size(); j++){
                            undoCommand += m[j]->getName();
                            if(j != (m.size() - 1)){
                                undoCommand += ",";
                            }
                        }
                        undoCommand += "}";
                    }
                }
            }
            media = ds.define(media, undoCommand, false);
        }else if(s.size() == 4){
            undoCommand = "add " + s[1] + " to " + s[3];
            media = as.add(media,command);
        }
    }

    void Redo(){}

    vector<Media *> getMedia(){
        return media;
    }

private:
    string command;
    string undoCommand;
    vector<Media *> media;
    vector<Media *> media_copy;
};

#endif // DELETEMEDIACOMMAND_H_INCLUDED

