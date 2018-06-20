#include "xthreejs/loaders/xmaterial_loader_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xmaterial_loader>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xmaterial_loader>;
    template xw::xmaterialize<xthree::xmaterial_loader>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xmaterial_loader>>;
    template class xw::xgenerator<xthree::xmaterial_loader>;
    template xw::xgenerator<xthree::xmaterial_loader>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xmaterial_loader>>;
#endif
