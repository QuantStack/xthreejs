#include "xthreejs/textures/xvideo_texture_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xvideo_texture>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xvideo_texture>;
    template xw::xmaterialize<xthree::xvideo_texture>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xvideo_texture>>;
    template class xw::xgenerator<xthree::xvideo_texture>;
    template xw::xgenerator<xthree::xvideo_texture>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xvideo_texture>>;
#endif
