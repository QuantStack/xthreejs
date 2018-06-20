#include "xthreejs/loaders/xfont_loader_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xfont_loader>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xfont_loader>;
    template xw::xmaterialize<xthree::xfont_loader>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xfont_loader>>;
    template class xw::xgenerator<xthree::xfont_loader>;
    template xw::xgenerator<xthree::xfont_loader>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xfont_loader>>;
#endif
