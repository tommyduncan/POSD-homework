#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Shapes.h"
#include "ShapeMedia.h"
#include <vector>
#include "MyDocument.h"
#include <string>
#include <cstring>
#include "Instruction.h"
#include "CommandManager.h"
#include "DefineMediaCommand.h"

const double epsilon = 0.000001;

TEST(defineUndo, Command_Pattern){
    string cmd1 = "def cSmall = Circle(0,0,10)";
    string cmd2 = "def rTall = Rectangle(0,0,4,5)";
    Command *currentCMD;
    vector<Media *> media;
    CommandManager cmdManager;

    DefineMediaCommand dmc1(media, cmd1);
    cmdManager.ExecuteCMD(&dmc1);
    media = dmc1.getMedia();

    DefineMediaCommand dmc2(media, cmd2);
    cmdManager.ExecuteCMD(&dmc2);
    media = dmc2.getMedia();

    cmdManager.UndoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(300, media[0]->area(), epsilon);
}

TEST(defineRedo, Command_Pattern){
    string cmd1 = "def cSmall = Circle(0,0,10)";
    string cmd2 = "def rTall = Rectangle(0,0,4,5)";
    Command *currentCMD;
    vector<Media *> media;
    CommandManager cmdManager;

    DefineMediaCommand dmc1(media, cmd1);
    cmdManager.ExecuteCMD(&dmc1);
    media = dmc1.getMedia();

    DefineMediaCommand dmc2(media, cmd2);
    cmdManager.ExecuteCMD(&dmc2);
    media = dmc2.getMedia();

    cmdManager.UndoCMD();
    cmdManager.RedoCMD();

    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(20, media[1]->area(), epsilon);
}

TEST(AddUndo, Command_Pattern){
    string cmd1 = "def cSmall = Circle(0,0,10)";
    string cmd2 = "def rTall = Rectangle(0,0,4,5)";
    string cmd3 = "def comboExclamation = combo{rTall,cSmall}";
    string cmd4 = "def cMid = Circle(0,0,8)";
    string cmd5 = "add cMid to comboExclamation";
    Command *currentCMD;
    vector<Media *> media;
    CommandManager cmdManager;

    DefineMediaCommand dmc1(media, cmd1);
    cmdManager.ExecuteCMD(&dmc1);
    media = dmc1.getMedia();

    DefineMediaCommand dmc2(media, cmd2);
    cmdManager.ExecuteCMD(&dmc2);
    media = dmc2.getMedia();

    DefineMediaCommand dmc3(media, cmd3);
    cmdManager.ExecuteCMD(&dmc3);
    media = dmc3.getMedia();

    DefineMediaCommand dmc4(media, cmd4);
    cmdManager.ExecuteCMD(&dmc4);
    media = dmc4.getMedia();

    DefineMediaCommand dmc5(media, cmd5);
    cmdManager.ExecuteCMD(&dmc5);
    media = dmc5.getMedia();

    cmdManager.UndoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(320, media[2]->area(), epsilon);
}

TEST(AddRedo, Command_Pattern){
    string cmd1 = "def cSmall = Circle(0,0,10)";
    string cmd2 = "def rTall = Rectangle(0,0,4,5)";
    string cmd3 = "def comboExclamation = combo{rTall,cSmall}";
    string cmd4 = "def cMid = Circle(0,0,8)";
    string cmd5 = "add cMid to comboExclamation";
    Command *currentCMD;
    vector<Media *> media;
    CommandManager cmdManager;

    DefineMediaCommand dmc1(media, cmd1);
    cmdManager.ExecuteCMD(&dmc1);
    media = dmc1.getMedia();

    DefineMediaCommand dmc2(media, cmd2);
    cmdManager.ExecuteCMD(&dmc2);
    media = dmc2.getMedia();

    DefineMediaCommand dmc3(media, cmd3);
    cmdManager.ExecuteCMD(&dmc3);
    media = dmc3.getMedia();

    DefineMediaCommand dmc4(media, cmd4);
    cmdManager.ExecuteCMD(&dmc4);
    media = dmc4.getMedia();

    DefineMediaCommand dmc5(media, cmd5);
    cmdManager.ExecuteCMD(&dmc5);
    media = dmc5.getMedia();

    /*cmdManager.UndoCMD();
    cmdManager.RedoCMD();

    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();*/

    DOUBLES_EQUAL(320, media[2]->area(), epsilon);
}

#endif // UTSHAPES_H_INCLUDED










