#include "QuantityCard.h"

namespace Cori {

bool operator==(QuantityCard left, QuantityCard right) {
    return {
        left.expansion() == right.expansion()
        && left.cardNumber() == right.cardNumber()
    };
}

}