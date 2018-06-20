#include "xthreejs/objects/xbone_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xbone>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xbone>;
    template xw::xmaterialize<xthree::xbone>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xbone>>;
    template class xw::xgenerator<xthree::xbone>;
    template xw::xgenerator<xthree::xbone>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xbone>>;
#endif
