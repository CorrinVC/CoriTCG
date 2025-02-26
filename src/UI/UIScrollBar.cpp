#include "UIScrollBar.h"

namespace Cori {

UIScrollBar::UIScrollBar(float width, float height)
: UIScrollBar(0.0f, 0.0f, width, height)
{
    setPositionRelativeTo(ScreenTopRight);
}

UIScrollBar::UIScrollBar(float x, float y, float width, float height)
: UIElement(x, y, width, height)
{
    setBackgroundColor(sf::Color(120, 120, 120));
}

}