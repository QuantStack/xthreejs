#include "xthreejs/objects/xline_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xline>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xline>;
    template xw::xmaterialize<xthree::xline>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xline>>;
    template class xw::xgenerator<xthree::xline>;
    template xw::xgenerator<xthree::xline>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xline>>;
#endif
