#include "xthreejs/extras/core/xfont_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xfont>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xfont>;
    template xw::xmaterialize<xthree::xfont>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xfont>>;
    template class xw::xgenerator<xthree::xfont>;
    template xw::xgenerator<xthree::xfont>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xfont>>;
#endif
