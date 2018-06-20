#include "xthreejs/animation/xproperty_binding_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xproperty_binding>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xproperty_binding>;
    template xw::xmaterialize<xthree::xproperty_binding>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xproperty_binding>>;
    template class xw::xgenerator<xthree::xproperty_binding>;
    template xw::xgenerator<xthree::xproperty_binding>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xproperty_binding>>;
#endif
