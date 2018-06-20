#include "xthreejs/scenes/xfog_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xfog>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xfog>;
    template xw::xmaterialize<xthree::xfog>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xfog>>;
    template class xw::xgenerator<xthree::xfog>;
    template xw::xgenerator<xthree::xfog>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xfog>>;
#endif
