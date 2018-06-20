#include "xthreejs/textures/xtext_texture_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xtext_texture>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xtext_texture>;
    template xw::xmaterialize<xthree::xtext_texture>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xtext_texture>>;
    template class xw::xgenerator<xthree::xtext_texture>;
    template xw::xgenerator<xthree::xtext_texture>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xtext_texture>>;
#endif
