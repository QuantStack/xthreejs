#include "xthreejs/math/xmath_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xmath>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xmath>;
    template xw::xmaterialize<xthree::xmath>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xmath>>;
    template class xw::xgenerator<xthree::xmath>;
    template xw::xgenerator<xthree::xmath>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xmath>>;
#endif
