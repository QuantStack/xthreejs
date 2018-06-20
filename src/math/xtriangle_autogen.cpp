#include "xthreejs/math/xtriangle_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xtriangle>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xtriangle>;
    template xw::xmaterialize<xthree::xtriangle>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xtriangle>>;
    template class xw::xgenerator<xthree::xtriangle>;
    template xw::xgenerator<xthree::xtriangle>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xtriangle>>;
#endif
