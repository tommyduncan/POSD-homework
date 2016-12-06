#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<string.h>
#include<stdlib.h>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

using namespace std;

int main()
{
    string input, cmd, shapeType, shapeName, shape1, shape2;
    char *c_input, *c_cmd, *c_shapeType, *c_shapeName, *shapeDetail, *param;
    int x, y, r, length, width, index;
    regex area("[A-Za-z0-9]*.area[\?]");
    regex perimeter("[A-Za-z0-9]*.perimeter[\?]");
    vector<Media *> mediaVector;
    vector<string> mediaIndex;
    Shape *shape;
    Media *media;

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
                shapeDetail = strtok(NULL, " ");
                shapeDetail = strtok(NULL, "\0");

                if(shapeDetail[0] == 'c')
                    c_shapeType = strtok(shapeDetail, "{");
                else
                    c_shapeType = strtok(shapeDetail, "(");

                shapeType.assign(c_shapeType);

                if(shapeType == "Circle")
                {
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
                {
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
                }
                else if(shapeType == "combo")
                {
                    param = strtok(NULL, ",");
                    shape1.assign(param);
                    param = strtok(NULL, "}");
                    shape2.assign(param);

                    media = new ComboMedia(shapeName);

                    for(unsigned int i = 0; i < mediaIndex.size(); i++)
                    {
                        if(mediaIndex[i] == shape1)
                        {
                            index = i;
                            break;
                        }
                        else
                        {
                            index = -1;
                        }
                    }
                    media->add(mediaVector[index]);

                    for(unsigned int i = 0; i < mediaIndex.size(); i++)
                    {
                        if(mediaIndex[i] == shape2)
                        {
                            index = i;
                            break;
                        }
                        else
                        {
                            index = -1;
                        }
                    }
                    media->add(mediaVector[index]);

                    mediaVector.push_back(media);
                    mediaIndex.push_back(shapeName);
                }
            }
            else if(cmd == "add")
                cout << ">> " << cmd << endl;
            else if(cmd == "delete")
                cout << ">> " << cmd << endl;
            else if(cmd == "show")
            {
                for(unsigned int i = 0; i < mediaIndex.size(); i++)
                {
                    cout << "  " << mediaIndex[i] << endl;
                }
            }
            else if(cmd == "save")
                cout << ">> " << cmd << endl;
            else if(cmd == "load")
                cout << ">> " << cmd << endl;
            else
                cout << ">> Error: Invalid command !" << endl;
        }
        free(c_input);
        free(c_cmd);
        free(c_shapeType);
        free(c_shapeName);
        free(shapeDetail);
        free(param);
    }
    return 0;
}
