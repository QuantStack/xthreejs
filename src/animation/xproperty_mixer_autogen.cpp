#include "xthreejs/animation/xproperty_mixer_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xproperty_mixer>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xproperty_mixer>;
    template xw::xmaterialize<xthree::xproperty_mixer>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xproperty_mixer>>;
    template class xw::xgenerator<xthree::xproperty_mixer>;
    template xw::xgenerator<xthree::xproperty_mixer>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xproperty_mixer>>;
#endif
