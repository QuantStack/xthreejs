#include "xthreejs/math/xcylindrical_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcylindrical>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcylindrical>;
    template xw::xmaterialize<xthree::xcylindrical>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcylindrical>>;
    template class xw::xgenerator<xthree::xcylindrical>;
    template xw::xgenerator<xthree::xcylindrical>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcylindrical>>;
#endif
