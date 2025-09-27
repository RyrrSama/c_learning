#ifndef COMPONENTS_H
#define COMPONENTS_H
#define HBORDERCHAR '#'
#define VBORDERCHAR '|'

//  Imports
#include <stdio.h>
#include <windows.h>

typedef enum
{
    RECTSHAPE,
    CUSTOMSHAPE,
} ShapeType;

typedef enum
{
    TOPLEFT,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT,
    CENTERLEFT,
    CENTERRIGHT,
    LEFT,
    RIGHT,
    CENTER,
    UP,
    DOWN
} Position;

typedef enum
{
    DDA,
    BRESENHAM
} LineAlgorithm;

typedef struct SHAPE
{
    // ** Common Perperties
    ShapeType shapeType;
    DWORD width, height;
    COORD *edges, center;
    // ** Rect properties
    COORD bottomLeft, bottomRight, topLeft, topRight, *rectRegion;
    // ** Custom Shape properties
    COORD *points;
    DWORD pointsCount, edgeCount, regionCount;
} Shape;

typedef struct INSTANCE
{
    // TODO: separate Console properties to different Struct(Maybe)
    HANDLE parentBuffer;
    CONSOLE_SCREEN_BUFFER_INFO parentBufferInfo;
    DWORD noOfCharsWritten;
    // ** Shape Properties of the object
    Shape shape;
    // ** Support Function for object
    void (*addVertex)(Shape shape, COORD vertex);
    void (*draw)(struct INSTANCE instance);
} Instance;

typedef struct LABEL
{
    Instance object;
    char *text;
    void (*setLabel)(struct LABEL *label, const char *newText);
    void (*setLabelPostion)(struct LABEL *label, COORD labelCoord);
} Label;

typedef struct BUTTON
{
    Instance object;
    Label label;
    void (*drawButton)(struct BUTTON button);
    void (*setButtonText)(struct BUTTON *button, const char *text);
    void (*setButtonLabelPostion)(struct BUTTON *button,
                                  Position labelPosition);
} Button;

typedef struct DIALOG
{
    Instance object;
    Instance *item;
    void (*addButton)(struct DIALOG dialog, Button button,
                      Position buttonPostion);
    void (*addNewItem)(struct DIALOG dialog, void *Instance);
    void (*drawDialog)(struct DIALOG dialog);
} Dialog;

// Function declaration
//* ************* Internal Support Functions

// ! DEPRECATED: changed to static function
// int lineAlgorithmDDA(COORD startPoint, COORD endPoint, Shape *shape);
// void updateShapeEdges(Shape *shape, LineAlgorithm algorithmType);
// void drawLabel(Button button);
// void drawButton(Button button);
// void drawShapeEdges(HANDLE consoleBuffer, COORD edges[], DWORD edgesCount,
//     DWORD noOfCharsWritten, char drawChar);
// int getParentScreenBufferInfo(Instance *instance);
// ! Internal Support Function Ended**************

// ************* Shape Instance supportive function

// ! Shape supportive function Ended **************

//  * **********Label instance supportive function
void setLabel(Label *label, const char *labelText);
void setLabelPosition(Label *label, COORD labelCoord);
//  ! Label instance supportive function

// * ***********Button instance supportive function
void setButtonText(struct BUTTON *button, const char *text);
void setButtonLabelPostion(struct BUTTON *button, Position labelPosition);

// ! Button supportive function Ended**************

// *********** Object Supportive function
// *(End users exposed functions)
void addVertex(Shape *shape, COORD vertex);

// ! TODO: Rename to general function name draw
void drawRect(Shape shape);
void drawCustomRect(Shape shape);
// ! Object Supportive function ended***********

// TODO: Not implemented function
// * ********************Dialog supportive function
// *(End users exposed functions)
void addNewItem(Dialog *dialog, char *label, COORD labelPostion);
// *(Internal functions)
void drawDialog(Dialog dialog);
// ! Dialog supportive function********************

// * **************Component Initiate Functions
// * (End Users Useable functions)
Shape createRectShape(int bottomLeftX, int bottomLeftY, int width, int height);
Shape createCustomRectShape(COORD bottomLeft, COORD bottomRight, COORD topRight,
                            COORD topLeft);

Instance createObject(HANDLE parentBuffer);

Instance createRectInstance(HANDLE parentBuffer, int bottomLeftX,
                            int bottomLeftY, int width, int height);

Instance createCustomRectInstance(HANDLE parentBuffer, COORD bottomLeft,
                                  COORD bottomRight, COORD topRight,
                                  COORD topLeft);

Button createButton(HANDLE parentBuffer, const char *label, int bottomLeftX,
                    int bottomLeftY, int width, int height);

Instance createDialog(HANDLE parentBuffer, int bottomLeftX, int bottomLeftY,
                      int width, int height);
// ! Component Initiate Functions(End Users Useable functions)***************

// ! Deprecated function need to remove
void drawLineDDA(HANDLE consoleBuffer, DWORD noOfCharsWritten, COORD startPoint,
                 COORD endPoint, char drawChar);
void drawLineCustom(HANDLE consoleBuffer, DWORD noOfCharsWritten,
                    COORD startPoint, COORD endPoint, char drawChar);

#endif