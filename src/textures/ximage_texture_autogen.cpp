#include "xthreejs/textures/ximage_texture_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::ximage_texture>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::ximage_texture>;
    template xw::xmaterialize<xthree::ximage_texture>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::ximage_texture>>;
    template class xw::xgenerator<xthree::ximage_texture>;
    template xw::xgenerator<xthree::ximage_texture>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::ximage_texture>>;
#endif
