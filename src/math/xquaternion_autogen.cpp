#include "xthreejs/math/xquaternion_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xquaternion>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xquaternion>;
    template xw::xmaterialize<xthree::xquaternion>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xquaternion>>;
    template class xw::xgenerator<xthree::xquaternion>;
    template xw::xgenerator<xthree::xquaternion>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xquaternion>>;
#endif
