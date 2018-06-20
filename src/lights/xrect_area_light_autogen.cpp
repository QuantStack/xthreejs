#include "xthreejs/lights/xrect_area_light_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xrect_area_light>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xrect_area_light>;
    template xw::xmaterialize<xthree::xrect_area_light>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xrect_area_light>>;
    template class xw::xgenerator<xthree::xrect_area_light>;
    template xw::xgenerator<xthree::xrect_area_light>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xrect_area_light>>;
#endif
