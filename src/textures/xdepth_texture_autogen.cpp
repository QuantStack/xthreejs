#include "xthreejs/textures/xdepth_texture_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xdepth_texture>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xdepth_texture>;
    template xw::xmaterialize<xthree::xdepth_texture>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xdepth_texture>>;
    template class xw::xgenerator<xthree::xdepth_texture>;
    template xw::xgenerator<xthree::xdepth_texture>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xdepth_texture>>;
#endif
