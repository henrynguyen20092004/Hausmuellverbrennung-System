#ifndef SPECIFICATION_SECTION_HPP
#define SPECIFICATION_SECTION_HPP

#include <QVBoxLayout>

#include "../../../API/Specification/Specification.hpp"
#include "../../Components/Table/Table.hpp"
#include "../../Components/TextLabel/TextLabel.hpp"

class SpecificationSection : public QWidget {
   public:
    SpecificationSection();

   private:
    Specification specification;

    TextLabel *titleLabel;
    Table *table;
    QVBoxLayout *layout;
};

#endif
