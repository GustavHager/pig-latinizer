#include "TranslatorGUI.hpp"

TranslatorGUI::TranslatorGUI() {
  activeTranslator = 0;
  isEvenColor = true;
}

void TranslatorGUI::setTranslator(Translator * translator) {
  activeTranslator = translator;
}

void TranslatorGUI::translateInput() {
  std::string text = editBox->getText();
  editBox->setText("");
  std::string translatedText = activeTranslator->translate(text);
  sf::Color textColor;
  if(isEvenColor) {
    textColor = sf::Color(230,230,230,255);
  } else {
    textColor = sf::Color(180,180,180,255);
  }
  chatbox->addLine(translatedText, textColor);
  isEvenColor = !isEvenColor;
}

void TranslatorGUI::TranslatorGUI::run() {
  AssertM(activeTranslator != 0, "No translator selected.");
  
  sf::RenderWindow window(sf::VideoMode(800, 600), "Translator");
  window.setFramerateLimit(60);

  tgui::Gui gui(window);

  try
    {
        tgui::Theme::Ptr theme = tgui::Theme::create("resources/translator_gui_theme.txt");

        tgui::Label::Ptr label = theme->load("label");
        label->setText("Translator - Input your words here and press <Enter> or \"Translate\".");
        label->setPosition(50, 20);
        label->setTextSize(20);
        gui.add(label);

        chatbox = theme->load("ChatBox");
        chatbox->setSize(700, 400);
        chatbox->setTextSize(18);
        chatbox->setPosition(50, 60);
        chatbox->setLinesStartFromTop();
        gui.add(chatbox);         

        editBox = theme->load("EditBox");
        editBox->setSize(595, 30);
        editBox->setTextSize(18);
        editBox->setPosition(50, 470);
        editBox->setDefaultText("Click to edit text...");
        editBox->connect("ReturnKeyPressed", [&](){ this->translateInput(); });
        gui.add(editBox);

        tgui::Button::Ptr button = theme->load("button");
        button->setPosition(650, 470);
        button->setText("Translate");
        button->setSize(100, 30);
        button->connect("pressed", [&](){ this->translateInput(); });
        gui.add(button);

        tgui::Label::Ptr label2 = theme->load("label");
        label2->setText(std::string("Active translator:  ")+activeTranslator->getName());
        label2->setPosition(50, 550);
        label2->setTextSize(20);
        gui.add(label2);

        button = theme->load("button");
        button->setPosition(window.getSize().x - 115.f, window.getSize().y - 50.f);
        button->setText("Exit");
        button->setSize(100, 30);
        button->connect("pressed", [&](){ window.close(); });
        gui.add(button);


    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "TGUI Exception: " << e.what() << std::endl;
        return;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event);
        }

        window.clear();
        gui.draw();
        window.display();
    }
    return;

}
