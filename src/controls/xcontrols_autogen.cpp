#include "xthreejs/controls/xcontrols_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcontrols>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcontrols>;
    template xw::xmaterialize<xthree::xcontrols>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcontrols>>;
    template class xw::xgenerator<xthree::xcontrols>;
    template xw::xgenerator<xthree::xcontrols>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcontrols>>;
#endif
