#ifndef INTRODUCTION_SECTION_HPP
#define INTRODUCTION_SECTION_HPP

#include "../../Components/TextEdit/TextEdit.hpp"
#include "../../../API/Introduction/Introduction.hpp"

class IntroductionSection : public TextEdit {
   public:
    IntroductionSection();

   private:
    Introduction introduction;

    void insertIntroduction();
    void insertTitle();
    void insertImage();
    void insertFirstParagraph();
    void insertSecondParagraph();
    void insertThirdParagraph();
};

#endif
