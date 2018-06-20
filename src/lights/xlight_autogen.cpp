#include "xthreejs/lights/xlight_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xlight>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xlight>;
    template xw::xmaterialize<xthree::xlight>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xlight>>;
    template class xw::xgenerator<xthree::xlight>;
    template xw::xgenerator<xthree::xlight>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xlight>>;
#endif
