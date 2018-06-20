#include "xthreejs/animation/xanimation_clip_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xanimation_clip>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xanimation_clip>;
    template xw::xmaterialize<xthree::xanimation_clip>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xanimation_clip>>;
    template class xw::xgenerator<xthree::xanimation_clip>;
    template xw::xgenerator<xthree::xanimation_clip>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xanimation_clip>>;
#endif
