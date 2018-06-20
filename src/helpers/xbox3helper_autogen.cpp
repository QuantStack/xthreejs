#include "xthreejs/helpers/xbox3helper_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xbox3helper>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xbox3helper>;
    template xw::xmaterialize<xthree::xbox3helper>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xbox3helper>>;
    template class xw::xgenerator<xthree::xbox3helper>;
    template xw::xgenerator<xthree::xbox3helper>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xbox3helper>>;
#endif
