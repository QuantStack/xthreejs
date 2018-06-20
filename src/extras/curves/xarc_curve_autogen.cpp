#include "xthreejs/extras/curves/xarc_curve_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xarc_curve>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xarc_curve>;
    template xw::xmaterialize<xthree::xarc_curve>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xarc_curve>>;
    template class xw::xgenerator<xthree::xarc_curve>;
    template xw::xgenerator<xthree::xarc_curve>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xarc_curve>>;
#endif
