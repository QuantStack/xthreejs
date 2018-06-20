#include "xthreejs/core/xgeometry_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xgeometry>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xgeometry>;
    template xw::xmaterialize<xthree::xgeometry>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xgeometry>>;
    template class xw::xgenerator<xthree::xgeometry>;
    template xw::xgenerator<xthree::xgeometry>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xgeometry>>;
#endif
