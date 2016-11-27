#include "Text.h"

Text::Text(Rectangle boundingbox, string text){
    rec = &boundingbox;
    desc = rec->description();
    context = text;
}

double Text::area(){
    return rec->area();
}

double Text::perimeter(){
    return rec->perimeter();
}

string Text::description(){
    return desc;
}

string Text::getText(){
    return context;
}
