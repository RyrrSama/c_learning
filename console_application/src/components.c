#include "components.h"
#include <math.h>
#include <string.h>

// **************************Static functions

static int lineAlgorithmDDA(COORD startPoint, COORD endPoint, Shape *shape)
{
    // Calculate the differences in X and Y coordinates between the start and
    // end points.
    int xDiff = endPoint.X - startPoint.X;
    int yDiff = endPoint.Y - startPoint.Y;

    // Determine the number of steps required to draw the line based on the
    // larger difference.
    int steps = abs(xDiff) > abs(yDiff) ? abs(xDiff) : abs(yDiff);
    if (shape->edges == NULL)
    {
        shape->edges = (COORD *) malloc(sizeof(COORD) * (steps + 1));
        if (shape->edges == NULL)
        {
            // Handle memory allocation failure
            return -1;
        }
    }
    else
    {
        COORD *newEdges = (COORD *) realloc(
            shape->edges, (sizeof(COORD) * (shape->edgeCount + (steps + 1))));

        if (newEdges == NULL)
        {
            // Handle memory allocation failure
            return -1;
        }
        shape->edges = newEdges;
    }

    // Calculate the increment values for X and Y coordinates per step.
    float xIncrement = xDiff / (float) steps;
    float yIncrement = yDiff / (float) steps;

    // Initialize the floating-point coordinates for the current position.
    float xCoord = startPoint.X;
    float yCoord = startPoint.Y;

    // Loop through each step to draw the line.
    for (int i = shape->edgeCount; i <= (shape->edgeCount + steps); i++)
    {
        COORD tempCoord;
        // Update the drawing point by rounding the floating-point coordinates
        // to the nearest integer.
        tempCoord.X     = (SHORT) round(xCoord);
        tempCoord.Y     = (SHORT) round(yCoord);
        shape->edges[i] = tempCoord;
        // Increment the floating-point coordinates by the calculated
        // increments.
        xCoord += xIncrement;
        yCoord += yIncrement;
    }
    shape->edgeCount += (steps + 1);
    return 0;
}

static void getRectShapeEdges(Shape *shape, LineAlgorithm algorithmType)
{
    if (algorithmType == DDA)
    {
        lineAlgorithmDDA(shape->bottomLeft, shape->bottomRight, shape);
        lineAlgorithmDDA(shape->bottomRight, shape->topRight, shape);
        lineAlgorithmDDA(shape->topRight, shape->topLeft, shape);
        lineAlgorithmDDA(shape->topLeft, shape->bottomLeft, shape);
    }
    else if (algorithmType == BRESENHAM)
    {
    }
}

static void getCustomShapeEdges(Shape *shape, LineAlgorithm algorithmType)
{
    if (algorithmType == DDA)
    {
        for (DWORD pIndex = 0; pIndex < (shape->pointsCount - 1); pIndex++)
        {

            lineAlgorithmDDA(shape->points[pIndex], shape->points[pIndex + 1],
                             &shape);
        }
    }
    else if (algorithmType == BRESENHAM)
    {
    }
}

static void updateShapeEdges(Shape *shape, LineAlgorithm algorithmType)
{
    if (shape->shapeType == RECTSHAPE)
    {
        getRectShapeEdges(shape, algorithmType);
    }
    else if (shape->shapeType == CUSTOMSHAPE)
    {
        getCustomShapeEdges(shape, algorithmType);
    }
}

