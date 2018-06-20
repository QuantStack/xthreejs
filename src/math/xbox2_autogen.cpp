#include "xthreejs/math/xbox2_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xbox2>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xbox2>;
    template xw::xmaterialize<xthree::xbox2>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xbox2>>;
    template class xw::xgenerator<xthree::xbox2>;
    template xw::xgenerator<xthree::xbox2>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xbox2>>;
#endif
