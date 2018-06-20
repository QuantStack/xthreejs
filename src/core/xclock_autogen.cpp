#include "xthreejs/core/xclock_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xclock>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xclock>;
    template xw::xmaterialize<xthree::xclock>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xclock>>;
    template class xw::xgenerator<xthree::xclock>;
    template xw::xgenerator<xthree::xclock>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xclock>>;
#endif
