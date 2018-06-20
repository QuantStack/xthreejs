#include "xthreejs/loaders/xloader_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xloader>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xloader>;
    template xw::xmaterialize<xthree::xloader>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xloader>>;
    template class xw::xgenerator<xthree::xloader>;
    template xw::xgenerator<xthree::xloader>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xloader>>;
#endif
