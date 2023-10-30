#pragma once
#include <iostream>
#include <vector>

class DialogueBox {
private:
    int x, y;
    int width, height;
    //DXImage boxImage;
    std::vector<std::string> dialogueTexts;
    size_t currentTextIndex;

public:

    DialogueBox(int posX, int posY, int boxWidth, int boxHeight, const char* boxImagePath, int fontSize);

    void AddText(const std::string& text) ;

    void DisplayText();

    void SetPosition(int posX, int posY);

    void NextText();

    size_t GetDialogueTextsSize();
    size_t GetCurrentTextIndex();
};
