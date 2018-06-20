#include "xthreejs/lights/xambient_light_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xambient_light>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xambient_light>;
    template xw::xmaterialize<xthree::xambient_light>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xambient_light>>;
    template class xw::xgenerator<xthree::xambient_light>;
    template xw::xgenerator<xthree::xambient_light>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xambient_light>>;
#endif
