#include "../src/WinMain.h"
#include "VisualNovel.h"
#include <iostream>
#include <vector>

DialogueBox::DialogueBox(int posX, int posY, int boxWidth, int boxHeight, const char* boxImagePath, int fontSize) {
    x = posX;
    y = posY;
    width = boxWidth;
    height = boxHeight;

    //boxImage.Load(boxImagePath);

    currentTextIndex = 0;
}

void DialogueBox::AddText(const std::string& text) {
    dialogueTexts.push_back(text);
}

void DialogueBox::DisplayText() {
    //DrawGraph(x, y, boxImage, TRUE);
    int width = 50;
    int height = 50;
    x = WINDOW_W_HALF;
    y = WINDOW_H_HALF;
    DrawBox(x-width,y-height, x + width, y + width,BLACK,1);
    if (currentTextIndex < dialogueTexts.size()) {
        DrawString(x + 10, y + 10, dialogueTexts[currentTextIndex].c_str(), GetColor(0, 0, 0), 0);
    }
}

void DialogueBox::SetPosition(int posX, int posY) {
    x = posX;
    y = posY;
}

void DialogueBox::NextText() {
    if (currentTextIndex < dialogueTexts.size() - 1) 
    {
        currentTextIndex++;
    }
}

size_t DialogueBox::GetDialogueTextsSize()
{
    return dialogueTexts.size();
}

size_t DialogueBox::GetCurrentTextIndex()
{
    return currentTextIndex;
}