static COORD getPositionCoord(Shape shape, Position labelPosition)
{
    COORD updateCoord;

    if (labelPosition == BOTTOMLEFT)
    {
        updateCoord   = shape.bottomLeft;
        updateCoord.X = updateCoord.X + shape.height;
        updateCoord.Y = updateCoord.Y - shape.height;
    }
    else if (labelPosition == BOTTOMRIGHT)
    {
        updateCoord   = shape.bottomRight;
        updateCoord.X = updateCoord.X - shape.width;
        updateCoord.Y = updateCoord.Y - shape.height;
    }
    else if (labelPosition == TOPRIGHT)
    {
        updateCoord   = shape.topRight;
        updateCoord.X = updateCoord.X - shape.width;
        updateCoord.Y = updateCoord.Y + shape.height;
    }
    else if (labelPosition == TOPLEFT)
    {
        updateCoord   = shape.topLeft;
        updateCoord.X = updateCoord.X + shape.height;
        updateCoord.Y = updateCoord.Y - shape.height;
    }
    else if (labelPosition == CENTER)
    {
        updateCoord   = shape.center;
        updateCoord.X = updateCoord.X - (shape.width / 2);
    }
    else if (labelPosition == CENTERLEFT)
    {
        updateCoord   = shape.center;
        updateCoord.X = updateCoord.X - shape.width;
    }
    else if (labelPosition == CENTERRIGHT)
    {
        updateCoord = shape.center;
    }
    return updateCoord;
}

// TODO: Remove this function since this is specific for button
static void drawButtonLabel(Button button)
{
    // Calculate the length of the label to determine its offset for centering.
    int offset = strlen(button.label);

    // Get the center coordinate of the button's rectangle.
    COORD labelCoord = button.object.shape.center;

    // Adjust the X-coordinate to center the label horizontally.
    labelCoord.X -= (offset / 2);

    // Set the console cursor position to the calculated label coordinate.
    SetConsoleCursorPosition(button.object.parentBuffer, labelCoord);

    // Write the label text to the console at the calculated position.
    WriteConsole(button.object.parentBuffer, button.label, strlen(button.label),
                 &button.object.noOfCharsWritten, NULL);
}

static void drawShapeEdges(HANDLE consoleBuffer, COORD edges[],
                           DWORD edgesCount, DWORD noOfCharsWritten,
                           char drawChar)
{
    for (DWORD index = 0; index < edgesCount; index++)
    {
        FillConsoleOutputCharacter(consoleBuffer, drawChar, 1, edges[index],
                                   &noOfCharsWritten);
    }
}

static void drawInstance(Instance instance)
{
    drawShapeEdges(instance.parentBuffer, instance.shape.edges,
                   instance.shape.edgeCount, instance.noOfCharsWritten,
                   HBORDERCHAR);
}

// ! Static functions Ended

// ! Internal Support Functions Ended**************

// ************* Shape Instance supportive function
// ! Shape supportive function Ended **************

// * ***********Label instance supportive function
void drawLabel(struct LABEL label)
{
    // Set the console cursor position to the calculated label coordinate.
    SetConsoleCursorPosition(label.object.parentBuffer,
                             label.object.shape.bottomLeft);

    // Write the label text to the console at the calculated position.
    WriteConsole(label.object.parentBuffer, label.text, strlen(label.text),
                 &label.object.noOfCharsWritten, NULL);
}

void setLabel(struct LABEL *label, const char *newText)
{
    // Calculate the length of the new label, including the null terminator.
    int labelLength = strlen(newText) + 1;

    // If the button's label is not yet allocated, allocate memory for it.
    if (!label->text) label->text = (char *) malloc(labelLength * sizeof(char));
    // If the existing label memory is insufficient, resize it to fit the new
    // label.
    else if (strlen(label->text) < labelLength)
        label->text = (char *) realloc(label->text, labelLength * sizeof(char));

    // Copy the new label into the allocated memory, including the null
    // terminator.
    memcpy(label->text, label, labelLength);
}

void setLabelPostion(struct LABEL *label, COORD labelCoord)
{
    label->object.shape.bottomLeft = labelCoord;
}
// ! Label supportive function Ended***************

// * ***********Button instance supportive function

void drawButton(Button button)
{
    drawInstance(button.object);
    drawLabel(button.label);
}

void setButtonText(Button *button, const char *label)
{
    setLabel(&button->label, label);
}

