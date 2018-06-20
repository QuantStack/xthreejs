#include "xthreejs/extras/core/xshape_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xshape>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xshape>;
    template xw::xmaterialize<xthree::xshape>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xshape>>;
    template class xw::xgenerator<xthree::xshape>;
    template xw::xgenerator<xthree::xshape>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xshape>>;
#endif
