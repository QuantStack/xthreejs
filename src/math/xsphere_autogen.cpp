#include "xthreejs/math/xsphere_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xsphere>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xsphere>;
    template xw::xmaterialize<xthree::xsphere>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xsphere>>;
    template class xw::xgenerator<xthree::xsphere>;
    template xw::xgenerator<xthree::xsphere>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xsphere>>;
#endif
