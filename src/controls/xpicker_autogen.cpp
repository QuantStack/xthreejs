#include "xthreejs/controls/xpicker_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xpicker>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xpicker>;
    template xw::xmaterialize<xthree::xpicker>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xpicker>>;
    template class xw::xgenerator<xthree::xpicker>;
    template xw::xgenerator<xthree::xpicker>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xpicker>>;
#endif
