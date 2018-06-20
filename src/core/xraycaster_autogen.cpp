#include "xthreejs/core/xraycaster_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xraycaster>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xraycaster>;
    template xw::xmaterialize<xthree::xraycaster>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xraycaster>>;
    template class xw::xgenerator<xthree::xraycaster>;
    template xw::xgenerator<xthree::xraycaster>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xraycaster>>;
#endif
