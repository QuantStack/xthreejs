#include "xthreejs/objects/xgroup_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xgroup>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xgroup>;
    template xw::xmaterialize<xthree::xgroup>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xgroup>>;
    template class xw::xgenerator<xthree::xgroup>;
    template xw::xgenerator<xthree::xgroup>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xgroup>>;
#endif
