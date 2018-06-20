#include "xthreejs/animation/xanimation_utils_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xanimation_utils>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xanimation_utils>;
    template xw::xmaterialize<xthree::xanimation_utils>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xanimation_utils>>;
    template class xw::xgenerator<xthree::xanimation_utils>;
    template xw::xgenerator<xthree::xanimation_utils>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xanimation_utils>>;
#endif
