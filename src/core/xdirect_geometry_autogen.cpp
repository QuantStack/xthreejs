#include "xthreejs/core/xdirect_geometry_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xdirect_geometry>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xdirect_geometry>;
    template xw::xmaterialize<xthree::xdirect_geometry>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xdirect_geometry>>;
    template class xw::xgenerator<xthree::xdirect_geometry>;
    template xw::xgenerator<xthree::xdirect_geometry>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xdirect_geometry>>;
#endif
