#pragma once

#include "UI/UIElement.h"
#include <vector>

namespace Cori {

inline std::vector<UIElement*> gMultiParentElements {};

inline bool deletionProtectionContains(UIElement* element) {
    return std::find(gMultiParentElements.begin(), gMultiParentElements.end(), element) != gMultiParentElements.end();
}

inline void cleanupMultiParentElements() {
    for(UIElement* element : gMultiParentElements) {
        delete element;
        element = NULL;
    }
}

}