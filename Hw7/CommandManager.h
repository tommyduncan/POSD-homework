#ifndef COMMANDMANAGER_H_INCLUDED
#define COMMANDMANAGER_H_INCLUDED

#include <stack>
#include "Command.h"

class CommandManager {
public:
    CommandManager(){}

    void ExecuteCMD(Command *cmd){
        cmd->Execute();
        undocmds.push(cmd);
    }

    void RedoCMD(){
        currentCMD = redocmds.top();
        redocmds.pop();
        currentCMD->Execute();
        undocmds.push(currentCMD);
    }

    void UndoCMD(){
        currentCMD = undocmds.top();
        undocmds.pop();
        currentCMD->Undo();
        redocmds.push(currentCMD);
    }

    Command *getCurrentCMD(){
        return currentCMD;
    }

private:
    stack<Command *> undocmds;
    stack<Command *> redocmds;
    Command *currentCMD;
};

#endif // COMMANDMANAGER_H_INCLUDED
