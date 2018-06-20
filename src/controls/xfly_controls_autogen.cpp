#include "xthreejs/controls/xfly_controls_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xfly_controls>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xfly_controls>;
    template xw::xmaterialize<xthree::xfly_controls>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xfly_controls>>;
    template class xw::xgenerator<xthree::xfly_controls>;
    template xw::xgenerator<xthree::xfly_controls>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xfly_controls>>;
#endif
