#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<string.h>
#include<stdlib.h>
#include<fstream>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "Visitor.h"

using namespace std;

int main()
{
    fstream file;
    regex area("[A-Za-z0-9]*.area[\?]");
    regex perimeter("[A-Za-z0-9]*.perimeter[\?]");
    int x1, y1, x2, y2, x3, y3, index = -1;
    unsigned int x, y, r, length, width, commaCounter, paramCounter, parenthCounter, counter;
    char *c_input, *c_cmd, *c_shapeType, *c_shapeName, *c_fileName, *c_shapeDetail, *param, *temp, *pEnd, buffer1[128] = {0}, buffer2[128] = {0}, shapeChar[128];
    string input, cmd, shapeType, shapeName, comboName, fileName, shapeDetail, contentShape[10], writeString1, writeString2, temporary;
    vector<Media *> mediaVector;
    vector<string> mediaIndex, contentName;
    Shape *shape;
    Media *media, *comboMedia;
    descriptionVisitor dv;

    while(1)
    {
        cout << ":- ";
        getline(cin, input);
        c_input = (char *)malloc(sizeof(char) * strlen(input.c_str()));

        if(regex_match(input, area))
        {
            strcpy(c_input, input.c_str());
            c_shapeName = strtok(c_input, ".");
            shapeName.assign(c_shapeName);

            for(unsigned int i = 0; i < mediaIndex.size(); i++)
            {
                if(mediaIndex[i] == shapeName)
                {
                    index = i;
                    break;
                }
                else
                {
                    index = -1;
                }
            }
            if(index == -1)
                cout << ">> Cannot find any shape named" << shapeName << endl;
            else
                cout << ">> " << mediaVector[index]->area() << endl;
        }
        else if(regex_match(input, perimeter))
        {
            strcpy(c_input, input.c_str());
            c_shapeName = strtok(c_input, ".");
            shapeName.assign(c_shapeName);

            for(unsigned int i = 0; i < mediaIndex.size(); i++){
                if(mediaIndex[i] == shapeName){
                    index = i;
                    break;
                }else{
                    index = -1;
                }
            }

            if(index == -1)
                cout << ">> Cannot find any shape named" << shapeName << endl;
            else
                cout << ">> " << mediaVector[index]->perimeter() << endl;
        }
        else
        {
            strcpy(c_input, input.c_str());
            c_cmd = strtok(c_input, " ");
            cmd.assign(c_cmd);

            if(cmd == "def")
            {
                c_shapeName = strtok(NULL, " ");
                shapeName.assign(c_shapeName);

                /* �j�M�O�_�����ƦW�٪�Shape */
                for(unsigned int i = 0; i < mediaIndex.size(); i++){
                    if(mediaIndex[i] == shapeName){
                        index = i;
                        break;
                    }else{
                        index = -1;
                    }
                }
                if(index != -1){
                    cout << ">> \"" << shapeName << "\" has already existed." << endl;
                    continue;
                }

                c_shapeDetail = strtok(NULL, " ");
                c_shapeDetail = strtok(NULL, "\0");

                if(c_shapeDetail[0] == 'c')
                    c_shapeType = strtok(c_shapeDetail, "{");
                else
                    c_shapeType = strtok(c_shapeDetail, "(");

                shapeType.assign(c_shapeType);

                if(shapeType == "Circle")
                {   /* ���ΥXCircle����ߥH�Υb�|�� */
                    param = strtok(NULL, ",");
                    x = atoi(param);
                    param = strtok(NULL, ",");
                    y = atoi(param);
                    param = strtok(NULL, ")");
                    r = atoi(param);

                    shape = new Circle(x, y, r);
                    media = new ShapeMedia(shape, shapeName);

                    mediaVector.push_back(media);
                    mediaIndex.push_back(shapeName);
                }
                else if(shapeType == "Rectangle")
                {   /* ���ΥXRectangle�����W���I�H�Ϊ��B�e */
                    param = strtok(NULL, ",");
                    x = atoi(param);
                    param = strtok(NULL, ",");
                    y = atoi(param);
                    param = strtok(NULL, ", ");
                    length = atoi(param);
                    param = strtok(NULL, ")");
                    width = atoi(param);

                    shape = new Rectangle(x, y, length, width);
                    media = new ShapeMedia(shape, shapeName);

                    mediaVector.push_back(media);
                    mediaIndex.push_back(shapeName);
                }else if(shapeType == "Triangle")
                {   /* ����Triangle���T�ӳ��I�y�� */
                    param = strtok(NULL, ",");
                    x1 = atoi(param);
                    param = strtok(NULL, ",");
                    y1 = atoi(param);
                    param = strtok(NULL, ", ");
                    x2 = atoi(param);
                    param = strtok(NULL, ", ");
                    y2 = atoi(param);
                    param = strtok(NULL, ", ");
                    x3 = atoi(param);
                    param = strtok(NULL, ")");
                    y3 = atoi(param);

                    shape = new Triangle(x1, y1, x2, y2, x3, y3);
                    media = new ShapeMedia(shape, shapeName);

                    mediaVector.push_back(media);
                    mediaIndex.push_back(shapeName);
                }else if(shapeType == "combo"){
                    commaCounter = 0;
                    temp = strtok(NULL, "}");
                    for(unsigned int i = 0; temp[i] != '\0'; i++){
                        if(temp[i] == ','){
                            commaCounter++;
                        }
                    }

                    paramCounter = 0;
                    param = strtok(temp, ",");
                    contentShape[paramCounter].assign(param);
                    paramCounter ++;
                    for(unsigned int i = 0; i < commaCounter; i++, paramCounter++){
                        if(i < commaCounter - 1){
                            param = strtok(NULL, ",");
                            contentShape[paramCounter].assign(param);
                        }else{
                            param = strtok(NULL, "\0");
                            contentShape[paramCounter].assign(param);
                        }
                    }

                    media = new ComboMedia(shapeName);

                    for(unsigned int i = 0; i < paramCounter; i++){
                        for(unsigned int j = 0; j < mediaIndex.size(); j++){
                            if(mediaIndex[j] == contentShape[i]){
                                index = j;
                                break;
                            }else{
                                index = -1;
                            }
                        }
                        media->add(mediaVector[index]);
                    }

                    mediaVector.push_back(media);
                    mediaIndex.push_back(shapeName);
                }
            }
            else if(cmd == "add"){
                c_shapeName = strtok(NULL, " ");    /* ���XShapeMedia���W�� */
                shapeName.assign(c_shapeName);

                /* �qmediaIndex��X������Shape Name */
                for(unsigned int i = 0; i < mediaIndex.size(); i++){
                    if(mediaIndex[i] == shapeName){
                        index = i;
                        break;
                    }else{
                        index = -1;
                    }
                }
                x = index;

                c_shapeName = strtok(NULL, " ");
                c_shapeName = strtok(NULL, "\0");   /* ���XComboMedia���W�� */
                shapeName.assign(c_shapeName);

                /* �j�M�X���[�J��ComboMedia */
                for(unsigned int i = 0; i < mediaIndex.size(); i++){
                    if(mediaIndex[i] == shapeName){
                        index = i;
                        break;
                    }else{
                        index = -1;
                    }
                }
                y = index;

                mediaVector[y]->add(mediaVector[x]);    /* �NShapeMedia�[�J�iComboMedia�� */
            }
            else if(cmd == "delete"){
                c_shapeName = strtok(NULL, " ");
                shapeName.assign(c_shapeName);
                temp = strtok(NULL, " ");

                /* �P�_delete���榡 */
                if(!temp){
                    for(unsigned int i = 0; i < mediaIndex.size(); i++){
                        if(mediaIndex[i] == shapeName){
                            index = i;
                            break;
                        }else{
                            index = -1;
                        }
                    }
                    mediaIndex.erase(mediaIndex.begin() + index);
                    mediaVector.erase(mediaVector.begin() + index);
                }else{
                    temp = strtok(NULL, " ");
                    comboName.assign(temp);

                    for(unsigned int i = 0; i < mediaIndex.size(); i++){
                        if(mediaIndex[i] == comboName){
                            index = i;
                            break;
                        }else{
                            index = -1;
                        }
                    }
                    mediaVector[index]->remove(shapeName);
                }
            }
            else if(cmd == "show"){
                for(unsigned int i = 0; i < mediaIndex.size(); i++){
                    cout << "   " << mediaIndex[i] << endl;
                }
            }
            else if(cmd == "save"){
                c_shapeName = strtok(NULL, " ");
                shapeName.assign(c_shapeName);
                c_fileName = strtok(NULL, "\"");
                c_fileName = strtok(NULL, "\"");    /* �N����X���ɮצW�٤��ΥX�� */
                fileName.assign(c_fileName);    /* �N�ɮצW�ٱq"char *"���A�ഫ��"std::string"���A */

                /* �j�M����X��ComboMedia */
                for(unsigned int i = 0; i < mediaIndex.size(); i++){
                    if(mediaIndex[i] == shapeName){
                        index = i;
                        break;
                    }else{
                        index = -1;
                    }
                }

                /* ���description */
                mediaVector[index]->accept(&dv);
                contentName = dv.getContentName();
                writeString1 = dv.getDescription();

                /* �B�z����XShape���W�� */
                for(unsigned int i = 0; i < contentName.size(); i++){
                    writeString2 += contentName[i];
                    if(i < contentName.size() - 1)
                        writeString2 += " ";
                }

                /* �}�ɡB�g��... */
                file.open(fileName, ios::out);
                if(!file){
                    cout << ">> Fail to open file !" << endl;
                }else{
                    file << writeString1 << endl << shapeName << "{" << writeString2 << "}" << endl;
                }
                file.close();
                cout << ">> " << shapeName << " saved to " << fileName << endl;
            }
            else if(cmd == "load"){
                c_fileName = strtok(NULL, "\"");
                fileName.assign(c_fileName);

                cout << ">> loading " << fileName << " ..." << endl;

                file.open(fileName, ios::in);
                if(!file){
                    cout << ">> Fail to open file !" << endl;
                }else{
                    file.getline(buffer1, sizeof(buffer1));
                    file.getline(buffer2, sizeof(buffer2));

                    /* �p��ĬA�����ƶq */
                    parenthCounter = 0;
                    for(unsigned int i = 0; buffer1[i] != '\0'; i++){
                        if(buffer1[i] == '('){
                            parenthCounter++;
                        }
                    }

                    /* �B�z�ĤG��Load�i�Ӫ�Shape�W�� */
                    param = strtok(buffer2, "{");
                    shapeName.assign(param);
                    comboMedia = new ComboMedia(shapeName);
                    for(unsigned int i = 0; i < parenthCounter - 1; i++){
                            if(i < parenthCounter - 2){
                                param = strtok(NULL, " ");
                                contentShape[i].assign(param);
                            }else{
                                param = strtok(NULL, "}");
                                contentShape[i].assign(param);
                            }
                    }

                    /* �B�z�Ĥ@��Load�i�Ӫ�Shape�A�óЫ� */
                    c_shapeDetail = strtok(buffer1, "(");
                    for(unsigned int i = 0; i < parenthCounter - 1; i++){
                        c_shapeDetail = strtok(NULL, ")");
                        if(*c_shapeDetail == 'r'){
                            for(counter = 0; c_shapeDetail[counter] != '\0'; counter++){
                                shapeChar[counter] = c_shapeDetail[counter + 2];
                            }
                            shapeChar[counter] = '\0';

                            x = (int)strtol(shapeChar, &pEnd, 10);
                            y = (int)strtol(pEnd, &pEnd, 10);
                            length = (int)strtol(pEnd, &pEnd, 10);
                            width = (int)strtol(pEnd, &pEnd, 10);

                            shape = new Rectangle(x, y, length, width);
                            media = new ShapeMedia(shape, contentShape[i]);
                            comboMedia->add(media);
                        }else if(*c_shapeDetail == 'c'){
                            for(counter = 0; c_shapeDetail[counter] != '\0'; counter++){
                                shapeChar[counter] = c_shapeDetail[counter + 2];
                            }
                            shapeChar[counter] = '\0';

                            x = (int)strtol(shapeChar, &pEnd, 10);
                            y = (int)strtol(pEnd, &pEnd, 10);
                            r = (int)strtol(pEnd, &pEnd, 10);

                            shape = new Circle(x, y, r);
                            media = new ShapeMedia(shape, contentShape[i]);
                            comboMedia->add(media);
                        }else if(*c_shapeDetail == 't'){
                            for(counter = 0; c_shapeDetail[counter] != '\0'; counter++){
                                shapeChar[counter] = c_shapeDetail[counter + 2];
                            }
                            shapeChar[counter] = '\0';

                            x1 = (int)strtol(shapeChar, &pEnd, 10);
                            y1 = (int)strtol(pEnd, &pEnd, 10);
                            x2 = (int)strtol(pEnd, &pEnd, 10);
                            y2 = (int)strtol(pEnd, &pEnd, 10);
                            x3 = (int)strtol(pEnd, &pEnd, 10);
                            y3 = (int)strtol(pEnd, &pEnd, 10);

                            shape = new Triangle(x1, y1, x2, y2, x3, y3);
                            media = new ShapeMedia(shape, contentShape[i]);
                            comboMedia->add(media);
                        }
                    }
                    mediaIndex.push_back(shapeName);
                    mediaVector.push_back(comboMedia);

                    /* ����O����Ŷ��B��l��buffer�ܼ� */
                    memset(buffer1, '\0', 128);
                    memset(buffer2, '\0', 128);
                    file.close();

                    file.open(fileName, ios::in);
                    file.getline(buffer1, sizeof(buffer1));
                    file.getline(buffer2, sizeof(buffer2));
                    file.close();

                    cout << "   " << shapeName << " = " << buffer2 << " = " << buffer1 << endl;
                }
            }
            else
                cout << ">> Error: Invalid command !" << endl;
        }
    }
    return 0;
}
