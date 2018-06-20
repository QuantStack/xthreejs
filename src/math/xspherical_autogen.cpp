#include "xthreejs/math/xspherical_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xspherical>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xspherical>;
    template xw::xmaterialize<xthree::xspherical>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xspherical>>;
    template class xw::xgenerator<xthree::xspherical>;
    template xw::xgenerator<xthree::xspherical>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xspherical>>;
#endif
