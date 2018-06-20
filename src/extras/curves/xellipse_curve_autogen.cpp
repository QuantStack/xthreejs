#include "xthreejs/extras/curves/xellipse_curve_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xellipse_curve>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xellipse_curve>;
    template xw::xmaterialize<xthree::xellipse_curve>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xellipse_curve>>;
    template class xw::xgenerator<xthree::xellipse_curve>;
    template xw::xgenerator<xthree::xellipse_curve>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xellipse_curve>>;
#endif
