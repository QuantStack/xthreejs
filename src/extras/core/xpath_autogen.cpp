#include "xthreejs/extras/core/xpath_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xpath>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xpath>;
    template xw::xmaterialize<xthree::xpath>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xpath>>;
    template class xw::xgenerator<xthree::xpath>;
    template xw::xgenerator<xthree::xpath>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xpath>>;
#endif
