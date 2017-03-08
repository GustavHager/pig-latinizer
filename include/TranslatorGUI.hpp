#ifndef TRANSLATOR_GUI_HPP
#define TRANSLATOR_GUI_HPP

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include "Translator.hpp"
#include "InformativeAssert.hpp"

class TranslatorGUI {
  public:
    TranslatorGUI();
    void setTranslator(Translator * translator);
    void run();
  private:
    Translator * activeTranslator;
    tgui::EditBox::Ptr editBox;
    tgui::ChatBox::Ptr chatbox;
    bool isEvenColor;

    void translateInput();

};

#endif
