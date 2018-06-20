#include "xthreejs/lights/xpoint_light_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xpoint_light>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xpoint_light>;
    template xw::xmaterialize<xthree::xpoint_light>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xpoint_light>>;
    template class xw::xgenerator<xthree::xpoint_light>;
    template xw::xgenerator<xthree::xpoint_light>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xpoint_light>>;
#endif
