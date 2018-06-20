#include "xthreejs/loaders/xcache_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcache>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcache>;
    template xw::xmaterialize<xthree::xcache>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcache>>;
    template class xw::xgenerator<xthree::xcache>;
    template xw::xgenerator<xthree::xcache>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcache>>;
#endif
