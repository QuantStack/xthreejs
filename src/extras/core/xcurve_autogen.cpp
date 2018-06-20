#include "xthreejs/extras/core/xcurve_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcurve>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcurve>;
    template xw::xmaterialize<xthree::xcurve>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcurve>>;
    template class xw::xgenerator<xthree::xcurve>;
    template xw::xgenerator<xthree::xcurve>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcurve>>;
#endif
