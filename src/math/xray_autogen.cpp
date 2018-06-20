#include "xthreejs/math/xray_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xray>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xray>;
    template xw::xmaterialize<xthree::xray>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xray>>;
    template class xw::xgenerator<xthree::xray>;
    template xw::xgenerator<xthree::xray>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xray>>;
#endif
