#include "xthreejs/core/xuniform_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xuniform>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xuniform>;
    template xw::xmaterialize<xthree::xuniform>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xuniform>>;
    template class xw::xgenerator<xthree::xuniform>;
    template xw::xgenerator<xthree::xuniform>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xuniform>>;
#endif
