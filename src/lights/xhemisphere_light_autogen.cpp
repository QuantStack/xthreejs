#include "xthreejs/lights/xhemisphere_light_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xhemisphere_light>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xhemisphere_light>;
    template xw::xmaterialize<xthree::xhemisphere_light>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xhemisphere_light>>;
    template class xw::xgenerator<xthree::xhemisphere_light>;
    template xw::xgenerator<xthree::xhemisphere_light>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xhemisphere_light>>;
#endif
