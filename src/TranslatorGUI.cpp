#include "TranslatorGUI.hpp"

TranslatorGUI::TranslatorGUI() {
  activeTranslator = 0;
}

void TranslatorGUI::setTranslator(Translator * translator) {
  activeTranslator = translator;
}

void TranslatorGUI::TranslatorGUI::run() {
  AssertM(activeTranslator != 0, "No translator selected.");
  
  sf::RenderWindow window(sf::VideoMode(800, 600), "Translator");
  window.setFramerateLimit(60);

  tgui::Gui gui(window);

  try
    {
        tgui::Theme::Ptr theme = tgui::Theme::create("../translator_gui_theme.txt");

        tgui::Label::Ptr label = theme->load("label");
        label->setText("Translator - Input your text here and press enter:");
        label->setPosition(50, 10);
        label->setTextSize(18);
        gui.add(label);

        tgui::ChatBox::Ptr chatbox = theme->load("ChatBox");
        chatbox->setSize(600, 400);
        chatbox->setTextSize(18);
        chatbox->setPosition(50, 40);
        chatbox->setLinesStartFromTop();
        chatbox->addLine("texus : Hey, this is TGUI!", sf::Color::Green);
        chatbox->addLine("Me : Looks awesome! ;)", sf::Color::Yellow);
        chatbox->addLine("texus : Thanks! :)", sf::Color::Green);
        chatbox->addLine("Me : The widgets rock ^^", sf::Color::Yellow);
        gui.add(chatbox);         

        tgui::EditBox::Ptr editBox = theme->load("EditBox");
        editBox->setSize(600, 30);
        editBox->setTextSize(18);
        editBox->setPosition(50, 450);
        editBox->setDefaultText("Click to edit text...");
        gui.add(editBox);

        tgui::Button::Ptr button = theme->load("button");
        button->setPosition(window.getSize().x - 115.f, window.getSize().y - 50.f);
        button->setText("Exit");
        button->setSize(100, 40);
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
