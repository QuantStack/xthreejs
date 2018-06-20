#include "xthreejs/core/xlayers_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xlayers>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xlayers>;
    template xw::xmaterialize<xthree::xlayers>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xlayers>>;
    template class xw::xgenerator<xthree::xlayers>;
    template xw::xgenerator<xthree::xlayers>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xlayers>>;
#endif
