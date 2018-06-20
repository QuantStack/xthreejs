#include "xthreejs/geometries/xring_geometry_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xring_geometry>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xring_geometry>;
    template xw::xmaterialize<xthree::xring_geometry>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xring_geometry>>;
    template class xw::xgenerator<xthree::xring_geometry>;
    template xw::xgenerator<xthree::xring_geometry>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xring_geometry>>;
#endif
