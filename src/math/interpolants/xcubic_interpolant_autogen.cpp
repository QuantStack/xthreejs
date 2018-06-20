#include "xthreejs/math/interpolants/xcubic_interpolant_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcubic_interpolant>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcubic_interpolant>;
    template xw::xmaterialize<xthree::xcubic_interpolant>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcubic_interpolant>>;
    template class xw::xgenerator<xthree::xcubic_interpolant>;
    template xw::xgenerator<xthree::xcubic_interpolant>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcubic_interpolant>>;
#endif