void setButtonLabelPostion(struct BUTTON *button, Position labelPosition)
{
    COORD updateCoord = getPositionCoord(button->object.shape, labelPosition);
    setLabelPostion(&button->label, updateCoord);
}

// ! Button supportive function Ended**************

// *********** Object Supportive function
// *(End users exposed functions)
void addVertex(Shape *shape, COORD vertex)
{
    // TODO: Add dynamic memory allocation for points
    shape->points[shape->pointsCount] = vertex;
    shape->pointsCount += 1;
}

// * ********************Menu supportive function
// *(End users exposed functions)

// ! Menu supportive function********************
// * **************Component Initiate Functions
// * (End Users Useable functions)

Label createLabel(COORD bottomLeft, const char *text)
{
    Label label;
    label.object.shape.bottomLeft = bottomLeft;
}

Shape createRectShape(int bottomLeftX, int bottomLeftY, int width, int height)
{
    Shape rect;
    rect.shapeType    = RECTSHAPE;
    COORD bottomLeft  = {bottomLeftX, bottomLeftY};
    COORD bottomRight = {bottomLeftX + (width - 1), bottomLeftY};
    COORD topLeft     = {bottomLeftX, bottomLeftY - (height - 1)};
    COORD topRight    = {bottomLeftX + (width - 1), bottomLeftY - (height - 1)};
    COORD center      = {bottomLeftX + (width / 2), bottomLeftY - (height / 2)};
    rect.width        = width;
    rect.height       = height;
    rect.bottomLeft   = bottomLeft;
    rect.bottomRight  = bottomRight;
    rect.topLeft      = topLeft;
    rect.topRight     = topRight;
    rect.center       = center;
    rect.edges        = NULL;
    rect.rectRegion   = NULL;
    rect.edgeCount    = 0;
    rect.regionCount  = 0;
    updateShapeEdges(&rect, DDA);
    return rect;
}

Instance createRectInstance(HANDLE parentBuffer, int bottomLeftX,
                            int bottomLeftY, int width, int height)
{
    Instance instance;
    instance.shape = createRectShape(bottomLeftX, bottomLeftY, width, height);
    instance.parentBuffer = parentBuffer;
    instance.draw         = drawInstance;
    return instance;
}

Shape createCustomRectShape(COORD bottomLeft, COORD bottomRight, COORD topRight,
                            COORD topLeft)
{
    Shape customShape;
    customShape.shapeType   = RECTSHAPE;
    customShape.bottomLeft  = bottomLeft;
    customShape.bottomRight = bottomRight;
    customShape.topLeft     = topLeft;
    customShape.topRight    = topRight;
    customShape.width       = bottomRight.X - bottomLeft.X;
    customShape.height      = bottomLeft.Y - topLeft.Y;
    COORD center            = {bottomLeft.X + (customShape.width / 2),
                               bottomLeft.Y - (customShape.height / 2)};
    customShape.center      = center;
    customShape.edges       = NULL;
    customShape.rectRegion  = NULL;
    customShape.edgeCount   = 0;
    customShape.regionCount = 0;
    updateShapeEdges(&customShape, DDA);
    return customShape;
}

Instance createCustomRectInstance(HANDLE parentBuffer, COORD bottomLeft,
                                  COORD bottomRight, COORD topRight,
                                  COORD topLeft)
{
    Instance customRect;
    customRect.shape =
        createCustomRectShape(bottomLeft, bottomRight, topRight, topLeft);
    customRect.parentBuffer = parentBuffer;
    customRect.draw         = drawInstance;
    return customRect;
}

Button createButton(HANDLE parentBuffer, const char *label, int bottomLeftX,
                    int bottomLeftY, int width, int height)
{
    Button button;
    button.object.parentBuffer = parentBuffer;
    button.object.shape =
        createRectShape(bottomLeftX, bottomLeftY, width, height);

    button.drawButton = drawButton;
    button.setLabel   = setLabel;
    return button;
}