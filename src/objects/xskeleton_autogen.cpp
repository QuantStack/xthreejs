#include "xthreejs/objects/xskeleton_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xskeleton>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xskeleton>;
    template xw::xmaterialize<xthree::xskeleton>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xskeleton>>;
    template class xw::xgenerator<xthree::xskeleton>;
    template xw::xgenerator<xthree::xskeleton>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xskeleton>>;
#endif
