#ifndef MEDIABUILDER_H_INCLUDED
#define MEDIABUILDER_H_INCLUDED

#include "Shape.h"
#include "Media.h"
#include "Text.h"
#include "TextMedia.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

class MediaBuilder
{
public:
    virtual void buildComboMedia() = 0;
    virtual void buildShapeMedia(Shape *s) = 0;
    virtual void buildShapeMedia(Media *m) = 0;
    virtual Media *getMedia() const = 0;

private:

};

class ShapeMediaBuilder : public MediaBuilder
{
public:
    ShapeMediaBuilder();
    void buildShapeMedia(Shape *s);
    void buildShapeMedia(Media *m);
    void buildComboMedia();
    Media *getMedia() const;
    //ShapeMedia *getShapeMedia() const;

private:
    ShapeMedia *sm;
};

class ComboMediaBuilder : public MediaBuilder{
public:
    ComboMediaBuilder();
    void buildShapeMedia(Shape *s);
    void buildShapeMedia(Media *m);
    void buildComboMedia();
    Media *getMedia() const;
    //ComboMedia *getComboMedia() const;
    ShapeMedia *findMedia(Shape *s);

private:
    ComboMedia *cm;
    vector<ShapeMedia *> mediaIndex;
};

#endif
