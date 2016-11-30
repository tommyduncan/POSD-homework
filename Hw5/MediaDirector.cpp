#include "MediaDirector.h"

void MediaDirector::setMediaBuilder(stack<MediaBuilder *> *mbs){
    unsigned int i = 0;
    while(!mbs->empty()){
        mediaBuilder[i] = mbs->top();

        mbs->pop();
        i++;
    }
    for(unsigned int j = i - 1; j > 0; j--){
        mediaBuilder[i - 1]->buildShapeMedia(mediaBuilder[j - 1]->getMedia());
    }

    descriptionVisitor dv;
    Media *media = mediaBuilder[i - 1]->getMedia();

    media->accept(&dv);

    result = dv.getDescription();
}

void MediaDirector::concrete(string content){
    cout << content << endl;
}

string MediaDirector::getResult(){
    return result;
}
