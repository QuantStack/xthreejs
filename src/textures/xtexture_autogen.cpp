#include "xthreejs/textures/xtexture_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xtexture>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xtexture>;
    template xw::xmaterialize<xthree::xtexture>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xtexture>>;
    template class xw::xgenerator<xthree::xtexture>;
    template xw::xgenerator<xthree::xtexture>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xtexture>>;
#endif
