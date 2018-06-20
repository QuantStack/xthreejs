#include "xthreejs/extras/curves/xspline_curve_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xspline_curve>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xspline_curve>;
    template xw::xmaterialize<xthree::xspline_curve>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xspline_curve>>;
    template class xw::xgenerator<xthree::xspline_curve>;
    template xw::xgenerator<xthree::xspline_curve>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xspline_curve>>;
#endif
