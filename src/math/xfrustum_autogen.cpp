#include "xthreejs/math/xfrustum_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xfrustum>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xfrustum>;
    template xw::xmaterialize<xthree::xfrustum>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xfrustum>>;
    template class xw::xgenerator<xthree::xfrustum>;
    template xw::xgenerator<xthree::xfrustum>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xfrustum>>;
#endif
