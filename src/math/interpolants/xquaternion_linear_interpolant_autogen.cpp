#include "xthreejs/math/interpolants/xquaternion_linear_interpolant_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xquaternion_linear_interpolant>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xquaternion_linear_interpolant>;
    template xw::xmaterialize<xthree::xquaternion_linear_interpolant>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xquaternion_linear_interpolant>>;
    template class xw::xgenerator<xthree::xquaternion_linear_interpolant>;
    template xw::xgenerator<xthree::xquaternion_linear_interpolant>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xquaternion_linear_interpolant>>;
#endif
