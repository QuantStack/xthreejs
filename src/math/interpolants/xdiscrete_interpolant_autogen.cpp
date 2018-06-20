#include "xthreejs/math/interpolants/xdiscrete_interpolant_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xdiscrete_interpolant>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xdiscrete_interpolant>;
    template xw::xmaterialize<xthree::xdiscrete_interpolant>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xdiscrete_interpolant>>;
    template class xw::xgenerator<xthree::xdiscrete_interpolant>;
    template xw::xgenerator<xthree::xdiscrete_interpolant>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xdiscrete_interpolant>>;
#endif
