#include "MediaDirector.h"

void MediaDirector::setMediaBuilder(stack<MediaBuilder *> *mbs){
    while(!mbs->empty()){
        media = mbs->top()->getMedia();

        descriptionVisitor *dv = new descriptionVisitor();

        media->accept(dv);

        cout << dv->getDescription() << endl;

        mbs->pop();
    }
}

void MediaDirector::concrete(string content){
    cout << content << endl;
}
