#include "xthreejs/objects/xblackbox_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xblackbox>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xblackbox>;
    template xw::xmaterialize<xthree::xblackbox>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xblackbox>>;
    template class xw::xgenerator<xthree::xblackbox>;
    template xw::xgenerator<xthree::xblackbox>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xblackbox>>;
#endif
