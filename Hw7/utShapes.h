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

TEST(Problem2_1, Hw7){    // Execute command
    string cmd = "def cSmall = Circle(0,0,10)";
    Command *currentCMD;
    vector<Media *> media;
    CommandManager cmdManager;

    DefineMediaCommand dmc(media, cmd);
    cmdManager.ExecuteCMD(&dmc);
    media = dmc.getMedia();

    if(media.size() == 1){
        DOUBLES_EQUAL(300, media[0]->area(), epsilon);
    }else{
        FAIL("Problem2-1 test failed !");
    }
}

TEST(Problem2_2, Hw7){    // Undo command
    string cmd = "def cSmall = Circle(0,0,10)";
    Command *currentCMD;
    vector<Media *> media;
    CommandManager cmdManager;

    DefineMediaCommand dmc(media, cmd);
    cmdManager.ExecuteCMD(&dmc);
    media = dmc.getMedia();

    cmdManager.UndoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    if(media.size() == 0){
        DOUBLES_EQUAL(0, media.size(), epsilon);
    }else{
        FAIL("Problem2-2 test failed !");
    }
}

TEST(Problem2_3, Hw7){    // Redo command
    string cmd = "def cSmall = Circle(0,0,10)";
    Command *currentCMD;
    vector<Media *> media;
    CommandManager cmdManager;

    DefineMediaCommand dmc(media, cmd);
    cmdManager.ExecuteCMD(&dmc);
    media = dmc.getMedia();

    cmdManager.UndoCMD();
    cmdManager.RedoCMD();

    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    if(media.size() == 1){
        DOUBLES_EQUAL(300, media[0]->area(), epsilon);
    }else{
        FAIL("Problem2-3 test failed !");
    }
}

TEST(Problem3, Hw7){    // Undo/Redo "add" command
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

    AddMediaCommand amc(media, cmd5);
    cmdManager.ExecuteCMD(&amc);
    media = amc.getMedia();

    cmdManager.UndoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(320, media[2]->area(), epsilon);

    cmdManager.RedoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(512, media[2]->area(), epsilon);
}

TEST(Problem4, Hw7){    // Undo/Redo "define" command
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

    DOUBLES_EQUAL(1, media.size(), epsilon);
    DOUBLES_EQUAL(300, media[0]->area(), epsilon);

    cmdManager.RedoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(2, media.size(), epsilon);
    DOUBLES_EQUAL(20, media[1]->area(), epsilon);
}

TEST(Problem5_1_1, Hw7){    // Undo/Redo delete shapeMedia
    string cmd1 = "def cSmall = Circle(0,0,10)";
    string cmd2 = "delete cSmall";
    Command *currentCMD;
    vector<Media *> media;
    CommandManager cmdManager;

    DefineMediaCommand dmc1(media, cmd1);
    cmdManager.ExecuteCMD(&dmc1);
    media = dmc1.getMedia();

    DeleteMediaCommand dmc2(media, cmd2);
    cmdManager.ExecuteCMD(&dmc2);
    media = dmc2.getMedia();

    cmdManager.UndoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(1, media.size(), epsilon);

    cmdManager.RedoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(0, media.size(), epsilon);
}

TEST(Problem5_1_2, Hw7){    // Undo/Redo delete comboMedia
    string cmd1 = "def cSmall = Circle(0,0,10)";
    string cmd2 = "def combo1 = combo{cSmall}";
    string cmd3 = "delete combo1";

    Command *currentCMD;
    vector<Media *> media;
    CommandManager cmdManager;

    DefineMediaCommand dmc1(media, cmd1);
    cmdManager.ExecuteCMD(&dmc1);
    media = dmc1.getMedia();

    DefineMediaCommand dmc2(media, cmd2);
    cmdManager.ExecuteCMD(&dmc2);
    media = dmc2.getMedia();

    DeleteMediaCommand dmc3(media, cmd3);
    cmdManager.ExecuteCMD(&dmc3);
    media = dmc3.getMedia();

    cmdManager.UndoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(2, media.size(), epsilon);

    cmdManager.RedoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    DOUBLES_EQUAL(1, media.size(), epsilon);
}

TEST(Problem5_2, Hw7){    // Undo/Redo delete shapeMedia form comboMedia
    string cmd1 = "def cSmall = Circle(0,0,10)";
    string cmd2 = "def rTall = Rectangle(0,0,4,5)";
    string cmd3 = "def comboExclamation = combo{rTall,cSmall}";
    string cmd4 = "def cMid = Circle(0,0,8)";
    string cmd5 = "add cMid to comboExclamation";
    string cmd6 = "delete rTall from comboExclamation";
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

    AddMediaCommand amc(media, cmd5);
    cmdManager.ExecuteCMD(&amc);
    media = amc.getMedia();

    DeleteMediaCommand dmc5(media, cmd6);
    cmdManager.ExecuteCMD(&dmc5);
    media = dmc5.getMedia();

    cmdManager.UndoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    if(media.size() == 4){
        DOUBLES_EQUAL(512, media[2]->area(), epsilon);
    }else{
        FAIL("Problem5-2 test failed !");
    }

    cmdManager.RedoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    if(media.size() == 4){
        DOUBLES_EQUAL(492, media[2]->area(), epsilon);
    }else{
        FAIL("Problem5-2 test failed !");
    }
}

TEST(Problem5_3, Hw7){    // Undo/Redo delete comboMedia form comboMedia
    string cmd1 = "def circle1 = Circle(0,0,10)";
    string cmd2 = "def rectangle = Rectangle(0,0,4,5)";
    string cmd3 = "def circle2 = Circle(5,5,8)";
    string cmd4 = "def combo1 = combo{rectangle,circle1}";
    string cmd5 = "def combo2 = combo{rectangle,circle2}";
    string cmd6 = "add combo2 to combo1";
    string cmd7 = "delete combo2 from combo1";
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

    AddMediaCommand amc(media, cmd6);
    cmdManager.ExecuteCMD(&amc);
    media = amc.getMedia();

    DeleteMediaCommand dmc6(media, cmd7);
    cmdManager.ExecuteCMD(&dmc6);
    media = dmc6.getMedia();

    cmdManager.UndoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    if(media.size() == 5){
        DOUBLES_EQUAL(532, media[3]->area(), epsilon);
    }else{
        FAIL("Problem5-3 test failed !");
    }

    cmdManager.RedoCMD();
    currentCMD = cmdManager.getCurrentCMD();
    media = currentCMD->getMedia();

    if(media.size() == 5){
        DOUBLES_EQUAL(320, media[3]->area(), epsilon);
    }else{
        FAIL("Problem5-3 test failed !");
    }
}

#endif // UTSHAPES_H_INCLUDED










