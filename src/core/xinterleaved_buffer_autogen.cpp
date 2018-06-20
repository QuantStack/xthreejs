#include "xthreejs/core/xinterleaved_buffer_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xinterleaved_buffer>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xinterleaved_buffer>;
    template xw::xmaterialize<xthree::xinterleaved_buffer>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xinterleaved_buffer>>;
    template class xw::xgenerator<xthree::xinterleaved_buffer>;
    template xw::xgenerator<xthree::xinterleaved_buffer>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xinterleaved_buffer>>;
#endif
