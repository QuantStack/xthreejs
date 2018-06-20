#include "xthreejs/math/xinterpolant_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xinterpolant>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xinterpolant>;
    template xw::xmaterialize<xthree::xinterpolant>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xinterpolant>>;
    template class xw::xgenerator<xthree::xinterpolant>;
    template xw::xgenerator<xthree::xinterpolant>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xinterpolant>>;
#endif
