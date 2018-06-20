#include "xthreejs/math/interpolants/xlinear_interpolant_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xlinear_interpolant>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xlinear_interpolant>;
    template xw::xmaterialize<xthree::xlinear_interpolant>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xlinear_interpolant>>;
    template class xw::xgenerator<xthree::xlinear_interpolant>;
    template xw::xgenerator<xthree::xlinear_interpolant>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xlinear_interpolant>>;
#endif
