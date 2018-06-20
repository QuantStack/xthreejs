#include "xthreejs/objects/xpoints_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xpoints>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xpoints>;
    template xw::xmaterialize<xthree::xpoints>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xpoints>>;
    template class xw::xgenerator<xthree::xpoints>;
    template xw::xgenerator<xthree::xpoints>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xpoints>>;
#endif
