#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

class Command {
public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
    virtual void Redo() = 0;
    virtual vector<Media *> getMedia() = 0;
};

#endif // COMMAND_H_INCLUDED
