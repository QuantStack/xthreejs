#include "xthreejs/core/xbuffer_geometry_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xbuffer_geometry>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xbuffer_geometry>;
    template xw::xmaterialize<xthree::xbuffer_geometry>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xbuffer_geometry>>;
    template class xw::xgenerator<xthree::xbuffer_geometry>;
    template xw::xgenerator<xthree::xbuffer_geometry>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xbuffer_geometry>>;
#endif
