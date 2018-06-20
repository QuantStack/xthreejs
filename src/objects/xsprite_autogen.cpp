#include "xthreejs/objects/xsprite_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xsprite>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xsprite>;
    template xw::xmaterialize<xthree::xsprite>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xsprite>>;
    template class xw::xgenerator<xthree::xsprite>;
    template xw::xgenerator<xthree::xsprite>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xsprite>>;
#endif
